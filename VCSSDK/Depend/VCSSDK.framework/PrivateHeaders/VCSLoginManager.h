//
//  VCSLoginManager.h
//  VCSSDK
//
//  Created by SailorGa on 2021/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 操作结果回调
typedef void (^VCSLoginManagerResultBlock)(NSError * _Nullable error);

@interface VCSLoginManager : NSObject

/// 服务连接状态
@property (nonatomic, assign, readonly) BOOL isServeConnect;

/// 登录令牌
@property (nonatomic, copy) NSString *token;
/// 连接地址
@property (nonatomic, copy) NSString *meetingHost;
/// 连接端口
@property (nonatomic, assign) NSInteger meetingPort;
/// 注册服务器标识
@property (nonatomic, copy) NSString *serverId;

#pragma mark - -------- 登录服务基础接口 ---------
#pragma mark 获取登录服务实例
/// 获取登录服务实例
+ (VCSLoginManager *)sharedManager;

#pragma mark 登录服务
/// 登录服务
/// @param token 登录token
/// @param meetingHost 连接地址
/// @param meetingPort 连接端口
/// @param serverId 注册服务器ID
/// @param timeoutInterval 超时时间
/// @param resultBlock 登录结果回调
- (void)login:(NSString *)token meetingHost:(NSString *)meetingHost meetingPort:(NSInteger)meetingPort serverId:(NSString *)serverId timeoutInterval:(NSTimeInterval)timeoutInterval resultBlock:(nullable VCSLoginManagerResultBlock)resultBlock;

#pragma mark 退出服务
/// 退出服务
- (void)logout;

@end

NS_ASSUME_NONNULL_END
