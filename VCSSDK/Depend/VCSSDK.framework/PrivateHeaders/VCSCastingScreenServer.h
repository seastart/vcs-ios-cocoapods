//
//  VCSCastingScreenServer.h
//  VCSSDK
//
//  Created by SailorGa on 2023/4/17.
//

#import <hkScreenShared/hkScreenShared.h>
#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSCastingScreenServer;

#pragma mark - 投屏服务端回调代理
@protocol VCSCastingScreenServerDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 投屏编码后数据回调
/// 投屏编码后数据回调
/// @param server 服务端实例
/// @param streamData 共享流数据
/// @param pts 显示时间戳
/// @param dts 解码时间戳
/// @param angle 显示角度
- (void)screenServer:(VCSCastingScreenServer *)server didStreamData:(NSData *)streamData pts:(uint32_t)pts dts:(uint32_t)dts angle:(int)angle;

#pragma mark 投屏音频原始数据回调
/// 投屏音频原始数据回调
/// @param server 服务端实例
/// @param streamData 共享音频数据
/// @param pts 显示时间戳
/// @param dts 解码时间戳
- (void)screenServer:(VCSCastingScreenServer *)server didAudioStreamData:(NSData *)streamData pts:(uint32_t)pts dts:(uint32_t)dts;

#pragma mark 投屏状态码回调
/// 投屏状态码回调
/// @param server 服务端实例
/// @param status 状态码
- (void)screenServer:(VCSCastingScreenServer *)server didProcessStatus:(int)status;

@end

#pragma mark - VCSCastingScreenServer
@interface VCSCastingScreenServer : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 投屏服务端回调代理
@property (nonatomic, weak) id<VCSCastingScreenServerDelegate> delegate;

#pragma mark 获取投屏服务端实例
/// 获取投屏服务端实例
+ (VCSCastingScreenServer *)sharedInstance;

#pragma mark 投屏版本
/// 投屏版本
- (NSString *)version;

#pragma mark 开启投屏服务端
/// 开启投屏服务端
/// @param delegate 代理回调
- (void)startScreenRecordingServer:(nullable id <VCSCastingScreenServerDelegate>)delegate;

#pragma mark 关闭投屏服务端
/// 关闭投屏服务端
- (void)closeScreenServer;

#pragma mark 强制关键帧
/// 强制关键帧
- (BOOL)forceKeyFrame;

#pragma mark 资源销毁
/// 资源销毁
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
