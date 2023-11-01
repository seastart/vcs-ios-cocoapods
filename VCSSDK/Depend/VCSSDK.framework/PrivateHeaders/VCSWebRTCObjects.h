//
//  VCSWebRTCObjects.h
//  VCSSDK
//
//  Created by SailorGa on 2023/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSRemoteSDPModel;

@interface VCSWebRTCBaseModel : NSObject

/// 状态码
@property (nonatomic, assign) NSInteger code;
/// 描述信息
@property (nonatomic, copy) NSString *message;

@end

@interface VCSWebRTCRemoteSDPModel : VCSWebRTCBaseModel

/// 远程SDP对象
@property (nonatomic, strong) VCSRemoteSDPModel *remoteSdp;

@end

@interface VCSRemoteSDPModel : VCSWebRTCBaseModel

/// 类型
@property (nonatomic, copy) NSString *type;
/// SDP
@property (nonatomic, copy) NSString *sdp;

@end

@interface VCSWebRTAudioModel : NSObject

/// 码流标识
@property (nonatomic, copy) NSString *streamId;
/// 音频功率
@property (nonatomic, assign) int power;
/// 银屏分贝
@property (nonatomic, assign) int db;

/// 创建远端音频功率对象
/// - Parameters:
///   - streamId: 码流标识
///   - power: 音频功率
///   - db: 音频分贝
- (instancetype)initWithStreamId:(nullable NSString *)streamId power:(int)power db:(int)db;

@end

NS_ASSUME_NONNULL_END
