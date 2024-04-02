//
//  VCSRedirectManager.h
//  VCSSDK
//
//  Created by SailorGa on 2023/11/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VCSRedirectManager : NSObject

#pragma mark 获取日志重定向单例
/// 获取日志重定向单例
+ (VCSRedirectManager *)sharedManager;

#pragma mark 启动日志重定向
/// 启动日志重定向
- (void)startService;

#pragma mark 获取日志文件名称
/// 获取日志文件名称
- (NSString *)getFolderName;

#pragma mark 获取日志文件路径
/// 获取日志文件路径
- (NSString *)getFilePath;

#pragma mark 停止日志重定向
/// 停止日志重定向
- (void)stopService;

@end

NS_ASSUME_NONNULL_END
