//
//  ScreenRTCSocket.h
//  hkScreenShared
//
//  Created by rich rich on 28/5/2020.
//  Copyright © 2020 rich rich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import <pthread.h>


#import "ScreenRTCBufferUtil.h"
NS_ASSUME_NONNULL_BEGIN

#define LOCK(lock) pthread_mutex_lock(&(lock));
#define UNLOCK(lock) pthread_mutex_lock(&(lock));;
@interface ScreenRTCConnect : NSObject
- (int)createConnect;
- (NSString *)ip;
- (BOOL)connect;
- (BOOL)bind;
- (BOOL)listen;
- (void)receive;
- (void)recvData;
- (void)close;
- (void)setSendBuffer;
- (void)setRecvBuffer;
- (void)setSendingTimeout;
- (void)setRecvTimeout;
@end

NS_ASSUME_NONNULL_END
