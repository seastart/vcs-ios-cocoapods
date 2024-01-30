//
//  VCSWebRTCNetwork.h
//  VCSSDK
//
//  Created by SailorGa on 2023/10/9.
//

#import <Foundation/Foundation.h>
#import "VCSWebRTCObjects.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^VCSHttpResultBlock)(BOOL isSuccess, id _Nullable result, NSString * _Nullable errorMsg);

@interface VCSWebRTCNetwork : NSObject

/// 初始化方法
+ (VCSWebRTCNetwork *)sharedManager;

/// POST方法
/// @param api 请求短连接
/// @param params 请求参数
/// @param className  Model对象
/// @param resultBlock 结果返回
- (void)POST:(NSString *)api params:(nullable NSDictionary *)params className:(NSString *)className resultBlock:(VCSHttpResultBlock)resultBlock;

@end

NS_ASSUME_NONNULL_END
