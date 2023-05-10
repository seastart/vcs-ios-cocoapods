//
//  VCSReplayKit.h
//  VCSSDK
//
//  Created by SailorGa on 2023/5/9.
//

#import <hkScreenShared/hkScreenShared.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSReplayKit;

#pragma mark - 录屏代理回调
/// 录屏代理回调
API_AVAILABLE(ios(12.0))
@protocol VCSReplayKitDelegate <NSObject>

#pragma mark 录屏完成回调
/// 录屏完成回调
/// - Parameters:
///   - broadcast: 录屏实例
///   - reason: 录屏结束原因
- (void)broadcastFinished:(VCSReplayKit *)broadcast reason:(NSString *)reason;

@end

#pragma mark - 录屏主入口类
/// 录屏主入口类
API_AVAILABLE(ios(12.0))
@interface VCSReplayKit : NSObject

#pragma mark 获取单例
/// 获取单例
+ (VCSReplayKit *)sharedInstance;

#pragma mark 录屏启动方法
/// 录屏启动方法
/// 需要在 RPBroadcastSampleHandler 的实现类中的 broadcastStartedWithSetupInfo 方法中调用
/// - Parameters:
///   - delegate: 回调对象
- (void)broadcastStartedWithDelegate:(id<VCSReplayKitDelegate>)delegate;

#pragma mark 媒体数据(音视频)发送方法
/// 媒体数据(音视频)发送方法
/// - Parameters:
///   - sampleBuffer: 系统回调的视频或音频帧
///   - sampleBufferType: 媒体输入类型
/// 注释：sampleBufferType 当前支持 RPSampleBufferTypeVideo 和 RPSampleBufferTypeAudioApp 类型的数据帧处理；
/// RPSampleBufferTypeAudioMic 不支持，可以在宿主 App 处理麦克风采集数据。
- (void)sendSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;

@end

NS_ASSUME_NONNULL_END
