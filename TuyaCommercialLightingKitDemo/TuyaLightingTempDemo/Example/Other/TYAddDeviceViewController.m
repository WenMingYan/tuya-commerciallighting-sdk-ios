//
//  TYAddDeviceViewController.m
//  TuyaLightingTempDemo
//
//  Created by 凌晨 on 2021/9/27.
//

#import "TYAddDeviceViewController.h"
#import <TuyaSmartBizCore/TuyaSmartBizCore.h>
#import <TYModuleServices/TYModuleServices.h>
#import <TuyaSmartCommercialLightingSdk/TuyaSmartCommercialLightingSdk.h>
#import <SVProgressHUD/SVProgressHUD.h>

@interface TYAddDeviceViewController ()

@end

@implementation TYAddDeviceViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (IBAction)addDeviceAction:(id)sender {
    id<TYActivatorProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYActivatorProtocol)];
    [impl gotoCategoryViewController];
          
    // 获取配网结果
    [impl activatorCompletion:TYActivatorCompletionNodeNormal customJump:NO completionBlock:^(NSArray * _Nullable deviceList) {
        
        [self.navigationController popToViewController:self animated:NO];
        
        NSLog(@"deviceList: %@",deviceList);
        
        UIAlertController *sheet = [UIAlertController alertControllerWithTitle:@"choose area" message:@"please choose area to transfer devices" preferredStyle:UIAlertControllerStyleActionSheet];
        
        id<TYLampProjectDataProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYLampProjectDataProtocol)];
        TuyaLightingProject *currentProject = [impl getCurrentProject];
        [currentProject.firstLevelAreas enumerateObjectsUsingBlock:^(TuyaLightingAreaModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            UIAlertAction *action = [UIAlertAction actionWithTitle:obj.name style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                
                [self transferDevicesWithAreaId:obj.areaId devIds:deviceList];
                
            }];
            [sheet addAction:action];
        }];
        
        [self presentViewController:sheet animated:YES completion:^{
                        
        }];
    }];
}



- (void)transferDevicesWithAreaId:(long long)areaId devIds:(NSArray<NSString *> *)devIds {
    [SVProgressHUD show];
    id<TYLampProjectDataProtocol> impl = [[TuyaSmartBizCore sharedInstance] serviceOfProtocol:@protocol(TYLampProjectDataProtocol)];
    TuyaLightingArea *area = [TuyaLightingArea areaWithAreaId:areaId projectId:impl.currentProjectId];
    __weak __typeof(self) weakSelf = self;
    [area transferDevicesWithDeviceIds:devIds success:^(NSArray<NSString *> * _Nonnull successDevIds, NSArray<NSString *> * _Nonnull failedDevIds) {
        __strong __typeof(weakSelf) strongSelf = weakSelf;
        [strongSelf.navigationController popViewControllerAnimated:YES];
        [SVProgressHUD dismiss];
    } failure:^(NSError *error) {
        [SVProgressHUD dismiss];
    }];
}

@end
