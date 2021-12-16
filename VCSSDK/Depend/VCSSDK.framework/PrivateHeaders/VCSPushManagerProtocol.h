//
//  VCSPushManagerProtocol.h
//  VCSSDK
//
//  Created by SailorGa on 2021/3/22.
//

#pragma mark - 推送服务相关代理
@protocol VCSPushManagerProtocol <NSObject>

#pragma mark 可选实现代理方法
@optional

#pragma mark 推送服务注册成功返回clientId
/// 推送服务注册成功返回clientId
/// @param clientId 客户端ID
- (void)onListenPushDidRegisterWithClientId:(nullable NSString *)clientId;

#pragma mark 收到透传消息
/// 收到透传消息
/// @param userInfo 推送消息内容
/// @param fromGetui YES-个推通道  NO-苹果APNs通道
/// @param offLine 是否是离线消息，YES-是离线消息
/// @param appId 应用的AppID
/// @param taskId 推送消息的任务ID
/// @param msgId 推送消息的MessageID
- (void)onListenPushDidReceiveWithUserInfo:(nullable NSDictionary *)userInfo fromGetui:(BOOL)fromGetui offLine:(BOOL)offLine appId:(nullable NSString *)appId taskId:(nullable NSString *)taskId msgId:(nullable NSString *)msgId;

#pragma mark 收到通知信息
/// 收到通知信息
/// @param notification apns通知内容
- (void)onListenPushDidReceiveWithNotification:(nullable NSDictionary *)notification;

@end
