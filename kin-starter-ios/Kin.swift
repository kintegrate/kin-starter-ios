//
//  Kin.swift
//  kin-starter-ios
//
//  Created by Richard Reitzfeld on 5/16/21.
//  Copyright © 2021 Richard Reitzfeld. All rights reserved.
//

import Foundation
import KinBase
import Promises

class Kin {
    
    private enum Constants {

        static let minAPIVersion: Int = 4
        static let paymentSpacerWindow: TimeInterval = 60.0
    }

    typealias KinBalanceBlock = (KinBalance) -> ()
    typealias KinPaymentBlock = ([KinPayment]) -> ()
        
    // MARK: - Private Properties
    
    private let isProduction: Bool
    private let appIndex: Int
    private let appAddress: String
    private let credentialUser: String
    private let credentialPassword: String
    private let onBalanceChanged: KinBalanceBlock?
    private let onPaymentHappened: KinPaymentBlock?
    private var kinAccountContext: KinAccountContext? = nil {
        didSet {
            setupListeners()
        }
    }
    private var disposeBag = DisposeBag()
    private var lastPaymentDate: Date?
    
    private lazy var kinEnvironment: KinEnvironment = {
        if isProduction {
            return KinEnvironment.Agora.mainNet(
                appInfoProvider: self,
                minApiVersion: Constants.minAPIVersion
            )
        } else {
            return KinEnvironment.Agora.testNet(
                minApiVersion: Constants.minAPIVersion
            )
        }
    }()
    
    // MARK: - Lifecycle
    
    init(isProduction: Bool,
         appIndex: Int,
         appAddress: String,
         credentialUser: String,
         credentialPassword: String,
         onBalanceChanged: KinBalanceBlock?,
         onPaymentHappened: KinPaymentBlock?) {
        self.isProduction = isProduction
        self.appIndex = appIndex
        self.appAddress = appAddress
        self.credentialUser = credentialUser
        self.credentialPassword = credentialPassword
        self.onBalanceChanged = onBalanceChanged
        self.onPaymentHappened = onPaymentHappened
        getContext()
    }
    
    // MARK: - Observation
    
    private func setupListeners() {
        watchBalance()
        watchPayments()
    }
    
    private func watchBalance() {
        guard let context = kinAccountContext else {
            assertionFailure("Should have a KinAccountContext")
            return
        }
        context
            .observeBalance()
            .subscribe({[weak self] balance in
                self?.onBalanceChanged?(balance)
            })
            .disposedBy(disposeBag)
    }
    
    private func watchPayments() {
        guard let context = kinAccountContext else {
            assertionFailure("Should have a KinAccountContext")
            return
        }
        context
            .observePayments()
            .subscribe({[weak self] payments in
                self?.onPaymentHappened?(payments)
            })
            .disposedBy(disposeBag)
    }
    
    // MARK: - Account Info
    
    func address() -> String? {
        return kinAccountContext?.accountId
    }

    func checkBalance(completion: @escaping (Result<KinBalance, Error>) -> ()) {
        kinAccountContext?.getAccount(
            forceUpdate: true
        ).then({ account in
            completion(.success(account.balance))
        }).catch({ (error) in
            completion(.failure(error))
        })
    }
    
    // MARK: - Context
    
    private func getContext() {
        kinEnvironment
            .allAccountIds()
            .then { [weak self] ids in
                let accountId = ids.first ?? self?.createAccount()

                guard let id = accountId else {
                    throw KinError.couldNotGetIdForContext
                }
                
                self?.kinAccountContext = self?.getContext(for: id)
        }.catch { error in
            assertionFailure("Error getting context: \(error)")
        }
    }
    
    private func createAccount() -> KinAccount.Id? {
        return try? KinAccountContext
            .Builder(env: kinEnvironment)
            .createNewAccount()
            .build()
            .accountId
    }
    
    private func getContext(for accountId: KinAccount.Id) -> KinAccountContext {
        return KinAccountContext
            .Builder(env: kinEnvironment)
            .useExistingAccount(accountId)
            .build()
    }
    
    // MARK: - Payments
    
    func sendKin(payments: [KinPaymentInfo],
                 address: String,
                 paymentType: KinBinaryMemo.TransferType,
                 completion: @escaping (Result<KinPayment, Error>) -> ()) {
        
        guard paymentTimeFrameIsValid() else {
            completion(.failure(KinError.tooManyTransactions))
            return
        }
        
        guard let invoice = try? buildInvoice(payments: payments) else {
            completion(.failure(KinError.couldNotCreateInvoice))
            return
        }
        
        guard let memo = try? buildMemo(invoice: invoice, transferType: paymentType) else {
            completion(.failure(KinError.couldNotCreateMemo))
            return
        }
        
        let amount = invoiceTotal(payments: payments)

        kinAccountContext?.sendKinPayment(
            KinPaymentItem(
                amount: amount,
                destAccountId: address,
                invoice: invoice
            ),
            memo: memo
        ).then(
            on: .main,
            {[weak self]  payment in
                self?.lastPaymentDate = Date()
                completion(.success(payment))
            }
        ).catch(
            on: .main,
            { error in
                completion(.failure(error))
            }
        )
        
    }
    
    private func paymentTimeFrameIsValid() -> Bool {
        guard let lastTransactionDate = lastPaymentDate else {
            return true
        }
        
        return Date().timeIntervalSince(lastTransactionDate) > Constants.paymentSpacerWindow
    }
    
    private func buildInvoice(payments: [KinPaymentInfo]) throws -> Invoice {
        let lineItems = try payments.map { payment in
            return try LineItem(
                title: payment.title,
                amount: Decimal(payment.amount)
            )
        }
        return try Invoice(lineItems: lineItems)
    }
    
    private func invoiceTotal(payments: [KinPaymentInfo]) -> Decimal {
        return payments.map { Decimal($0.amount) }.reduce(0, +)
    }
    
    private func buildMemo(invoice: Invoice,
                           transferType: KinBinaryMemo.TransferType) throws -> KinMemo {
        let invoiceList = try InvoiceList(invoices: [invoice])

        let memo = try KinBinaryMemo(
            typeId: transferType.rawValue,
            appIdx: appInfo.appIdx.value,
            foreignKeyBytes: invoiceList.id.decode()
        )
        return memo.kinMemo
    }
}

// MARK: - AppInfoProvider

extension Kin: AppInfoProvider {
    
    var appInfo: AppInfo {
        return AppInfo(
            appIdx: AppIndex(value: UInt16(appIndex)),
            kinAccountId: appAddress,
            name: "kin-ios-example",
            appIconData: Data()
        )
    }
    
    func getPassthroughAppUserCredentials() -> AppUserCredentials {
        return AppUserCredentials(
            appUserId: credentialUser,
            appUserPasskey: credentialPassword
        )
    }
}

extension Kin {
    
    enum KinError: Error {
        
        case tooManyTransactions
        case couldNotGetIdForContext
        case couldNotCreateInvoice
        case couldNotCreateMemo
    }
    
    struct KinPaymentInfo {
        
        let amount: Double
        let title: String
    }
}
