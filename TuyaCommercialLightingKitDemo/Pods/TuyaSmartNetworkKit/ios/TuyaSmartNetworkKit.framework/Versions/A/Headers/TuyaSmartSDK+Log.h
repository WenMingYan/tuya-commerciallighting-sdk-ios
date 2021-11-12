//
// TuyaSmartSDK+Log.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartSDK_Log_h
#define TuyaSmartSDK_Log_h

#import "TuyaSmartSDK.h"

NS_ASSUME_NONNULL_BEGIN


void TYSDKLog(NSInteger level, NSString *module, const char *file, const char *function, NSUInteger line, NSString *format, ...);

#undef TYLog
#undef TYSDKLogDebug
#undef TYSDKLogInfo
#undef TYSDKLogWarn
#undef TYSDKLogError

#define TYLog(...) \
    TYSDKLog(1, @"TuyaSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define TYSDKLogDebug(...) \
    TYSDKLog(0, @"TuyaSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define TYSDKLogInfo(...) \
    TYSDKLog(1, @"TuyaSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define TYSDKLogWarn(...) \
    TYSDKLog(2, @"TuyaSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define TYSDKLogError(...) \
    TYSDKLog(3, @"TuyaSmartHomeKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

@interface TuyaSmartSDK (Log)

/// Debug mode, default is false. Verbose log will print into console if opened.
@property (nonatomic, assign) BOOL debugMode;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartSDK_Log_h */
