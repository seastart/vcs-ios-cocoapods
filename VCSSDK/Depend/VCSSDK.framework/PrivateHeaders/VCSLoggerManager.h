//
//  VCSLoggerManager.h
//  VCSSDK
//
//  Created by SailorGa on 2022/9/26.
//

#import <Foundation/Foundation.h>
#import "VCSLoggerObjects.h"

NS_ASSUME_NONNULL_BEGIN

@class VCSLoggerManager;

#pragma mark - 日志事件回调
@protocol VCSLoggerManagerDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 行为日志扩展事件回调
/// 行为日志扩展事件回调
/// - Parameters:
///   - manager: 日志组件实例
///   - loggerParam: 行为日志对象
- (VCSLoggerItemModel *)loggerManager:(VCSLoggerManager *)manager onLoggerExpand:(VCSLoggerItemModel *)itemModel;

#pragma mark 实时日志扩展事件回调
/// 实时日志扩展事件回调
/// - Parameters:
///   - manager: 日志组件实例
///   - object: 实时日志对象
- (VCSMetricItemModel *)loggerManager:(VCSLoggerManager *)manager onMetricExpand:(VCSMetricItemModel *)itemModel;

@end

#pragma mark - VCSLoggerManager
@interface VCSLoggerManager : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 日志事件代理
@property (nonatomic, weak) id<VCSLoggerManagerDelegate> delegate;

#pragma mark 获取日志组件实例
/// 获取日志组件实例
+ (VCSLoggerManager *)sharedManager;

#pragma mark 日志组件版本
///  日志组件版本
- (NSString *)version;

#pragma mark 启动日志服务
/// 启动日志服务
/// - Parameters:
///   - domainUrl: 服务地址
///   - delegate: 日志代理
- (void)startLogger:(NSString *)domainUrl delegate:(nullable id <VCSLoggerManagerDelegate>)delegate;

#pragma mark 追加行为日志
/// 追加行为日志
/// - Parameter param: 行为日志参数
- (void)appendLoggerWithParam:(VCSLoggerParam *)param;

#pragma mark 追加实时日志
/// 追加实时日志
/// - Parameter param: 实时日志对象
- (void)appendMetricWithItemModel:(VCSMetricItemModel *)itemModel;

@end

NS_ASSUME_NONNULL_END
