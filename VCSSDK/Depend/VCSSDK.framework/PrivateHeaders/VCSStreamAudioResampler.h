//
//  VCSStreamAudioResampler.h
//  VCSSDK
//
//  Created by SailorGa on 2025/9/11.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

NS_ASSUME_NONNULL_BEGIN

/// 音频重采样完成回调
/// @param resampledData 重采样后的数据（16bit, 16kHz, 单声道）
/// @param samplerate 重采样后的采样率
/// @param channel 重采样后的声道
/// @param error 错误信息，成功时为nil
typedef void (^AudioResampleCompletionBlock)(NSData * _Nullable resampledData, int samplerate, int channel, NSError * _Nullable error);

/// 音频重采样错误域
extern NSErrorDomain const VCSAudioResamplerErrorDomain;

/// 音频重采样错误码
typedef NS_ENUM(NSInteger, VCSAudioResamplerErrorCode) {
    
    VCSAudioResamplerErrorInvalidInput = 1000,
    VCSAudioResamplerErrorConverterInitFailed,
    VCSAudioResamplerErrorInvalidOutputSize,
    VCSAudioResamplerErrorConversionFailed,
    VCSAudioResamplerErrorComplexResamplingRequired,
    VCSAudioResamplerErrorNotEnoughInputData
};

@interface VCSStreamAudioResampler : NSObject

#pragma mark - 获取音频重采样实例
/// 获取音频重采样实例
+ (instancetype)sharedInstance;

#pragma mark - 异步重采样音频数据
/// 异步重采样音频数据
/// - Parameters:
///   - inputData: 输入的PCM音频数据（16bit, 48kHz, 单声道）
///   - completion: 重采样完成回调
- (void)asyncResampleAudio:(NSData *)inputData completion:(AudioResampleCompletionBlock)completion;

#pragma mark - 同步重采样音频数据
/// 同步重采样音频数据
/// - Parameters:
///   - inputData: 输入的PCM音频数据（16bit, 48kHz, 单声道）
///   - error: 错误信息指针
- (NSData *)syncResampleAudio:(NSData *)inputData error:(NSError **)error;

#pragma mark - 计算重采样后的输出数据大小
/// 计算重采样后的输出数据大小
/// - Parameter inputSize: 输入数据的长度（字节数）
- (NSInteger)calculateOutputSize:(NSInteger)inputSize;

#pragma mark - 清理重采样器资源
/// 清理重采样器资源
- (void)cleanup;

@end

NS_ASSUME_NONNULL_END
