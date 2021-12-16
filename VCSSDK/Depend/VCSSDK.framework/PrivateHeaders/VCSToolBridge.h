//
//  VCSToolBridge.h
//  VCSSDK
//
//  Created by SailorGa on 2020/5/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VCSToolBridge : NSObject

/// 初始化方法
+ (VCSToolBridge *)sharedManager;

/// 检测当前App是否在后台
- (BOOL)applicationStateBackground;

/// 检测是否开启了相机权限
/// @param resultBlock 检测结果
- (void)checkCameraAuthorizationWithResultBlock:(void (^)(BOOL result))resultBlock;

/// 字典转Json字符串
/// @param dict 字典数据
- (NSString *)convertToJsonData:(NSDictionary *)dict;

#pragma mark - 获取数据的十六进制字符串
/// 获取数据的十六进制字符串
/// @param data 格式化数据
- (NSString *)getHexStringForData:(NSData *)data;

#pragma mark - 分割字符串
/// 分割字符串
/// @param string 目标字符串
/// @param seprate 分隔符
- (NSMutableArray *)stringToArray:(NSString *)string seprate:(NSString *)seprate;

#pragma mark - 获取唯一标识符UUID
/// 获取唯一标识符UUID
- (NSString *)getUniqueIdentifier;

#pragma mark - 域名解析IP地址
/// 域名解析IP地址
/// @param domain 域名地址
- (NSString *)localDomainParsing:(NSString *)domain;

#pragma mark - 获取当前时间(精确到毫秒)
/// 获取当前时间(精确到毫秒)
- (NSTimeInterval)getTimeInterval;

#pragma mark - 判断应用是否在Mac上运行
/// 判断应用是否在Mac上运行
- (BOOL)isiOSAppOnMac;

@end

NS_ASSUME_NONNULL_END
