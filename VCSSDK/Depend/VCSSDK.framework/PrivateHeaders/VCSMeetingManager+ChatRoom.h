//
//  VCSMeetingManager+ChatRoom.h
//  VCSSDK
//
//  Created by SailorGa on 2020/5/11.
//

#import "VCSMeetingManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface VCSMeetingManager(ChatRoom)

#pragma mark - 更新房间成员列表
/// 更新房间成员列表
/// - Parameter accountArray: 成员列表
- (void)onRoomMembersUpdate:(nullable NSArray<Account *> *)accountArray;

@end

NS_ASSUME_NONNULL_END
