//
//  VCSCastingSignaling.h
//  VCSSDK
//
//  Created by SailorGa on 2023/4/18.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSSDK/VCSSDK.h>)
#import <VCSSDK/VCSCastingParam.h>
#else
#import "VCSCastingParam.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSCastingSignaling;

#pragma mark - 投屏消息回调代理
@protocol VCSCastingSignalingDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 开启投屏回调
/// 开启投屏回调
/// @param signaling 指令实例
/// @param status 是否允许投屏(0-接受 1-拒绝)
/// @param extra 附加信息
- (void)castingSignaling:(VCSCastingSignaling *)signaling onCastingStartStatus:(VCSCastingStatus)status didExtra:(nullable NSString *)extra;

#pragma mark 结束投屏回调
/// 结束投屏回调
/// @param signaling 指令实例
- (void)castingSignalingDidCastingStop:(VCSCastingSignaling *)signaling;

#pragma mark 请求I帧回调
/// 请求I帧回调
/// @param signaling 指令实例
- (void)castingSignalingRequestIDR:(VCSCastingSignaling *)signaling;

#pragma mark 当前服务延时回调
/// 当前服务延时回调
/// @param timestamp 当前延时
- (void)castingSignalingDelayed:(NSInteger)timestamp;

@end

/// 释放完成回调
typedef void (^VCSCastingSignalingDestroyBlock)(void);

#pragma mark - VCSCastingSignaling
@interface VCSCastingSignaling : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

#pragma mark 获取投屏信令实例
/// 获取投屏信令实例
+ (VCSCastingSignaling *)sharedInstance;

#pragma mark 连接服务器
/// 连接服务器
/// - Parameter serviceHost: 服务地址
/// - Parameter linkId: 成员标识
/// - Parameter username: 成员标识
/// - Parameter delegate: 代理回调
- (BOOL)servicConnect:(NSString *)serviceHost linkId:(NSString *)linkId username:(NSString *)username delegate:(nullable id <VCSCastingSignalingDelegate>)delegate;

#pragma mark 启动投屏信令
/// 启动投屏信令
- (void)beginCastingSignaling;

#pragma mark 销毁连接
/// 销毁连接
/// @param finishBlock 释放完成回调
- (void)destroy:(VCSCastingSignalingDestroyBlock)finishBlock;

@end

NS_ASSUME_NONNULL_END
