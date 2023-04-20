//
//  VCSCastingParam.h
//  VCSSDK
//
//  Created by SailorGa on 2023/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSStreamSendModel;


#pragma mark - 网络延时抗抖动等级
/**
 网络延时抗抖动等级
 
 - VCSNetworkQosShakeLevelUltraShort: 超短(0) 单向延迟120ms左右 这种模式下没有丢包补偿机制 并且编码关闭了B帧 一般不建议实际使用
 - VCSNetworkQosShakeLevelShort: 短(1) 单向延迟200ms左右 单次丢包补偿 B帧为1 双向对讲环境下可以使用
 - VCSNetworkQosShakeLevelMedium: 中(2) 单向延迟350ms左右 两次丢包补偿 B帧为1 双向对讲环境下推荐使用
 - VCSNetworkQosShakeLevelLong: 长(3) 单向延迟600ms左右 三次丢包补偿 B帧为3 这种模式仅用于单向收看 双向对讲环境下不建议使用 该参数无法动态设置
 */
typedef enum : NSInteger {
    
    VCSNetworkQosShakeLevelUltraShort = 0,
    VCSNetworkQosShakeLevelShort = 1,
    VCSNetworkQosShakeLevelMedium = 2,
    VCSNetworkQosShakeLevelLong = 3
} VCSNetworkQosShakeLevel;

#pragma mark - 上行码率自适应状态
/**
 上行码率自适应状态
 
 - VCSCastingBitrateAdaptiveStateStart: 码率自适应开始工作
 - VCSCastingBitrateAdaptiveStateNormal: 码率恢复到最初设置
 - VCSCastingBitrateAdaptiveStateHalf:  码率变为原来的一半
 - VCSCastingBitrateAdaptiveStateQuarter: 码率变为原来的四分之一
 - VCSCastingBitrateAdaptiveStateVeryBad: 当前网络环境及其差劲情况
 */
typedef enum : NSInteger {
    
    VCSCastingBitrateAdaptiveStateStart = 1000,
    VCSCastingBitrateAdaptiveStateNormal = 0,
    VCSCastingBitrateAdaptiveStateHalf = -1,
    VCSCastingBitrateAdaptiveStateQuarter = -2,
    VCSCastingBitrateAdaptiveStateVeryBad = -3,
} VCSCastingBitrateAdaptiveState;

#pragma mark - 投屏采集状态
/**
 投屏采集状态
 
 - VCSCastingScreenStatusNormal: 投屏常规状态
 - VCSCastingScreenStatusError: 投屏连接错误
 - VCSCastingScreenStatusStop: 投屏已经停止
 - VCSCastingScreenStatusStart: 投屏已经开始
 */
typedef enum : NSInteger {
    
    VCSCastingScreenStatusNormal = 1000,
    VCSCastingScreenStatusError = -1,
    VCSCastingScreenStatusStop = 0,
    VCSCastingScreenStatusStart = 1
} VCSCastingScreenStatus;

#pragma mark - 编码类型
/**
 编码类型
 
 - VCSCodecTypeAAC: AAC
 - VCSCodecTypeOPUS: OPUS
 */
typedef enum : NSUInteger {
    
    VCSCodecTypeAAC = 0,
    VCSCodecTypeOPUS = 0x5355504F
} VCSCodecType;

#pragma mark - 投屏状态
/**
 投屏状态
 
 - VCSCastingStatusNormal: 默认状态
 - VCSCastingStatusAccept: 允许投屏
 - VCSCastingStatusRefuse: 拒绝投屏
 */
typedef enum : NSUInteger {
    
    VCSCastingStatusNormal = -1,
    VCSCastingStatusAccept = 0,
    VCSCastingStatusRefuse = 1
} VCSCastingStatus;


#pragma mark - 流媒体发送状态信息列表
@interface VCSStreamSendStatus : NSObject

@property (nonatomic, copy) NSArray <VCSStreamSendModel *> *uploadinfo;

@end


#pragma mark - 流媒体发送状态信息
@interface VCSStreamSendModel : NSObject

/// 上传缓冲包数
@property (nonatomic, assign) int buffer;
/// 上传延迟
@property (nonatomic, assign) int delay;
/// 溢出缓冲包数
@property (nonatomic, assign) int overflow;
/// 上传速率(单位kps)
@property (nonatomic, copy) NSString *speed;
/// 上传状态
@property (nonatomic, assign) NSInteger status;
/// 补偿前丢包率
@property (nonatomic, assign) float loss_r;
/// 补偿后丢包率
@property (nonatomic, assign) float loss_c;

@end


#pragma mark - 流媒体配置参数
@interface VCSCastingMediaConfig : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

#pragma mark - ---- 常规配置参数 ----
/// 流媒体地址
@property (nonatomic, copy) NSString *streamHost;
/// 流媒体端口
@property (nonatomic, copy) NSString *streamPort;
/// 成员标识
@property (nonatomic, copy) NSString *linkId;
/// 房间凭证
@property (nonatomic, copy) NSString *session;
/// 房间号码
@property (nonatomic, copy) NSString *roomNo;
/// 设备标识
@property (nonatomic, copy) NSString *deviceId;


#pragma mark - ---- 网络质量参数 ----
/// 接收自适应延迟二档位，默认 500
@property (nonatomic, assign) int secondGear;
/// 接收自适应延迟三档位，默认 1200
@property (nonatomic, assign) int thirdGear;

/// 获取云端音频数据信息周期，默认为500毫秒
@property (nonatomic, assign) float onAudioCycle;

/// 开启硬件解码 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isHardwarede;
/// 开启网络自适应延迟 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isNetworkAdaptive;
/// 开启码率自适应 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isBitrateAdaptive;

/// 网络延时抗抖动等级，默认VCSNetworkQosShakeLevelMedium
@property (nonatomic, assign) VCSNetworkQosShakeLevel shakeLevel;


#pragma mark - ---- 调试模式参数 ----
/// 远程调试地址
@property (nonatomic, copy, nullable) NSString *debugHost;
/// 保存视频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveVideo;
/// 保存采集音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioCapture;
/// 保存远程音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioReceive;


#pragma mark - ---- 高阶配置参数 ----
/// 回声消除AEC，默认12
@property (nonatomic, assign) int aec;
/// 自动增益控制AGC，默认16000
@property (nonatomic, assign) int agc;
/// 音频采样率，默认48000
@property (nonatomic, assign) int audioSampe;
/// 音频编码格式，默认AAC
@property (nonatomic, assign) VCSCodecType audioEncode;

@end


#pragma mark - 通讯指令父类定义
@interface VCSCastingSignalingBaseModel : NSObject

/// 指令类型(指示包用途，如：发起投屏、心跳等)
@property (nonatomic, copy) NSString *action;
/// 数据包类型(指示包类型，如：请求、响应等)
@property (nonatomic, copy) NSString *type;
/// 消息编号
@property (nonatomic, copy) NSString *seq;

@end


#pragma mark - 通讯指令对象定义
@interface VCSCastingSignalingModel : VCSCastingSignalingBaseModel

/// 发送者标识
@property (nonatomic, copy) NSString *senderId;
/// 发送者名称
@property (nonatomic, copy) NSString *senderName;

/// 错误码(如：发起投屏时，0-接受 1-拒绝)
@property (nonatomic, assign) VCSCastingStatus status;

/// 目标标识
@property (nonatomic, copy) NSString *targetId;
/// 附加数据
@property (nonatomic, copy) NSString *extra;

@end


NS_ASSUME_NONNULL_END
