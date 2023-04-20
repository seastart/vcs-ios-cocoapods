//
//  VCSCastingManager.h
//  VCSSDK
//
//  Created by SailorGa on 2023/4/10.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <ReplayKit/ReplayKit.h>

#if __has_include(<VCSSDK/VCSSDK.h>)
#import <VCSSDK/VCSCastingParam.h>
#else
#import "VCSCastingParam.h"
#endif

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 投屏状态回调
/// 投屏状态回调
typedef void (^VCSCastingBroadcastStatusBlock)(VCSCastingStatus status);

#pragma mark - 投屏完成回调
/// 投屏完成回调
typedef void (^VCSCastingBroadcastFinishedBlock)(NSString * _Nullable reason);

#pragma mark - VCSCastingManager
@interface VCSCastingManager : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------
#pragma mark 接收端是否允许投屏
/// 接收端是否允许投屏
@property (nonatomic, assign, readonly) VCSCastingStatus castingStatus;

#pragma mark 获取投屏单例
/// 获取投屏单例
+ (VCSCastingManager *)sharedInstance;

#pragma mark - ------------ 投屏宿主相关接口函数 ------------
#pragma mark 配置投屏参数
/// 配置投屏参数
/// - Parameters:
///   - mediaConfig: 配置参数
///   - statusBlock: 状态回调
- (void)setupCastingConfig:(VCSCastingMediaConfig *)mediaConfig statusBlock:(VCSCastingBroadcastStatusBlock)statusBlock;

#pragma mark 停止投屏
/// 停止投屏
- (void)stopCasting;

#pragma mark - ------------ 投屏扩展相关接口函数 ------------
#pragma mark 开启投屏客户端
/// 开启投屏客户端
/// @param finishedBlock 完成回调
- (void)startCastingScreenClient:(VCSCastingBroadcastFinishedBlock)finishedBlock;

#pragma mark 发送投屏帧数据
/// 发送投屏帧数据
/// @param sampleBuffer 帧数据
/// @param sampleBufferType 帧数据类型
- (void)sendCastingSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;

@end

NS_ASSUME_NONNULL_END
