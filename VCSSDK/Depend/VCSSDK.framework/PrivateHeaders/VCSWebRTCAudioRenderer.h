//
//  VCSWebRTCAudioRenderer.h
//  VCSSDK
//
//  Created by SailorGa on 2023/10/27.
//

#import <WebRTC/WebRTC.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSWebRTCAudioRenderer;

#pragma mark - 渲染数据回调
@protocol VCSWebRTCAudioRendererDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 渲染音频数据回调
/// 渲染音频数据回调
/// - Parameters:
///   - renderer: 渲染器实例
///   - sampleBuffer: 音频数据
- (void)renderer:(VCSWebRTCAudioRenderer *)renderer didRenderSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end

@interface VCSWebRTCAudioRenderer : NSObject <RTCAudioRenderer>

#pragma mark 创建渲染器
/// 创建渲染器
/// - Parameter delegate: 代理委托
- (instancetype)initWithDelegate:(id <VCSWebRTCAudioRendererDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
