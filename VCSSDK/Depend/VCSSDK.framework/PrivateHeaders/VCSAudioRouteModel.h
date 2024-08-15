//
//  VCSAudioRouteModel.h
//  VCSSDK
//
//  Created by SailorGa on 2024/4/23.
//

#import <Foundation/Foundation.h>
#import "VCSCommons.h"

NS_ASSUME_NONNULL_BEGIN

@interface VCSAudioRouteModel : NSObject

/// 音频路由标识
@property (nonatomic, copy, nullable) NSString *identifier;
/// 音频路由
@property (nonatomic, assign) VCSAudioRoute route;
/// 音频路由名称
@property (nonatomic, copy, nullable) NSString *routeName;

/// 初始化音频路由对象
/// - Parameters:
///   - identifier: 音频路由标识
///   - route: 音频路由类型
///   - routeName: 音频路由名称
- (instancetype)initWithIdentifier:(nullable NSString *)identifier route:(VCSAudioRoute)route routeName:(nullable NSString *)routeName;

@end

NS_ASSUME_NONNULL_END
