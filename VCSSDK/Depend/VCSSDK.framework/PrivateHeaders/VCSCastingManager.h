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

#pragma mark - 投屏回调
@protocol VCSCastingManagerDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 投屏检测状态回调
/// 投屏检测状态回调
/// @param status 状态码
/// @param reason 拒绝原因
- (void)onCastingProbesStatus:(VCSCastingStatus)status reason:(nullable NSString *)reason;

#pragma mark 屏幕录制状态回调
/// 屏幕录制状态回调
/// @param status 状态码
- (void)onScreenRecordStatus:(VCSCastingScreenStatus)status;

#pragma mark 投屏状态回调
/// 投屏状态回调
/// @param status 状态码
/// @param reason 拒绝原因
- (void)onCastingScreenStatus:(VCSCastingStatus)status reason:(nullable NSString *)reason;

#pragma mark 发送状态信息回调
/// 发送状态信息回调
/// @param sendModel 发送状态数据
- (void)onSendStreamModel:(VCSStreamSendModel *)sendModel;

#pragma mark 当前服务延时回调
/// 当前服务延时回调
/// @param timestamp 服务延时
- (void)onSignalingDelayed:(NSInteger)timestamp;

@end

#pragma mark - 投屏完成回调
/// 投屏完成回调
typedef void (^VCSCastingBroadcastFinishedBlock)(NSString * _Nullable reason);

#pragma mark - VCSCastingManager
@interface VCSCastingManager : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 当前屏幕录制状态
@property (nonatomic, assign, readonly) VCSCastingScreenStatus screenStatus;

#pragma mark 获取投屏单例
/// 获取投屏单例
+ (VCSCastingManager *)sharedInstance;

#pragma mark - ------------ 投屏宿主相关接口函数 ------------
#pragma mark 配置投屏参数
/// 配置投屏参数
/// - Parameters:
///   - mediaConfig: 配置参数
///   - appGroup: Application Group Identifier
///   - delegate: 代理回调
- (void)setupCastingConfig:(VCSCastingMediaConfig *)mediaConfig appGroup:(NSString *)appGroup delegate:(nullable id <VCSCastingManagerDelegate>)delegate;

#pragma mark 启动投射音频
/// 启动投射音频
/// - Parameter enable: YES-启用 NO-关闭
- (void)enableCastingAudio:(BOOL)enable;

#pragma mark 停止投屏
/// 停止投屏
- (void)stopCasting;

@end

NS_ASSUME_NONNULL_END
