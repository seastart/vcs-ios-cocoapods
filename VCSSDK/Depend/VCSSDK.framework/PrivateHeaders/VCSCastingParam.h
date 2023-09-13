//
//  VCSCastingParam.h
//  VCSSDK
//
//  Created by SailorGa on 2023/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSStreamSendModel;

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


#pragma mark - 投屏状态
/**
 投屏状态
 
 - VCSCastingStatusNormal: 默认状态
 - VCSCastingStatusAccept: 允许投屏
 - VCSCastingStatusRefuse: 拒绝投屏
 - VCSCastingStatusFailed: 投屏失败
 - VCSCastingStatusWarning: 投屏预警
 */
typedef enum : NSUInteger {
    
    VCSCastingStatusNormal = -1,
    VCSCastingStatusAccept = 0,
    VCSCastingStatusRefuse = 1,
    VCSCastingStatusFailed = 2,
    VCSCastingStatusWarning = 3
} VCSCastingStatus;


#pragma mark - 溢出状态
/**
 溢出状态
 
 - VCSOverflowStatusNormal: 默认状态
 - VCSOverflowStatusIntermit: 中断状态
 - VCSOverflowStatusRecover: 恢复状态
 */
typedef enum : NSUInteger {
    
    VCSOverflowStatusNormal = 0,
    VCSOverflowStatusIntermit = 1,
    VCSOverflowStatusRecover = 2
} VCSOverflowStatus;


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
/// 视频上传速率(单位kps)
@property (nonatomic, copy) NSString *speed;
/// 音频上传速率(单位kps)
@property (nonatomic, copy) NSString *audio_speed;
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
/// 投屏地址
@property (nonatomic, copy) NSString *domain;
/// 用户名称
@property (nonatomic, copy) NSString *username;
/// 媒体流是否启用加密，默认 NO
@property (nonatomic, assign) BOOL enableEncrypt;

#pragma mark - ---- 编码配置参数 ----
/// 编码宽度，默认720
@property (nonatomic, assign) int encoderWidth;
/// 编码高度，默认1280
@property (nonatomic, assign) int encoderHeight;
/// 编码帧率，默认20
@property (nonatomic, assign) int framerate;

#pragma mark - ---- 调试模式参数 ----
/// 远程调试地址
@property (nonatomic, copy, nullable) NSString *debugHost;
/// 保存视频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveVideo;
/// 保存音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudio;

@end


#pragma mark - 通讯指令父类定义
@interface VCSCastingSignalingBaseModel : NSObject

/// 指令类型(指示包用途，如：发起投屏、心跳等)
@property (nonatomic, copy) NSString *action;
/// 数据包类型(指示包类型，如：请求、响应等)
@property (nonatomic, copy) NSString *type;
/// 消息编号
@property (nonatomic, copy) NSString *seq;
/// 平台类型
@property (nonatomic, assign) NSInteger terminalType;

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

/// 当前时间戳
@property (nonatomic, assign) NSInteger timetick;
/// ping指令凑包数据
@property (nonatomic, assign) NSString *ext;
/// 调试信息
@property (nonatomic, assign) NSString *info;

@end


NS_ASSUME_NONNULL_END
