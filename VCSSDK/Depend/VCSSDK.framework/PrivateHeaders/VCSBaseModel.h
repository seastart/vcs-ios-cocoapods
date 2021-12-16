//
//  VCSBaseModel.h
//  VCSSDK
//
//  Created by SailorGa on 2021/7/4.
//

#import "SGJSONModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface VCSBaseModel : SGJSONModel

/// 重载父类init
/// @param dict 字典数据
- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
