//
//  VCSInterfaces.h
//  VCSSDK
//
//  Created by SailorGa on 2021/3/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 密码HmacSHA1加密Key
FOUNDATION_EXTERN NSString *__nonnull const VCSHmacSha1Key;
#pragma mark - HTTP接口请求前缀
FOUNDATION_EXTERN NSString *__nonnull const VCSDATADAPIPREFIX;
#pragma mark - 账号登录
FOUNDATION_EXTERN NSString *__nonnull const VCSAccountLoginInterfacePart;
#pragma mark - 游客登录
FOUNDATION_EXTERN NSString *__nonnull const VCSTouristLoginInterfacePart;

#pragma mark - 踢出指定成员
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomKickoutInfofacePart;
#pragma mark - 转移主持人给指定成员
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomMoveHostInfofacePart;
#pragma mark - 回收指定成员房间主持人权限
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomRecoveryHostInfofacePart;
#pragma mark - 设置/取消指定成员联席主持人权限
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomUnionHostInfofacePart;
#pragma mark - 设置房间音视频状态
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomMediaStateInfofacePart;
#pragma mark - 变更房间内成员昵称
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomMemberNicknameInfofacePart;
#pragma mark - 变更房间内自己的状态
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomSelvesStateInfofacePart;

#pragma mark - 呼叫服务接收订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRegReceiveTopic;
#pragma mark - 呼叫服务发送订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRegServerPublishTopic;

#pragma mark - 会控服务接收订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomReceiveTopic;
#pragma mark - 会控服务接收全员广播订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomBroadcastReceiveTopic;
#pragma mark - 会控服务发送订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomServerPublishTopic;

#pragma mark - 美颜预览卸载通知
FOUNDATION_EXTERN NSString *__nonnull const VCSBeautyPreviewUninstallNotification;

@interface VCSInterfaces : NSObject

@end

NS_ASSUME_NONNULL_END
