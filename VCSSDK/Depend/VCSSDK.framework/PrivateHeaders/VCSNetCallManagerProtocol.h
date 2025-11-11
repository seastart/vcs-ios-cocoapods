//
//  VCSNetCallManagerProtocol.h
//  VCSSDK
//
//  Created by SailorGa on 2020/8/18.
//

#pragma mark - 呼叫服务相关代理
@protocol VCSNetCallManagerProtocol <NSObject>

#pragma mark 可选实现代理方法
@optional

#pragma mark 呼叫服务响应回调
/// 呼叫服务响应回调
/// @param command cmd指令
/// @param result 结果
- (void)onListenNetCallResultCommand:(Command)command result:(Result)result;

#pragma mark 呼叫服务收到数据回调
/// 呼叫服务收到数据回调
/// @param data 消息体，注：该数据为未解包数据需要解包获取PacketType、Command、Result以及结构数据NSData
/// @param topic 订阅主题
/// @param retained 保留字段
- (void)onListenNetCallReceiveWithData:(NSData *)data topic:(nullable NSString *)topic retained:(BOOL)retained;

#pragma mark 邀请入会通知
/// 邀请入会通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallInviteWithNotify:(InviteNotification *)notify error:(NSError *)error;

#pragma mark 邀请入会确认通知
/// 邀请入会确认通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallInviteConfirmWithNotify:(InviteConfirm *)notify error:(NSError *)error;

#pragma mark 成员的通话状态通知
/// 成员的通话状态通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallAccountCallStatusWithNotify:(WaitingRoomBroadcast *)notify error:(NSError *)error;

#pragma mark 自己的通话状态通知
/// 自己的通话状态通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallMyAccountCallStatusWithNotify:(WaitingRoomUpdate *)notify error:(NSError *)error;

#pragma mark 应用内推送通知
/// 应用内推送通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallInAppPushNotificationWithNotify:(PushNotification *)notify error:(NSError *)error;

#pragma mark 会议开始通知(在线的受邀人员会收到该通知)
/// 会议开始通知(在线的受邀人员会收到该通知)
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallMeetingBeginNotificationWithNotify:(MeetingBeginNotify *)notify error:(NSError *)error;

#pragma mark 会议结束通知(在线的受邀人员会收到该通知)
/// 会议结束通知(在线的受邀人员会收到该通知)
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallMeetingEndedNotificationWithNotify:(MeetingEndNotify *)notify error:(NSError *)error;

#pragma mark 会议邀请通知
/// 会议邀请通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallMeetingInviteNotificationWithNotify:(InviteConfNoticeNotify *)notify error:(NSError *)error;

#pragma mark 聊天消息发送回执通知
/// 聊天消息发送回执通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallChatResponseWithNotify:(RegChatResponse *)notify error:(NSError *)error;

#pragma mark 聊天消息撤回通知
/// 聊天消息撤回通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallChatRevokeWithNotify:(RegChatRevokeNotify *)notify error:(NSError *)error;

#pragma mark 预约会议通知
/// 预约会议通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallRoomPrepareWithNotify:(RoomPrepareNotify *)notify error:(NSError *)error;

#pragma mark 呼叫卡片消息通知
/// 呼叫卡片消息通知
/// @param notify 通知信息
/// @param error 错误信息
- (void)onListenNetCallRoomCardMsgWithNotify:(CallCardMsgNotify *)notify error:(NSError *)error;

#pragma mark 事件命令透传通知
/// 事件命令透传通知
/// @param command 消息指令
/// @param content 消息内容
- (void)onListenNetCallEventWithCommand:(VCSCommandEventState)command content:(NSString *)content;

@end
