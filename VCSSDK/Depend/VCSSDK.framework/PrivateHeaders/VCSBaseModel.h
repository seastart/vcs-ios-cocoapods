//
//  VCSBaseModel.h
//  VCSSDK
//
//  Created by SailorGa on 2021/7/4.
//

#import "SGJSONModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface VCSBaseModel : SGJSONModel

/// 错误码
@property (nonatomic, assign) NSInteger code;
/// 错误信息
@property (nonatomic, copy) NSString *msg;

/// 构建对象
/// - Parameter dict: 字典数据
- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
