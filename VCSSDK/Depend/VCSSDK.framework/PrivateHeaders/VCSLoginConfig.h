//
//  VCSLoginConfig.h
//  VCSSDK
//
//  Created by SailorGa on 2022/12/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VCSLoginConfig : NSObject

/// AppID
@property (nonatomic, copy) NSString *appId;
/// AppKey
@property (nonatomic, copy) NSString *appKey;
/// 服务器地址
@property (nonatomic, copy) NSString *domainUrl;

/// 登录账号
@property (nonatomic, copy) NSString *loginname;
/// 登录密码/短信验证码
@property (nonatomic, copy) NSString *password;

/// 公司标识
@property (nonatomic, copy, nullable) NSString *corpId;
/// 网络线路
@property (nonatomic, copy, nullable) NSString *lineId;
/// 推送标识
@property (nonatomic, copy, nullable) NSString *pushId;

/// 是否是游客身份登录
@property (nonatomic, assign) BOOL isTourist;

@end

NS_ASSUME_NONNULL_END
