//
//  VCSMeetingNetworkHelper.h
//  VCSSDK
//
//  Created by SailorGa on 2022/12/19.
//

#import <AFNetworking/AFNetworking.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^NetworkResultBlock)(BOOL result, id _Nullable data, NSString * _Nullable errorMsg);

@interface VCSMeetingNetworkHelper : NSObject

#pragma mark - 获取网络工具对象
/// 获取网络工具对象
+ (VCSMeetingNetworkHelper *)networkHelper;

#pragma mark - 设置域名地址
/// 设置域名地址
/// - Parameters:
///   - domainUrl: 域名地址
///   - appId: 应用标识
///   - appKey: 应用密钥
- (void)setupDomainUrl:(NSString *)domainUrl appId:(NSString *)appId appKey:(NSString *)appKey;

#pragma mark - 设置用户令牌
/// 设置用户令牌
/// - Parameter token: 用户令牌
- (void)setupUserToken:(nullable NSString *)token;

#pragma mark - 发起GET请求
/// 发起GET请求
/// - Parameters:
///   - url: 请求接口
///   - params: 请求参数
///   - className: 结果对象
///   - resultBlock: 请求回调
- (void)GET:(NSString *)url params:(nullable NSDictionary *)params className:(nullable NSString *)className resultBlock:(NetworkResultBlock)resultBlock;

#pragma mark - 发起POST请求
/// 发起POST请求
/// - Parameters:
///   - url: 请求接口
///   - params: 请求参数
///   - className: 结果对象
///   - resultBlock: 请求回调
- (void)POST:(NSString *)url params:(nullable NSDictionary *)params className:(nullable NSString *)className resultBlock:(NetworkResultBlock)resultBlock;

@end

NS_ASSUME_NONNULL_END
