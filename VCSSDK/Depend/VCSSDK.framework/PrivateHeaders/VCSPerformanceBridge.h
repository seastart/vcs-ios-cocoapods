//
//  VCSPerformanceBridge.h
//  VCSSDK
//
//  Created by SailorGa on 2021/1/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VCSPerformanceBridge : NSObject

#pragma mark - 获取应用程序内存占用情况
/// 获取应用程序内存占用情况
+ (double)getApplicationMemory;

#pragma mark - 获取应用程序CPU占有率
/// 获取应用程序CPU占有率
+ (double)getApplicationCPU;

#pragma mark - 获取系统内存占用情况
/// 获取系统内存占用情况
+ (double)getSystemMemory;

#pragma mark - 获取系统CPU占有率
/// 获取系统CPU占有率
+ (double)getSystemCPU;

#pragma mark - 获取设备全部内存
/// 获取设备全部内存
+ (double)getAllMemory;

@end

NS_ASSUME_NONNULL_END
