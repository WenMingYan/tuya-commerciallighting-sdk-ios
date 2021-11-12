//
//  TuyaSmartMerchantModel.h
//  TuyaSmartBaseKit-UserToB
//
//  Created by huxn on 2021/5/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMerchantModel : NSObject

/// Merchant Code.
@property (nonatomic,strong) NSString *merchantCode;

/// Merchant Name.
@property (nonatomic,strong) NSString *merchantName;

/// Whether password of current account match this merchant.
@property (nonatomic,assign) BOOL match;

@end

NS_ASSUME_NONNULL_END
