//
//  ScreenRTCServerSocket.h
//  hkScreenShared
//
//  Created by rich rich on 28/5/2020.
//  Copyright © 2020 rich rich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
/// #import <pthread.h>
/// #import "ScreenRTCConnect.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ScreenRTCServerConnectProtocol;

@interface ScreenRTCServer:NSObject
/// : ScreenRTCConnect

/// 回调代理
@property(nonatomic , weak) id <ScreenRTCServerConnectProtocol> delegate;

/// 初始化屏幕采集服务端
/// - Parameters:
///   - ModeType: 编码模式 0-编码模式 1-原数据模式
///   - appGroup: Application Group Identifier
///   - isCasting: 是否是投屏模式 YES-投屏 NO-共享
- (BOOL)initServerConnect:(int)ModeType appGroup:(NSString *)appGroup isCasting:(BOOL)isCasting;

/// 创建服务端链接
- (BOOL)createServerConnect;

/// 释放服务端链接
- (BOOL)destroyServerConnect;

/// 关闭录屏服务
- (BOOL)closeClientByCustomUser;

/// 请求关键帧
- (BOOL)doRequestIDR;

/// 更新编码帧率
- (BOOL)updateFps:(int)fps;

@end

/// 回调代理
@protocol ScreenRTCServerConnectProtocol <NSObject>

/// 非编码数据【NV12】
/// - (void)didProcessSampleBuffer:(CMSampleBufferRef)sampleBuffer stamp:(CMTime)pts;

/// 视频编码数据回调
- (void)didProcessEncoderData:(NSData *)sampleBuffer pts:(uint32_t)pts dts:(uint32_t)dts angle:(int)angle keyframe:(BOOL)keyframe;

/// 音频数据回调
- (void)didProcessAudioData:(NSData *)sampleBuffer pts:(uint32_t)pts dts:(uint32_t)dts;

/// 屏幕采集状态回调
/// [0]-屏幕采集停止
/// [1]-屏幕采集开始
/// [1]-屏幕采集异常
- (void)didProcessStatus:(int)codes;

@end
NS_ASSUME_NONNULL_END
