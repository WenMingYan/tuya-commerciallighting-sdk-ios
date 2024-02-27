//
//  TYCacheManager.m
//  TuyaLightingTempDemo
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/) 
//

#import "TYCacheManager.h"
#import <TuyaSmartBizCore/TuyaSmartBizCore.h>
#import <TYModuleServices/TYModuleServices.h>
#import <TuyaCommercialLightingKit/TuyaCommercialLightingKit.h>

@interface TYCacheManager ()<TYLampProjectDataProtocol>

@end

@implementation TYCacheManager


+ (TYCacheManager *)sharedInstance {
    static TYCacheManager *_sharedInstance=nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedInstance = [[self alloc] init];
        [_sharedInstance initCurrentProject];
    });
    return _sharedInstance;
}

- (void)initCurrentProject {
    // 注册要实现的协议
    [[TuyaSmartBizCore sharedInstance] registerService:@protocol(TYLampProjectDataProtocol) withInstance:self];
}


- (void)clearCurrentProject {
//    [self.groupUserdefault removeObjectForKey:kCurrentHomeIdKey];
//    [self.groupUserdefault synchronize];
}

- (TuyaLightingProject *)getCurrentProject {
    long long projectId = self.projectId;
    TuyaLightingProject *project = [TuyaLightingProject projectWithProjectId:projectId];
    return project;
}

- (void)updateCurrentProjectId:(long long)projectId {
//    if (projectId > 0) {
//        [self.groupUserdefault setObject:@(projectId) forKey:kCurrentHomeIdKey];
//        [self.groupUserdefault synchronize];
//    }
}

- (long long)currentProjectId {
//    long long projectId = [[self.groupUserdefault objectForKey:kCurrentHomeIdKey] longLongValue];
    return self.projectId;
}

- (void)setProjectId:(long long)projectId {
    _projectId = projectId;
    [self updateCurrentProjectId:projectId];
}

@end
