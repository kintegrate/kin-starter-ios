//
//  AppDelegate.swift
//  kin-starter-ios
//
//  Created by Richard Reitzfeld on 5/16/21.
//  Copyright © 2021 Richard Reitzfeld. All rights reserved.
//

import UIKit
import KinBase

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    private enum Constants {
        
        static let exampleAppAddress: String = "GAYSJAFQ4WHU6OOGPNF3MULUMXHFBHTKN4M7O466VDGCY4GR5CV4LL6Q"
        static let exampleAppIndex: Int = 165
        static let credentialUser = "MyUser"
        static let credentialPassword = "MyPass"
        static let exampleSendAddress: String = "GA6CCT5IB4DJBR63BM3BQ7WB3M2UZ6QG6Z5XB64GSIABH6ICIETTAVU2"
        static let minAPIVersion: Int = 4
    }
    
    // MARK: - Public Properties

    var window: UIWindow?

    // MARK: - Lifecycle
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        let viewController = ViewController()
        
        window = UIWindow(frame: UIScreen.main.bounds)
        window?.rootViewController = viewController
        window?.makeKeyAndVisible()
        
        return true
    }
}
