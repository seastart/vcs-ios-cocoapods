//
//  VCSRoomControlManager.h
//  VCSSDK
//
//  Created by SailorGa on 2022/12/21.
//

#import <Foundation/Foundation.h>
#import "VCSLoginConfig.h"
#import "Models.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

/// 数据请求结果回调
typedef void (^VCSNetworkResultBlock)(BOOL result, id _Nullable data, NSString * _Nullable errorMsg);

@interface VCSRoomControlManager : NSObject

/// 登录配置参数
@property (nonatomic, strong, readonly) VCSLoginConfig *loginConfig;
/// 域名地址
@property (nonatomic, copy, readonly) NSString *domainUrl;
/// 应用标识
@property (nonatomic, copy, readonly) NSString *appId;
/// 应用密钥
@property (nonatomic, copy, readonly) NSString *appKey;
/// 当前令牌
@property (nonatomic, copy, readonly) NSString *token;


#pragma mark - -------- 会议控制基础接口 ---------
#pragma mark 单例模式初始化会议控制务实例
/// 单例模式初始化会议控制务实例
+ (VCSRoomControlManager *)sharedManager;


#pragma mark - -------- 组件公共基础接口 ---------
#pragma mark 通过配置初始化组件
/// 通过配置初始化组件
/// - Parameters:
///   - config: 配置参数
///   - resultBlock: 结果回调
- (void)initializeWithConfig:(VCSLoginConfig *)config resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 通过令牌初始化组件
/// 通过令牌初始化组件
/// - Parameters:
///   - token: 登录令牌
///   - appId: 应用标识
///   - appKey: 应用密钥
///   - domainUrl: 服务地址
- (void)initializeWithToken:(NSString *)token appId:(NSString *)appId appKey:(NSString *)appKey domainUrl:(NSString *)domainUrl;

#pragma mark 更新令牌
/// 更新令牌
/// - Parameters:
///   - token: 登录令牌
- (void)updateToken:(nullable NSString *)token;


#pragma mark - -------- 会议控制相关接口 ---------
#pragma mark 踢出指定成员
/// 踢出指定成员
/// @param targetId 目标成员标识
/// @param reenter 是否允许再次进入
/// @param resultBlock 结果回调
- (void)kickoutMemberWithTargetId:(NSString *)targetId reenter:(BOOL)reenter resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 转移主持人权限给指定成员
/// 转移主持人权限给指定成员
/// @param targetId 目标成员标识
/// @param resultBlock 结果回调
- (void)moveRoomHostWithTargetId:(NSString *)targetId resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 回收指定成员房间主持人权限
/// 回收指定成员房间主持人权限
/// @param targetId 目标成员标识
/// @param resultBlock 结果回调
- (void)recoveryRoomHostWithTargetId:(nullable NSString *)targetId resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 设置/取消指定成员联席主持人权限
/// 设置/取消指定成员联席主持人权限
/// @param targetId 目标成员标识
/// @param state 设置状态(YES-设置 NO-回收)
/// @param resultBlock 结果回调
- (void)setupRoomUnionHostWithTargetId:(NSString *)targetId state:(BOOL)state resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 设置房间音频状态
/// 设置房间音频状态
/// @param state 音频状态
/// @param resultBlock 结果回调
- (void)setupRoomAudioStateWithState:(DeviceState)state resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 设置房间视频状态
/// 设置房间视频状态
/// @param state 视频状态
/// @param resultBlock 结果回调
- (void)setupRoomVideoStateWithState:(DeviceState)state resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 变更房间内成员的昵称
/// 变更房间内成员的昵称
/// @param targetId 目标成员标识
/// @param nickname 新昵称
/// @param resultBlock 结果回调
- (void)changeMemberNicknameWithTargetId:(NSString *)targetId nickname:(NSString *)nickname resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 变更房间内自己的昵称
/// 变更房间内自己的昵称
/// - Parameters:
///   - nickname: 新昵称
///   - resultBlock: 结果回调
- (void)changeSelvesNickname:(NSString *)nickname resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 变更房间内自己的音频状态
/// 变更房间内自己的音频状态
/// - Parameters:
///   - audioState: 音频状态
///   - resultBlock: 结果回调
- (void)changeSelvesAudioState:(DeviceState)audioState resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

#pragma mark 变更房间内自己的视频状态
/// 变更房间内自己的视频状态
/// - Parameters:
///   - videoState: 视频状态
///   - resultBlock: 结果回调
- (void)changeSelvesVideoState:(DeviceState)videoState resultBlock:(nullable VCSNetworkResultBlock)resultBlock;

@end

NS_ASSUME_NONNULL_END
