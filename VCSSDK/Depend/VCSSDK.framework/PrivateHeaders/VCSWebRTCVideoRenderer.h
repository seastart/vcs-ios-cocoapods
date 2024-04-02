//
//  VCSWebRTCVideoRenderer.h
//  VCSSDK
//
//  Created by SailorGa on 2023/10/27.
//

#import <WebRTC/WebRTC.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSWebRTCVideoRenderer;

#pragma mark - 渲染数据回调
@protocol VCSWebRTCVideoRendererDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 画面尺寸回调
/// 画面尺寸回调
/// - Parameters:
///   - renderer: 渲染器实例
///   - size: 尺寸
- (void)renderer:(VCSWebRTCVideoRenderer *)renderer didRendererSize:(CGSize)size;

#pragma mark 渲染视频数据回调
/// 渲染视频数据回调
/// - Parameters:
///   - renderer: 渲染器实例
///   - frame: 视频数据
- (void)renderer:(VCSWebRTCVideoRenderer *)renderer didRendererVideoFrame:(RTCVideoFrame *)frame;

@end

@interface VCSWebRTCVideoRenderer : NSObject <RTCVideoRenderer>

#pragma mark 创建渲染器
/// 创建渲染器
/// - Parameter delegate: 代理委托
- (instancetype)initWithDelegate:(id <VCSWebRTCVideoRendererDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
