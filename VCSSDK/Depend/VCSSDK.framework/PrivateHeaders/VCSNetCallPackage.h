//
//  VCSNetCallPackage.h
//  VCSSDK
//
//  Created by SailorGa on 2020/8/18.
//

#import <Foundation/Foundation.h>
#import "Register.pbobjc.h"
#import "Models.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 呼叫服务消息解析结果回调
/// 呼叫服务消息解析结果回调
/// @param type 报文类型
/// @param command 通知类型
/// @param result 结果
/// @param data 解析出的数据
typedef void(^VCSNetCallPackageBlock)(PacketType type, Command command, Result result, NSData *data);

@interface VCSNetCallPackage : NSObject

#pragma mark - 组装呼叫服务消息发送报文 报文头(12B) + 报文体(*B)
#pragma mark 发送心跳
/// 发送心跳
/// @param token 登录token
/// @param accountId 账号ID
/// @param version 版本信息
+ (NSData *)sendHeartBeatWithToken:(NSString *)token accountId:(NSString *)accountId version:(NSInteger)version;

#pragma mark 发送邀请入会请求
/// 发送邀请入会请求
/// @param token 登录token
/// @param accountId 账号ID
/// @param roomNo 房间号码
/// @param targetId 目标账号ID
+ (NSData *)sendInviteWithToken:(NSString *)token accountId:(NSString *)accountId roomNo:(NSString *)roomNo targetId:(NSString *)targetId;

#pragma mark 发送邀请入会确认
/// 发送邀请入会请求
/// @param inviteId 邀请人账号ID
/// @param accountId 账号ID
/// @param roomNo 房间号码
/// @param targetId 目标账号ID
/// @param response 邀请响应码
+ (NSData *)sendInviteConfirmWithInviteId:(NSString *)inviteId accountId:(NSString *)accountId roomNo:(NSString *)roomNo targetId:(NSString *)targetId response:(InviteResponse)response;

#pragma mark 发起呼叫
/// 发起呼叫
/// @param accountsArray 呼叫列表
/// @param roomNo 房间ID
/// @param token 登录token
/// @param accountId 用户ID
/// @param restart 是否重新开始(YES-忽略上次的呼叫 NO-叠加上次的呼叫)
+ (NSData *)sendCallWithAccountsArray:(NSMutableArray<WaitingAccount *> *)accountsArray token:(NSString *)token roomNo:(NSString *)roomNo accountId:(NSString *)accountId restart:(BOOL)restart;

#pragma mark 发起呼叫
/// 发起呼叫
/// @param accountsArray 呼叫列表
/// @param roomNo 房间ID
/// @param token 登录token
/// @param accountId 用户ID
/// @param restart 是否重新开始(YES-忽略上次的呼叫 NO-叠加上次的呼叫)
/// @param role 参会角色
+ (NSData *)sendCallWithAccountsArray:(NSMutableArray<WaitingAccount *> *)accountsArray token:(NSString *)token roomNo:(NSString *)roomNo accountId:(NSString *)accountId restart:(BOOL)restart role:(ConferenceRole)role;

#pragma mark 从呼叫中移除(废弃)
/// 从呼叫中移除(废弃)
/// @param targetIdArray 目标用户ID列表
/// @param roomNo 房间ID
/// @param token 登录token
/// @param accountId 用户ID
+ (NSData *)sendCallRemoveWithTargetIdArray:(NSMutableArray<NSString *> *)targetIdArray token:(NSString *)token roomNo:(NSString *)roomNo accountId:(NSString *)accountId;

#pragma mark 取消呼叫(新增)
/// 取消呼叫(新增)
/// @param accountsArray 取消呼叫
/// @param roomNo 房间ID
/// @param token 登录token
/// @param accountId 用户ID
+ (NSData *)sendCallCancelNewWithAccountsArray:(NSMutableArray<WaitingAccount *> *)accountsArray token:(NSString *)token roomNo:(NSString *)roomNo accountId:(NSString *)accountId;

#pragma mark 从呼叫中移除(新增)
/// 从呼叫中移除(新增)
/// @param accountsArray 移除目标用户列表(空集合则移除所有人)
/// @param roomNo 房间ID
/// @param token 登录token
/// @param accountId 用户ID
+ (NSData *)sendCallRemoveNewWithAccountsArray:(NSMutableArray<RemoveAccount *> *)accountsArray token:(NSString *)token roomNo:(NSString *)roomNo accountId:(NSString *)accountId;

#pragma mark 上报自己的通话状态
/// 上报自己的通话状态
/// @param account 用户信息
/// @param token 登录token
+ (NSData *)sendAccountStatusWithWaitingAccount:(WaitingAccount *)account token:(NSString *)token;

#pragma mark - 解析收到的呼叫服务消息
/// 解析收到的呼叫服务消息
/// @param receiveData 接收数据
/// @param resultBlock 结果回调
+ (void)receiveSocketData:(NSData *)receiveData resultBlock:(VCSNetCallPackageBlock)resultBlock;

@end

NS_ASSUME_NONNULL_END
