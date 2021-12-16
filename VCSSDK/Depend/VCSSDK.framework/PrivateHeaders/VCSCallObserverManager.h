//
//  VCSCallObserverManager.h
//  VCSSDK
//
//  Created by SailorGa on 2020/5/12.
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CTCallCenter.h>
#import <CoreTelephony/CTCall.h>
#import "VCSCommons.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 电话监听实例相关代理
@protocol VCSCallObserverManagerDelegate <NSObject>

#pragma mark 可选实现代理方法
@optional

#pragma mark 来电监听
/// 来电监听
/// @param callState 来电状态
- (void)callObserverCallChanged:(NSString *)callState;

@end

@interface VCSCallObserverManager : NSObject

#pragma mark 电话监听实例相关代理
@property (nonatomic, weak) id <VCSCallObserverManagerDelegate> delegate;

#pragma mark - 单例模式电话监听实例
/// 单例模式电话监听实例
+ (VCSCallObserverManager *)sharedManager;

#pragma mark - 初始化监听实例
/// 初始化监听实例
- (void)initCallObserver;

#pragma mark - 释放电话监听资源
/// 释放电话监听资源
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
