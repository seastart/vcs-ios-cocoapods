//
//  VCSCastingProbes.h
//  VCSSDK
//
//  Created by SailorGa on 2023/7/3.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSSDK/VCSSDK.h>)
#import <VCSSDK/VCSCastingParam.h>
#else
#import "VCSCastingParam.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSCastingProbes;

#pragma mark - 投屏检测回调代理
@protocol VCSCastingProbesDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 投屏检测回调
/// 投屏检测回调
/// @param probes 指令实例
/// @param status 是否允许投屏(0-接受 1-拒绝)
/// @param extra 附加信息
- (void)castingProbes:(VCSCastingProbes *)probes onCastingStartStatus:(VCSCastingStatus)status didExtra:(nullable NSString *)extra;

@end

/// 释放完成回调
typedef void (^VCSCastingProbesDestroyBlock)(void);

#pragma mark - VCSCastingProbes
@interface VCSCastingProbes : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

#pragma mark 获取投屏检测实例
/// 获取投屏检测实例
+ (VCSCastingProbes *)sharedInstance;

#pragma mark 投屏检测
/// 投屏检测
/// - Parameter serviceHost: 服务地址
/// - Parameter linkId: 成员标识
/// - Parameter username: 成员标识
/// - Parameter delegate: 代理回调
- (BOOL)castingProbes:(NSString *)serviceHost linkId:(NSString *)linkId username:(NSString *)username delegate:(nullable id <VCSCastingProbesDelegate>)delegate;

#pragma mark 销毁投屏检测
/// 销毁投屏检测
/// @param finishBlock 释放完成回调
- (void)destroy:(VCSCastingProbesDestroyBlock)finishBlock;

@end

NS_ASSUME_NONNULL_END
