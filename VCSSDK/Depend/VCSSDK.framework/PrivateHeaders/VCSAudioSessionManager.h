//
//  VCSAudioSessionManager.h
//  VCSSDK
//
//  Created by SailorGa on 2023/11/9.
//

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>
#import "VCSAudioRouteModel.h"
#import "VCSCommons.h"

NS_ASSUME_NONNULL_BEGIN

@class VCSAudioSessionManager;

#pragma mark - 音频会话回调
@protocol VCSAudioSessionManagerDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 音频路由变更回调
/// 音频路由变更回调
/// @param manager 音频会话实例
/// @param route 音频路由
/// @param routeName 音频路由名称
/// @param previousRoute 变更前的音频路由
/// @param previousRouteName 变更前的音频路由名称
- (void)audioSessionDidChangeRoute:(VCSAudioSessionManager *)manager route:(VCSAudioRoute)route routeName:(NSString *)routeName previousRoute:(VCSAudioRoute)previousRoute previousRouteName:(NSString *)previousRouteName;

@end

@interface VCSAudioSessionManager : NSObject

/// 音频会话代理
@property (nonatomic, weak) id<VCSAudioSessionManagerDelegate> delegate;

/// 有线耳机是否可用
@property (nonatomic, assign, readonly) BOOL headphoneDeviceAvailable;
/// 蓝牙耳机是否可用
@property (nonatomic, assign, readonly) BOOL bluetoothDeviceAvailable;

#pragma mark 获取音频会话单例
/// 获取音频会话单例
+ (VCSAudioSessionManager *)sharedManager;

#pragma mark 音频会话配置
/// 音频会话配置
- (void)setupAudioSession;

#pragma mark 设置音频路由
/// 设置音频路由
/// - Parameter route: 音频路由
- (void)setAudioRoute:(VCSAudioRoute)route;

#pragma mark 获取当前音频路由
/// 获取当前音频路由
- (VCSAudioRoute)currentAudioRoute;

#pragma mark 获取音频路由列表
/// 获取音频路由列表
- (NSArray<VCSAudioRouteModel *> *)getAvailableAudioRoutes;

#pragma mark 释放音频会话
/// 释放音频会话
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
