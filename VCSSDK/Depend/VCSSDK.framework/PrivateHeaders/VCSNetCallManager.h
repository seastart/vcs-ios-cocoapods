//
//  VCSNetCallManager.h
//  VCSSDK
//
//  Created by SailorGa on 2020/8/18.
//

#import <Foundation/Foundation.h>
#import "Register.pbobjc.h"
#import "Models.pbobjc.h"
#import "VCSNetCallManagerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface VCSNetCallManager : NSObject

#pragma mark 呼叫服务相关代理
@property (nonatomic, weak) id <VCSNetCallManagerProtocol> delegate;

#pragma mark - -------- 呼叫服务基础接口 ---------
#pragma mark 单例模式初始化呼叫服务实例
/// 单例模式初始化呼叫服务实例
+ (VCSNetCallManager *)sharedManager;

#pragma mark 获取呼叫服务版本号
/// 获取呼叫服务版本号
- (NSString *)version;

#pragma mark 获取呼叫服务版本信息
/// 获取呼叫服务版本信息
- (NSString *)getVersionInfo;

#pragma mark 连接呼叫服务
/// 连接呼叫服务
/// @param accountId 帐号ID
/// @param token 登录token
/// @param meetingHost 连接地址
/// @param meetingPort 连接端口
- (BOOL)startNetCallWithAccountId:(NSString *)accountId token:(NSString *)token meetingHost:(NSString *)meetingHost meetingPort:(NSInteger)meetingPort;

#pragma mark 停止并释放呼叫服务
/// 停止并释放呼叫服务
- (void)stop;

#pragma mark 发起邀请
/// 发起邀请
/// @param roomNo 房间号码
/// @param targetId 目标账号ID
- (void)inviteWithRoomNo:(NSString *)roomNo targetId:(NSString *)targetId;

#pragma mark 发送邀请入会确认
/// 发送邀请入会请求
/// @param inviteId 邀请人账号ID
/// @param roomNo 房间号码
/// @param targetId 目标账号ID
/// @param isAccepted 是否接受邀请(YES-接受 NO-拒绝)
- (void)inviteConfirmWithInviteId:(NSString *)inviteId roomNo:(NSString *)roomNo targetId:(NSString *)targetId isAccepted:(BOOL)isAccepted;

#pragma mark 发起呼叫
/// 发起呼叫
/// @param accountsArray 呼叫列表
/// @param roomNo 房间ID
/// @param restart 是否重新开始(YES-忽略上次的呼叫 NO-叠加上次的呼叫)
- (void)callWithAccountsArray:(nullable NSMutableArray<WaitingAccount *> *)accountsArray roomNo:(NSString *)roomNo restart:(BOOL)restart;

#pragma mark 取消呼叫
/// 取消呼叫
/// @param accountsArray 取消呼叫列表
/// @param roomNo 房间ID
- (void)callCancelWithAccountsArray:(nullable NSMutableArray<WaitingAccount *> *)accountsArray roomNo:(NSString *)roomNo;

#pragma mark 从呼叫中移除
/// 从呼叫中移除
/// @param targetIdArray 目标用户ID列表(空集合则取消所有人)
/// @param roomNo 房间ID
- (void)callRemoveWithTargetIdArray:(nullable NSMutableArray<NSString *> *)targetIdArray roomNo:(NSString *)roomNo;

#pragma mark 上报自己的通话状态
/// 上报自己的通话状态
/// @param roomNo 房间号码
/// @param name 用户名
/// @param nickname 用户昵称
/// @param portrait 用户头像
/// @param status 通话状态
- (void)accountStatusWithRoomNo:(NSString *)roomNo name:(nullable NSString *)name nickname:(nullable NSString *)nickname portrait:(nullable NSString *)portrait status:(InviteStatus)status;

@end

NS_ASSUME_NONNULL_END
