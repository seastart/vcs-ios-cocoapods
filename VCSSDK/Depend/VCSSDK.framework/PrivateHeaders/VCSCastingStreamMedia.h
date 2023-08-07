//
//  VCSCastingStreamMedia.h
//  VCSSDK
//
//  Created by SailorGa on 2023/4/17.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSSDK/VCSSDK.h>)
#import <VCSSDK/VCSCastingParam.h>
#else
#import "VCSCastingParam.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSCastingStreamMedia;

#pragma mark - 流媒体回调代理
@protocol VCSCastingStreamMediaDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 流媒体发送状态数据回调
/// 流媒体发送状态数据回调
/// @param stream 流媒体实例
/// @param sendModel 流媒体发送状态数据
- (void)streamMedia:(VCSCastingStreamMedia *)stream onSendStreamModel:(VCSStreamSendModel *)sendModel;

#pragma mark 流媒体溢出状态回调
/// 流媒体溢出状态回调
/// @param stream 流媒体实例
/// @param status 溢出状态
- (void)streamMedia:(VCSCastingStreamMedia *)stream didChangeOverflowStatus:(VCSOverflowStatus)status;

#pragma mark 流媒体连接结果回调
/// 流媒体连接结果回调
/// @param stream 流媒体实例
/// @param succeed 是否成功
- (void)streamMedia:(VCSCastingStreamMedia *)stream didConnectFinish:(BOOL)succeed;

@end

/// 释放完成回调
typedef void (^VCSCastingStreamMediaDestroyBlock)(void);

#pragma mark - VCSCastingStreamMedia
@interface VCSCastingStreamMedia : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

#pragma mark 获取流媒体实例
/// 获取流媒体实例
+ (VCSCastingStreamMedia *)sharedInstance;

#pragma mark 流媒体版本
/// 流媒体版本
- (NSString *)version;

#pragma mark 初始化流媒体
/// 初始化流媒体
/// @param mediaConfig 配置参数
/// @param linkId 用户标识
/// @param delegate 代理回调
- (void)initializeStreamMediaWithMediaConfig:(VCSCastingMediaConfig *)config linkId:(NSString *)linkId delegate:(nullable id <VCSCastingStreamMediaDelegate>)delegate;

#pragma mark 发布投屏视频流
/// 发布投屏视频流
/// @param streamData 投屏视频流数据
/// @param stamp 显示时间戳
/// @param dts 解码时间戳
/// @param displayAngle 显示角度
/// @param keyframe 是否为关键帧
- (void)publishScreenVideoWithStreamData:(NSData *)streamData stamp:(uint32_t)stamp dts:(uint32_t)dts displayAngle:(int)displayAngle keyframe:(BOOL)keyframe;

#pragma mark 发布投屏音频流
/// 发布投屏音频流
/// @param streamData 投屏音频流数据
/// @param stamp 显示时间戳
/// @param dts 解码时间戳
- (void)publishScreenAudioWithStreamData:(NSData *)streamData stamp:(uint32_t)stamp dts:(uint32_t)dts;

#pragma mark 资源销毁
/// 资源销毁
/// @param finishBlock 完成回调
- (void)destroy:(nullable VCSCastingStreamMediaDestroyBlock)finishBlock;

@end

NS_ASSUME_NONNULL_END
