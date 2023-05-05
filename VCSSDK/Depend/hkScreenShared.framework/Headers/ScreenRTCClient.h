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

typedef void (^StopReplayKit)(NSString *msg);

@interface ScreenRTCClient:NSObject

@property (nonatomic, copy) StopReplayKit ReplayBlock;
/// YES-投屏 NO-共享，默认 NO
@property (nonatomic, assign) BOOL projection;

/// 初始化后方可创 Create Cliect Connect
- (BOOL)initCliectConnect:(int)ModeType;

/// 设置分辨率与编码帧率
- (void)setCaptureSize:(int)width height:(int)height framerate:(int)framerate;

/// 采集的帧率，默认15[进行弱网帧率控制的时候可以实时调用这个来设置]
- (void)setCaptureFps:(int)capfps;

/// 创建 client socket
- (BOOL)createCliectConnect;

/// close
- (void)close;

/// client send video data to server
- (void)sendBuffertoServer:(CMSampleBufferRef)sampleBuffer;

/// client send audio data to server
- (void)sendAudioBuffertoServer:(CMSampleBufferRef)sampleBuffer;

/// 在没有图像数据时进行补帧
- (void)sendNotifyBuffertoServer;

@end

NS_ASSUME_NONNULL_END
