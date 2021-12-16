//
//  VCSPushManager.h
//  VCSSDK
//
//  Created by SailorGa on 2021/3/22.
//

#import <Foundation/Foundation.h>
#import <GTSDK/GeTuiSdk.h>
#import "VCSPushManagerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface VCSPushManager : NSObject

#pragma mark - -------- 推送服务基础接口 ---------
#pragma mark 单例模式获取推送服务实例
/// 单例模式获取推送服务实例
+ (VCSPushManager *)sharedManager;

#pragma mark 获取推送服务版本号
/// 获取推送服务版本号
- (NSString *)version;

#pragma mark 获取推送服务版本信息
/// 获取推送服务版本信息
- (NSString *)getVersionInfo;

#pragma mark 启动推送服务
/// 启动推送服务
/// @param appId 设置App的个推AppId，此AppId从个推网站获取
/// @param appKey 设置App的个推AppKey，此AppKey从个推网站获取
/// @param appSecret 设置App的个推AppSecret，此AppSecret从个推网站获取
/// @param delegate 回调代理Delegate
- (void)startPushWithAppId:(NSString *)appId appKey:(NSString *)appKey appSecret:(NSString *)appSecret delegate:(id <VCSPushManagerProtocol>)delegate;

#pragma mark 销毁释放推送服务资源
/// 销毁释放推送服务资源
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
