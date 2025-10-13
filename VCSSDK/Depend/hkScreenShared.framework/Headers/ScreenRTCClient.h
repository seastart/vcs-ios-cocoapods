//
//  ScreenRTCClient.h
//  hkScreenShared
//
//  Created by rich rich on 28/5/2020.
//  Copyright © 2020 rich rich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
NS_ASSUME_NONNULL_BEGIN

/// 停止屏幕采集回调
typedef void (^StopReplayKit)(NSString *msg);

@interface ScreenRTCClient:NSObject

/// 屏幕分辨率宽
@property (nonatomic, assign) unsigned short screenWidth;
/// 屏幕分辨率高
@property (nonatomic, assign) unsigned short screenHeight;

/// 编码分辨率宽，默认 720
@property (nonatomic, assign) unsigned short Encoderwidth;
/// 编码分辨率高，默认 1280
@property (nonatomic, assign) unsigned short Encoderheight;
/// 最大帧率，默认 20
@property (nonatomic, assign) uint32_t EncodermaxFramerate;
/// 停止屏幕采集回调
@property (nonatomic, copy) StopReplayKit ReplayBlock;

/// 初始化客户端连接
/// - Parameters:
///   - ModeType: 模式类型(暂无意义)
///   - appGroup: Application Group Identifier
- (BOOL)initCliectConnect:(int)ModeType appGroup:(NSString *)appGroup;

#pragma mark - 创建客户端连接
/// 创建客户端连接
- (BOOL)createCliectConnect;

#pragma mark - 关闭客户端连接
/// 关闭客户端连接
- (void)close;

#pragma mark - 客户端将视频数据发送到服务器
/// 客户端将视频数据发送到服务器
/// - Parameter sampleBuffer: 视频数据
- (void)sendBuffertoServer:(CMSampleBufferRef)sampleBuffer;

#pragma mark - 客户端将音频数据发送到服务器
/// 客户端将音频数据发送到服务器
/// - Parameter sampleBuffer: 音频数据
- (void)sendAudioBuffertoServer:(CMSampleBufferRef)sampleBuffer;

#pragma mark - 静态补帧
/// 静态补帧
- (void)sendNotifyBuffertoServer;

#pragma mark - 请求调整码率
/// 请求调整码率
/// - Parameter isReduce: YES-降低 NO-提升
- (void)requestAdjustBitrate:(BOOL)isReduce;

@end

NS_ASSUME_NONNULL_END
