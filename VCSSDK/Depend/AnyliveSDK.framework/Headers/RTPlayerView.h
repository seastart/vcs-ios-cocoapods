//
//  RTPlayerView.h
//  AnyliveSDK
//
//  Created by huangkexing on 2019/4/25.
//  Copyright © 2019年 huangkexing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol RTPlayerViewDelegate<NSObject>
-(void)viewtouchtag:(CGFloat)tag tapcount:(int)tapCount; //单击暴露
@end
@interface RTPlayerView : UIView
{
}
#pragma mark - 接口
//显示RGB 这里中已有Yframe  Uframe=NULL Vframe=NULL
- (void)displayRGBData:(void *)Yframe Uframe:(void*)Uframe Vframe:(void*)Vframe width:(NSInteger)w height:(NSInteger)h;
- (void)setVideoSize:(GLuint)width height:(GLuint)height;
- (void)clearFrame;
- (void)ZoomFull:(BOOL)zooml;//是否全屏显示，如果全屏那么需要计算坐标
- (void)SetScal:(BOOL)scal;//YES: 加黑边，否则不加黑边
- (void)SetLayoutReset:(BOOL)set;//YES 计算
@property (weak, nonatomic) id<RTPlayerViewDelegate>delegate;
@property(nonatomic, assign) int windowWidth;
@property(nonatomic, assign) int windowHeight;
@property(nonatomic,assign)int tmpWindowsWidth;
@property(nonatomic,assign)int tmpWindowsHeight;

@property(nonatomic,assign)int dWidth;//归一化大小
@property(nonatomic,assign)int dHeight;//归一化大小
@property(nonatomic,assign)int srcWidth;//原始大小
@property(nonatomic,assign)int srcHeight;//原始大小
@property(nonatomic,assign)int tmpVideoWidth;
@property(nonatomic,assign)int tmpVideoHeight;
@property(nonatomic,assign)BOOL scal;// YES center_inside  NO:center_grop
@property(nonatomic,assign)BOOL resetLayout;//重新计算
@end
