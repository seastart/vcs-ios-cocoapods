//
//  VCSInterfaces.h
//  VCSSDK
//
//  Created by SailorGa on 2021/3/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 呼叫服务接收订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRegReceiveTopic;
#pragma mark - 呼叫服务发送订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRegServerPublishTopic;

#pragma mark - 会控服务接收订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomReceiveTopic;
#pragma mark - 会控服务发送订阅主题
FOUNDATION_EXTERN NSString *__nonnull const VCSRoomServerPublishTopic;

#pragma mark - 美颜预览卸载通知
FOUNDATION_EXTERN NSString *__nonnull const VCSBeautyPreviewUninstallNotification;

@interface VCSInterfaces : NSObject

@end

NS_ASSUME_NONNULL_END
