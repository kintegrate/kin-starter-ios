/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/extensions/filters/http/router/v3/router.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#if COCOAPODS==1
  #include  "third_party/upb/upb/def.h"
#else
  #include  "upb/def.h"
#endif
#if COCOAPODS==1
  #include  "src/core/ext/upbdefs-generated/envoy/extensions/filters/http/router/v3/router.upbdefs.h"
#else
  #include  "envoy/extensions/filters/http/router/v3/router.upbdefs.h"
#endif

extern upb_def_init envoy_config_accesslog_v3_accesslog_proto_upbdefinit;
extern upb_def_init google_protobuf_wrappers_proto_upbdefinit;
extern upb_def_init udpa_annotations_status_proto_upbdefinit;
extern upb_def_init udpa_annotations_versioning_proto_upbdefinit;
extern upb_def_init validate_validate_proto_upbdefinit;
extern const upb_msglayout envoy_extensions_filters_http_router_v3_Router_msginit;

static const upb_msglayout *layouts[1] = {
  &envoy_extensions_filters_http_router_v3_Router_msginit,
};

static const char descriptor[996] = {'\n', '4', 'e', 'n', 'v', 'o', 'y', '/', 'e', 'x', 't', 'e', 'n', 's', 'i', 'o', 'n', 's', '/', 'f', 'i', 'l', 't', 'e', 'r', 
's', '/', 'h', 't', 't', 'p', '/', 'r', 'o', 'u', 't', 'e', 'r', '/', 'v', '3', '/', 'r', 'o', 'u', 't', 'e', 'r', '.', 'p', 
'r', 'o', 't', 'o', '\022', '\'', 'e', 'n', 'v', 'o', 'y', '.', 'e', 'x', 't', 'e', 'n', 's', 'i', 'o', 'n', 's', '.', 'f', 'i', 
'l', 't', 'e', 'r', 's', '.', 'h', 't', 't', 'p', '.', 'r', 'o', 'u', 't', 'e', 'r', '.', 'v', '3', '\032', ')', 'e', 'n', 'v', 
'o', 'y', '/', 'c', 'o', 'n', 'f', 'i', 'g', '/', 'a', 'c', 'c', 'e', 's', 's', 'l', 'o', 'g', '/', 'v', '3', '/', 'a', 'c', 
'c', 'e', 's', 's', 'l', 'o', 'g', '.', 'p', 'r', 'o', 't', 'o', '\032', '\036', 'g', 'o', 'o', 'g', 'l', 'e', '/', 'p', 'r', 'o', 
't', 'o', 'b', 'u', 'f', '/', 'w', 'r', 'a', 'p', 'p', 'e', 'r', 's', '.', 'p', 'r', 'o', 't', 'o', '\032', '\035', 'u', 'd', 'p', 
'a', '/', 'a', 'n', 'n', 'o', 't', 'a', 't', 'i', 'o', 'n', 's', '/', 's', 't', 'a', 't', 'u', 's', '.', 'p', 'r', 'o', 't', 
'o', '\032', '!', 'u', 'd', 'p', 'a', '/', 'a', 'n', 'n', 'o', 't', 'a', 't', 'i', 'o', 'n', 's', '/', 'v', 'e', 'r', 's', 'i', 
'o', 'n', 'i', 'n', 'g', '.', 'p', 'r', 'o', 't', 'o', '\032', '\027', 'v', 'a', 'l', 'i', 'd', 'a', 't', 'e', '/', 'v', 'a', 'l', 
'i', 'd', 'a', 't', 'e', '.', 'p', 'r', 'o', 't', 'o', '\"', '\204', '\005', '\n', '\006', 'R', 'o', 'u', 't', 'e', 'r', '\022', '?', '\n', 
'\r', 'd', 'y', 'n', 'a', 'm', 'i', 'c', '_', 's', 't', 'a', 't', 's', '\030', '\001', ' ', '\001', '(', '\013', '2', '\032', '.', 'g', 'o', 
'o', 'g', 'l', 'e', '.', 'p', 'r', 'o', 't', 'o', 'b', 'u', 'f', '.', 'B', 'o', 'o', 'l', 'V', 'a', 'l', 'u', 'e', 'R', '\014', 
'd', 'y', 'n', 'a', 'm', 'i', 'c', 'S', 't', 'a', 't', 's', '\022', '(', '\n', '\020', 's', 't', 'a', 'r', 't', '_', 'c', 'h', 'i', 
'l', 'd', '_', 's', 'p', 'a', 'n', '\030', '\002', ' ', '\001', '(', '\010', 'R', '\016', 's', 't', 'a', 'r', 't', 'C', 'h', 'i', 'l', 'd', 
'S', 'p', 'a', 'n', '\022', 'G', '\n', '\014', 'u', 'p', 's', 't', 'r', 'e', 'a', 'm', '_', 'l', 'o', 'g', '\030', '\003', ' ', '\003', '(', 
'\013', '2', '$', '.', 'e', 'n', 'v', 'o', 'y', '.', 'c', 'o', 'n', 'f', 'i', 'g', '.', 'a', 'c', 'c', 'e', 's', 's', 'l', 'o', 
'g', '.', 'v', '3', '.', 'A', 'c', 'c', 'e', 's', 's', 'L', 'o', 'g', 'R', '\013', 'u', 'p', 's', 't', 'r', 'e', 'a', 'm', 'L', 
'o', 'g', '\022', '4', '\n', '\026', 's', 'u', 'p', 'p', 'r', 'e', 's', 's', '_', 'e', 'n', 'v', 'o', 'y', '_', 'h', 'e', 'a', 'd', 
'e', 'r', 's', '\030', '\004', ' ', '\001', '(', '\010', 'R', '\024', 's', 'u', 'p', 'p', 'r', 'e', 's', 's', 'E', 'n', 'v', 'o', 'y', 'H', 
'e', 'a', 'd', 'e', 'r', 's', '\022', '\307', '\001', '\n', '\024', 's', 't', 'r', 'i', 'c', 't', '_', 'c', 'h', 'e', 'c', 'k', '_', 'h', 
'e', 'a', 'd', 'e', 'r', 's', '\030', '\005', ' ', '\003', '(', '\t', 'B', '\224', '\001', '\372', 'B', '\220', '\001', '\222', '\001', '\214', '\001', '\"', '\211', 
'\001', 'r', '\206', '\001', 'R', '\036', 'x', '-', 'e', 'n', 'v', 'o', 'y', '-', 'u', 'p', 's', 't', 'r', 'e', 'a', 'm', '-', 'r', 'q', 
'-', 't', 'i', 'm', 'e', 'o', 'u', 't', '-', 'm', 's', 'R', '&', 'x', '-', 'e', 'n', 'v', 'o', 'y', '-', 'u', 'p', 's', 't', 
'r', 'e', 'a', 'm', '-', 'r', 'q', '-', 'p', 'e', 'r', '-', 't', 'r', 'y', '-', 't', 'i', 'm', 'e', 'o', 'u', 't', '-', 'm', 
's', 'R', '\023', 'x', '-', 'e', 'n', 'v', 'o', 'y', '-', 'm', 'a', 'x', '-', 'r', 'e', 't', 'r', 'i', 'e', 's', 'R', '\025', 'x', 
'-', 'e', 'n', 'v', 'o', 'y', '-', 'r', 'e', 't', 'r', 'y', '-', 'g', 'r', 'p', 'c', '-', 'o', 'n', 'R', '\020', 'x', '-', 'e', 
'n', 'v', 'o', 'y', '-', 'r', 'e', 't', 'r', 'y', '-', 'o', 'n', 'R', '\022', 's', 't', 'r', 'i', 'c', 't', 'C', 'h', 'e', 'c', 
'k', 'H', 'e', 'a', 'd', 'e', 'r', 's', '\022', '=', '\n', '\033', 'r', 'e', 's', 'p', 'e', 'c', 't', '_', 'e', 'x', 'p', 'e', 'c', 
't', 'e', 'd', '_', 'r', 'q', '_', 't', 'i', 'm', 'e', 'o', 'u', 't', '\030', '\006', ' ', '\001', '(', '\010', 'R', '\030', 'r', 'e', 's', 
'p', 'e', 'c', 't', 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'R', 'q', 'T', 'i', 'm', 'e', 'o', 'u', 't', '\022', 'U', '\n', '(', 
's', 'u', 'p', 'p', 'r', 'e', 's', 's', '_', 'g', 'r', 'p', 'c', '_', 'r', 'e', 'q', 'u', 'e', 's', 't', '_', 'f', 'a', 'i', 
'l', 'u', 'r', 'e', '_', 'c', 'o', 'd', 'e', '_', 's', 't', 'a', 't', 's', '\030', '\007', ' ', '\001', '(', '\010', 'R', '#', 's', 'u', 
'p', 'p', 'r', 'e', 's', 's', 'G', 'r', 'p', 'c', 'R', 'e', 'q', 'u', 'e', 's', 't', 'F', 'a', 'i', 'l', 'u', 'r', 'e', 'C', 
'o', 'd', 'e', 'S', 't', 'a', 't', 's', ':', '0', '\232', '\305', '\210', '\036', '+', '\n', ')', 'e', 'n', 'v', 'o', 'y', '.', 'c', 'o', 
'n', 'f', 'i', 'g', '.', 'f', 'i', 'l', 't', 'e', 'r', '.', 'h', 't', 't', 'p', '.', 'r', 'o', 'u', 't', 'e', 'r', '.', 'v', 
'2', '.', 'R', 'o', 'u', 't', 'e', 'r', 'B', 'N', '\n', '5', 'i', 'o', '.', 'e', 'n', 'v', 'o', 'y', 'p', 'r', 'o', 'x', 'y', 
'.', 'e', 'n', 'v', 'o', 'y', '.', 'e', 'x', 't', 'e', 'n', 's', 'i', 'o', 'n', 's', '.', 'f', 'i', 'l', 't', 'e', 'r', 's', 
'.', 'h', 't', 't', 'p', '.', 'r', 'o', 'u', 't', 'e', 'r', '.', 'v', '3', 'B', '\013', 'R', 'o', 'u', 't', 'e', 'r', 'P', 'r', 
'o', 't', 'o', 'P', '\001', '\272', '\200', '\310', '\321', '\006', '\002', '\020', '\002', 'b', '\006', 'p', 'r', 'o', 't', 'o', '3', 
};

static upb_def_init *deps[6] = {
  &envoy_config_accesslog_v3_accesslog_proto_upbdefinit,
  &google_protobuf_wrappers_proto_upbdefinit,
  &udpa_annotations_status_proto_upbdefinit,
  &udpa_annotations_versioning_proto_upbdefinit,
  &validate_validate_proto_upbdefinit,
  NULL
};

upb_def_init envoy_extensions_filters_http_router_v3_router_proto_upbdefinit = {
  deps,
  layouts,
  "envoy/extensions/filters/http/router/v3/router.proto",
  UPB_STRVIEW_INIT(descriptor, 996)
};
