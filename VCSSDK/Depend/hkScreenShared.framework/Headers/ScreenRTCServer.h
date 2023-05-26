//
//  ScreenRTCServerSocket.h
//  hkScreenShared
//
//  Created by rich rich on 28/5/2020.
//  Copyright © 2020 rich rich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
//#import <pthread.h>

//#import "ScreenRTCConnect.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ScreenRTCServerConnectProtocol;

@interface ScreenRTCServer:NSObject
//: ScreenRTCConnect

/**
 delegate
 */
@property(nonatomic , weak)id <ScreenRTCServerConnectProtocol> delegate;

#pragma mark - 初始化屏幕采集服务端
/// 初始化屏幕采集服务端
/// - Parameters:
///   - ModeType: 编码模式 0-编码模式 1-原数据模式
///   - appGroup: Application Group Identifier
///   - isCasting: 是否是投屏模式 YES-投屏 NO-共享
- (BOOL)initServerConnect:(int)ModeType appGroup:(NSString *)appGroup isCasting:(BOOL)isCasting;

/// 创建 server connect
- (BOOL)createServerConnect;

//
-(BOOL)destroyServerConnect;

-(BOOL )closeClientByCustomUser;

//用户请求关键帧

-(BOOL)doRequestIDR;

//更新编码帧率
-(BOOL)updateFps:(int)fps;

@end


@protocol ScreenRTCServerConnectProtocol <NSObject>

//非编码数据【NV12】
//- (void)didProcessSampleBuffer:(CMSampleBufferRef)sampleBuffer stamp:(CMTime)pts;

//编码数据
- (void)didProcessEncoderData:(NSData*)sampleBuffer pts:(uint32_t)pts dts:(uint32_t)dts angle:(int)angle;

//a音频
- (void)didProcessAudioData:(NSData*)sampleBuffer pts:(uint32_t)pts dts:(uint32_t)dts;


//Screen status  code [0:screen stop,1:screen start -1:screen connnect error]
-(void)didProcessStatus:(int)codes;
@end
NS_ASSUME_NONNULL_END
