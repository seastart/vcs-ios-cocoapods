//
//  VCSCastingScreenClient.h
//  VCSSDK
//
//  Created by SailorGa on 2023/4/17.
//

#import <hkScreenShared/hkScreenShared.h>
#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSCastingScreenClient;

#pragma mark - 投屏客户端回调代理
@protocol VCSCastingScreenClientDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 录屏完成回调
/// 录屏完成回调
/// @param clientn 客户端实例
/// @param reason 原因描述
- (void)screenClient:(VCSCastingScreenClient *)client didBroadcastFinished:(NSString *)reason;

@end

#pragma mark - VCSCastingScreenClient
@interface VCSCastingScreenClient : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 投屏客户端回调代理
@property (nonatomic, weak) id<VCSCastingScreenClientDelegate> delegate;

#pragma mark 获取投屏客户端实例
/// 获取投屏客户端实例
+ (VCSCastingScreenClient *)sharedInstance;

#pragma mark 开启投屏客户端
/// 开启投屏客户端
/// @param delegate 代理回调
- (void)startScreenRecordingClient:(nullable id <VCSCastingScreenClientDelegate>)delegate;

#pragma mark 发送共享屏幕帧数据
/// 发送共享屏幕帧数据
/// @param sampleBuffer 帧数据
/// @param sampleBufferType 帧数据类型
- (void)sendSampleBufferServer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;

@end

NS_ASSUME_NONNULL_END
