//
//  VCSWebRTCManager.h
//  VCSSDK
//
//  Created by SailorGa on 2023/10/9.
//

#import <Foundation/Foundation.h>
#import <WebRTC/WebRTC.h>

#if __has_include(<VCSSDK/VCSSDK.h>)
#import <VCSSDK/VCSMeetingParam.h>
#else
#import "VCSMeetingParam.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSWebRTCManager;

#pragma mark - 服务代理回调
@protocol VCSWebRTCManagerDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 远端视频数据回调
/// 远端视频数据回调
/// - Parameters:
///   - userId: 用户标识
///   - trackId: 轨道号
///   - type: 视频存储格式(0 - I420 , 1 - NV12, 2 - NV21)
///   - rotation: 视频方向
///   - width: 视频宽度
///   - height: 视频高度
///   - yData: 像素数据
///   - uData: 像素数据
///   - vData: 像素数据
- (void)roomRemoteStreamWithUserId:(NSString *)userId trackId:(int)trackId type:(int)type rotation:(RTCVideoRotation)rotation width:(int)width height:(int)height yData:(void *)yData uData:(void *)uData vData:(void *)vData;

#pragma mark 远端音频功率数据回调
/// 远端音频功率数据回调
/// - Parameter audioArray: 音频功率列表
- (void)roomRemoteAudioStatusAudioArray:(NSMutableArray<NSDictionary *> *)audioArray;

#pragma mark 设备性能使用情况回调
/// 设备性能使用情况回调
/// - Parameters:
///   - memory: 内存使用
///   - cpu: CPU占用率
- (void)devicePerformanceNotification:(double)memory cpu:(double)cpu;

@end

/// 获取时间戳回调
typedef void(^VCSWebRTCTimestampBlock)(void(^completionHandler)(NSInteger timestamp));

@interface VCSWebRTCManager : NSObject

#pragma mark 获取服务单例
/// 获取服务单例
+ (VCSWebRTCManager *)sharedManager;

#pragma mark 设置时间戳回调
/// 设置时间戳回调
@property (nonatomic, copy) VCSWebRTCTimestampBlock timestampBlock;

#pragma mark 加入房间
/// 加入房间
/// - Parameters:
///   - meetingParam: 入会参数
///   - roomNo: 房间号码
///   - delegate: 回调代理
- (void)enterRoomWithMeetingParam:(nonnull VCSMeetingParam *)meetingParam roomNo:(NSString *)roomNo delegate:(nullable id <VCSWebRTCManagerDelegate>)delegate;

#pragma mark 订阅远端用户的视频流
/// 订阅远端用户的视频流
/// - Parameters:
///   - userId: 指定远端用户标识
///   - trackId: 指定远端轨道标识
///   - subscribe: YES-订阅 NO-取消订阅
- (void)subscribeRemoteVideo:(NSString *)userId trackId:(int)trackId subscribe:(BOOL)subscribe;

#pragma mark 取消订阅远端所有视频流
/// 取消订阅远端所有视频流
- (void)unSubscribeRemoteAllVideo;

#pragma mark 订阅远端用户的音频流
/// 订阅远端用户的音频流
/// - Parameters:
///   - userId: 指定远端用户标识
///   - subscribe: YES-订阅 NO-取消订阅
- (void)subscribeRemoteAudio:(NSString *)userId subscribe:(BOOL)subscribe;

#pragma mark 取消订阅远端所有音频流
/// 取消订阅远端所有音频流
- (void)unSubscribeRemoteAllAudio;

#pragma mark 设置音频是否播放
/// 设置音频是否播放
/// - Parameter enabled: YES-播放 NO-静音
- (void)enabledAudio:(BOOL)enabled;

#pragma mark 离开房间
/// 离开房间
- (void)exitRoom;

@end

NS_ASSUME_NONNULL_END
