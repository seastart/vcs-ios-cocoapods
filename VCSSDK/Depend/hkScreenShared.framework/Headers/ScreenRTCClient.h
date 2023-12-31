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
//: ScreenRTCConnect
//encoder 必须设置这些编码参数否则录屏失败 720x1280    300kp
@property (nonatomic, readwrite) unsigned short Encoderwidth;
@property (nonatomic, readwrite) unsigned short Encoderheight;
@property (nonatomic, readwrite) uint32_t EncodermaxFramerate;//30
@property (nonatomic, copy) StopReplayKit ReplayBlock;

//非编码模式输出参数
@property (nonatomic, readwrite) unsigned int height;//720p

- (BOOL)initCliectConnect:(int)ModeType appGroup:(NSString *)appGroup; //初始化后方可创createCliectConnect
/// 创建 client socket
- (BOOL)createCliectConnect;
//close
- (void)close;

/// client send data to  server
- (void)sendBuffertoServer:(CMSampleBufferRef)sampleBuffer;

/// client send audio data to  server
- (void)sendAudioBuffertoServer:(CMSampleBufferRef)sampleBuffer;

- (void)sendNotifyBuffertoServer;

#pragma mark - 请求调整码率
/// 请求调整码率
/// - Parameter isReduce: YES-降低 NO-提升
- (void)requestAdjustBitrate:(BOOL)isReduce;

@end

NS_ASSUME_NONNULL_END
