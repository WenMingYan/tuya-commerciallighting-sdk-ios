//
//  TuyaSmartUser+Merchant.h
//  TuyaSmartBaseKit-UserToB
//
//  Created by huxn on 2021/5/25.
//

#import <TuyaSmartBaseKit/TuyaSmartUser.h>
#import "TuyaSmartMerchantModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (Merchant)

/// Whether have destroy job
@property (nonatomic, assign) BOOL hasDelJob;

/// Store extra user Info
@property (nonatomic, strong,readonly) NSMutableDictionary *extra;

/// User register type.
typedef NS_ENUM(NSInteger, TYMerchantCodeType) {
    /// Register from email.
    TYMerchantCodeLogin,
    /// Register from mobile phone.
    TYMerchantCodeReg,
    /// Register from other.
    TYMerchantCodeModifyOrFindPasswordOrQuery,
    /// Login be reg
    TYMerchantCodeLoginBeReg
};

#pragma mark - Merchant register

/// Send verification code. Used for login, register or change password.
/// @param countryCode Country Code.
/// @param username User Name ,use phone or email.
/// @param codeType Code Type. 0 -login, 1-register, 2- modify or find password or Query Merchant 3-login be reg
/// @param merchantCode  MerchantCode Code. When send verify code for multiple merchant's login should input this param.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMerchantVerifyCodeWithCountryCode:(NSString *_Nonnull)countryCode
                                     username:(NSString *_Nonnull)username
                                     codeType:(TYMerchantCodeType)codeType
                                 merchantCode:(NSString *_Nullable)merchantCode
                                      success:(TYSuccessHandler _Nullable)success
                                      failure:(TYFailureError _Nullable)failure;

/// Register merchant user.
/// @param countryCode Country Code.
/// @param username User Name ,use phone or email.
/// @param password Password.
/// @param code  Verification Code.
/// @param industryType Industry Type.
/// @param companyName Company Name.Optional.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)registerMerchantWithCountryCode:(NSString *_Nonnull)countryCode
                               username:(NSString *_Nonnull)username
                               password:(NSString *_Nonnull)password
                                   code:(NSString *_Nonnull)code
                           industryType:(NSString *_Nonnull)industryType
                            companyName:(NSString *_Nullable)companyName
                                success:(TYSuccessID _Nullable)success
                                failure:(TYFailureError _Nullable)failure;
/// Check merchant verify code.
/// @param countryCode Country Code.
/// @param username  User Name.
/// @param codeType  Code Type. 0 -login, 1-register, 2- modify or find password or Query Merchant
/// @param code Verify Code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)checkMerchantVerifyCodeWithCountryCode:(NSString *_Nonnull)countryCode
                              username:(NSString *_Nonnull)username
                              codeType:(TYMerchantCodeType)codeType
                                  code:(NSString *_Nonnull)code
                               success:(TYSuccessBOOL _Nullable)success
                               failure:(TYFailureError _Nullable)failure;

#pragma mark - Merchant Login & Reset Password & Login Out

/// Login merchant by use password.
/// @param password Password.
/// @param countryCode Country Code.
/// @param username User Name ,use phone or email.
/// @param merchantCode Merchant Code.
/// @param multiMerchantHanlder  Called when count of  merchant greater than 1,can not direct login success.When count of merchant equal to 1,will direct login success and call success.
/// @param success Called when login successfully.
/// @param failure Called when the login task is interrupted by an error.
- (void)loginMerchantByPassword:(NSString *_Nonnull)password
                    countryCode:(NSString *_Nonnull)countryCode
                       username:(NSString *_Nonnull)username
                   merchantCode:(NSString *_Nullable)merchantCode
           multiMerchantHanlder:(void(^_Nullable)(NSArray<TuyaSmartMerchantModel *> * _Nonnull merchantInfos))multiMerchantHanlder
                        success:(TYSuccessHandler _Nullable)success
                        failure:(TYFailureError _Nullable)failure;

/// Login merchant by use verification code.
/// @param code Verification Code.
/// @param countryCode Country Code.
/// @param username User Name ,use phone or email.
/// @param merchantCode Merchant Code.
/// @param multiMerchantHanlder  Called when count of  merchant greater than 1,can not direct login success.When count of merchant equal to 1,will direct login success and call success.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginMerchantByVerificationCode:(NSString *_Nonnull)code
                            countryCode:(NSString *_Nonnull)countryCode
                               username:(NSString *_Nonnull)username
                           merchantCode:(NSString *_Nullable)merchantCode
                   multiMerchantHanlder:(void(^_Nullable)(NSArray<TuyaSmartMerchantModel *> * _Nonnull merchantInfos))multiMerchantHanlder
                                success:(TYSuccessHandler _Nullable)success
                                failure:(TYFailureError _Nullable)failure;


/// Login and register merchant by use verification code.
/// @param code Verification Code.
/// @param countryCode Country Code.
/// @param username User Name ,use phone or email.
/// @param industryType Industry Type.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginAndRegisterMerchantByVerificationCode:(NSString *_Nonnull)code
                                          username:(NSString *_Nonnull)username
                                       countryCode:(NSString *_Nonnull)countryCode
                                      industryType:(NSString *_Nonnull)industryType
                                           success:(TYSuccessHandler _Nullable)success
                                           failure:(TYFailureError _Nullable)failure;
/// Get merchant User Info.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getMerchantUserInfoWithSuccess:(TYSuccessHandler _Nullable)success
                            failure:(TYFailureError _Nullable)failure;

/// query merchant infos by  verification code.
/// @param code Verification Code.
/// @param username User Name ,use phone or email.
/// @param countryCode Country Code.
/// @param success Called when the task finishes successfully. Will return merchantInfos in success block.
/// @param failure Called when the task is interrupted by an error.
- (void)queryMerchantInfosByVerificationCode:(NSString *_Nonnull)code
                                    username:(NSString *_Nonnull)username
                                 countryCode:(NSString *_Nonnull)countryCode
                                     success:(void(^_Nullable)(NSArray<TuyaSmartMerchantModel *> * _Nullable merchantInfos))success
                                     failure:(TYFailureError _Nullable)failure;

/// get back merchant password by verification code.
/// @param code Verification Code.
/// @param username User Name ,use phone or email.
/// @param countryCode Country Code.
/// @param newPassword  New Password.
/// @param merchantCode  Merchant Code. query the merchant code first,then use merchant code to get back the merchant code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getBackMerchantPasswordByVerificationCode:(NSString *_Nonnull)code
                                         username:(NSString *_Nonnull)username
                                      countryCode:(NSString *_Nonnull)countryCode
                                      newPassword:(NSString *_Nonnull)newPassword
                                     merchantCode:(NSString *_Nonnull)merchantCode
                                          success:(TYSuccessHandler _Nullable)success
                                          failure:(TYFailureError _Nullable)failure;

/// Reset password.
/// @param oldPassword Old Password.
/// @param newPassword New Password.
/// @param username User Name ,use phone or email.
/// @param countryCode Country Code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)resetMerchantPasswordWithUsername:(NSString *_Nonnull)username
                              countryCode:(NSString *_Nonnull)countryCode
                               oldPassword:(NSString *_Nonnull)oldPassword
                               newPassword:(NSString *_Nonnull)newPassword
                                   success:(TYSuccessHandler _Nullable)success
                                   failure:(TYFailureError _Nullable)failure;

/// LoginOut merchant.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOutMerchantWithSuccess:(TYSuccessHandler _Nullable)success
                            failure:(TYFailureError _Nullable)failure;

/// Destroy account.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error
- (void)cancelMerchantAccount:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;

/// Update  merchant user head icon.
/// @param headIcon Head Icon.
- (void)updateMerchantHeadIcon:(UIImage *_Nonnull)headIcon success:(TYSuccessHandler _Nullable)success failure:(TYFailureError _Nullable)failure;

/// Update  merchant user nicknmae.
/// @param nickname Nickname.
- (void)updateMerchantNickname:(NSString *_Nonnull)nickname success:(TYSuccessHandler _Nullable)success failure:(TYFailureError _Nullable)failure;

/// Login merchant by ticket
/// @param ticket login ticket
/// @param multiMerchantHanlder Called when count of  merchant greater than 1,can not direct login success.When count of merchant equal to 1,will direct login success and call success.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error
- (void)loginMerchantByTicket:(nonnull NSString*)ticket
         multiMerchantHanlder:(void(^_Nullable)(NSArray<TuyaSmartMerchantModel *> * _Nonnull merchantInfos))multiMerchantHanlder
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
