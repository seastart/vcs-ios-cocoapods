//
//  VCSPerformanceBridge.h
//  VCSSDK
//
//  Created by SailorGa on 2021/1/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VCSPerformanceBridge : NSObject

/// 初始化方法
+ (VCSPerformanceBridge *)sharedManager;

#pragma mark - 获取当前应用的内存占用情况
/// 获取当前应用的内存占用情况
- (double)getMemoryUsage;

#pragma mark - 获取当前应用CPU占有率
/// 获取当前应用在CPU中的占有率
- (double)getCpuUsage;

@end

NS_ASSUME_NONNULL_END
