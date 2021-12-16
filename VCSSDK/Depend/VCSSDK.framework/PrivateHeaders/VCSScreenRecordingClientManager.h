//
//  VCSScreenRecordingClientManager.h
//  VCSSDK
//
//  Created by SailorGa on 2020/6/11.
//

#import <Foundation/Foundation.h>
#import <hkScreenShared/hkScreenShared.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^VCSScreenClientCloseBlock)(NSString * _Nullable errorMsg);

@interface VCSScreenRecordingClientManager : NSObject

#pragma mark - -------- 屏幕录制被调用端基础接口 ---------
#pragma mark 单例模式初始化屏幕录制被调用端实例
/// 单例模式初始化屏幕录制被调用端实例
+ (VCSScreenRecordingClientManager *)sharedManager;

#pragma mark - 开启录制被调用端(编码模式)
/// 开启录制被调用端(编码模式)
/// @param closeBlock 被调用端关闭回调
- (void)startEncoderScreenRecordingClient:(VCSScreenClientCloseBlock)closeBlock;

#pragma mark - 开启录制被调用端(非编码模式)
/// 开启录制被调用端(非编码模式)
/// @param closeBlock 被调用端关闭回调
- (void)startScreenRecordingClient:(VCSScreenClientCloseBlock)closeBlock;

#pragma mark - 关闭被调用端屏幕共享连接
- (void)closeScreenClient;

#pragma mark - 发送缓冲区音视频流到服务器
/// 发送缓冲区音视频流到服务器
/// @param sampleBuffer 缓冲区
- (void)sendSampleBufferServer:(CMSampleBufferRef)sampleBuffer;

#pragma mark - 静态补帧
/// 静态补帧
- (void)sendNotifyBuffertoServer;

@end

NS_ASSUME_NONNULL_END
