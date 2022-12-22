//
//  VCSMeetingBaseModel.h
//  VCSSDK
//
//  Created by SailorGa on 2022/12/19.
//

#import "SGJSONModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface VCSMeetingBaseModel : SGJSONModel

/// 错误码
@property (nonatomic, assign) NSInteger code;
/// 错误信息
@property (nonatomic, copy) NSString *msg;

/// 构建对象
/// - Parameter dict: 字典数据
- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
