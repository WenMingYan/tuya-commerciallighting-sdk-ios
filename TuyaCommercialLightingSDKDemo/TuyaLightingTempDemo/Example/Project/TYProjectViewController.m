//
//  TYProjectViewController.m
//  TuyaLightingTempDemo
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/) 
//

#import "TYProjectViewController.h"
#import <Masonry/Masonry.h>
#import <TuyaSmartCommercialLightingSdk/TuyaSmartCommercialLightingSdk.h>
#import <SVProgressHUD/SVProgressHUD.h>

#import "TYAreaListViewController.h"
#import "TYCacheManager.h"
#import "TYAreaListViewController.h"

@interface TYProjectViewController ()<UITableViewDelegate, UITableViewDataSource>

@property(nonatomic, strong) IBOutlet UITableView *tableView;
@property(nonatomic, strong) NSArray<TuyaLightingProjectModel *> *dataArray;
@property(nonatomic, assign) NSInteger seleceIndex;


@end

@implementation TYProjectViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self loadData];
}

- (void)loadData {
    [SVProgressHUD show];
    TuyaLightingProjectManager *manager = [[TuyaLightingProjectManager alloc] init];
    [manager getProjectListWithSuccess:^(NSArray<TuyaLightingProjectModel *> * _Nonnull projectList) {
        [SVProgressHUD dismiss];
        self.dataArray = projectList;
        
        if (TYCacheManager.sharedInstance.projectId == 0) {
            self.seleceIndex = 0;
            TYCacheManager.sharedInstance.projectId = self.dataArray.firstObject.projectId;
        }
        
        [self.tableView reloadData];
        
    } failure:^(NSError * _Nonnull error) {
        [SVProgressHUD dismiss];
    }];
}


#pragma mark - UITableView

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    cell.textLabel.text = self.dataArray[indexPath.row].name;

    if(indexPath.row == self.seleceIndex){
        cell.accessoryType = UITableViewCellAccessoryCheckmark;
    } else {
        cell.accessoryType = UITableViewCellAccessoryNone;
    }

    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    self.seleceIndex = indexPath.row;
    [self.tableView reloadData];
    
    TYCacheManager.sharedInstance.projectId = self.dataArray[indexPath.row].projectId;
    
    TYAreaListViewController *vc = (TYAreaListViewController *)((UINavigationController *)self.tabBarController.viewControllers[1]).topViewController;
    [vc loadData];
}

@end
