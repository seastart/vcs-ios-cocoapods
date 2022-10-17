//
//  RTYUVPlayer.h
//  AnyliveSDK
//
//  Created by huangkexing on 2019/8/15.
//  Copyright © 2019年 huangkexing. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



@protocol RTYUVPlayerDelegate<NSObject>
-(void)viewtouchtag:(CGFloat)tag tapcount:(int)tapCount; //单击暴露
@end
@interface RTYUVPlayer : UIView
{
}
//@property(nonatomic,assign)BOOL mrender;
#pragma mark - 接口
// track:视频轨道 type:[0 I420 ,1 NV12 2 NV21]
- (int)displayYUVData:(int)track type:(int)type lable:(int)lable width:(int)width height:(int)height yData:(void *)yData uData:(void*)uData vData:(void*)vData;
-(void)SetLayoutReset:(BOOL)set;//YES 计算

//视图控制
/**
   * 改变绘图坐标系的偏移值
   */
-(void)move:(float)dx dy:(float)dy;

  /**
   * 缩放视图
   */
-(void)zoom:(float)scale;

-(void)directZoom:(float)scale;
-(float)getCurrentScale;
/**
 * 设置旋转角度 如果设置了 那么将会使用该角度 默认角度是0度，恢复到默认可以设置为0
 */
-(void)setViewRotate:(int)rotateAngle;

/**
 * 设置显示翻转 默认都是不翻转
 */
-(void)setViewflip:(BOOL)flipX flipY:(BOOL)flipY;
/**
 * 设置view scaleType，scaleType 请看VCS_EVENT_TYPE 中的定义。 默认为 CENTERINSIDE
 */

-(void)setViewScaleType:(int)ScaleType;
/**
 * 是否使用自定义显示控制模式。默认不使用。当使用自定义方式时【setViewScaleType，setViewflip，setViewRotate 起作用】
 */
-(void)customDisplayCtrl:(BOOL)use;
/**
 * 视图是否可移动 默认不可以移动或者缩放 open=false 恢复到默认的状态
 */
-(void)openViewZoomAndMove:(BOOL) open;

/**
   * 默认使用内部的Touch
   */
-(void)useMyControl:(BOOL)use;
/**
* 清除像素
*/
-(void)cleanpixels;
/**
 display CVPixelBufferRef[YUV]
 */
-(int)displayCVPixleBuffer:(CVPixelBufferRef)pixelbuffer;

-(void)ReleasePlay;
-(void)renderFinish;
//
@property (weak, nonatomic) id<RTYUVPlayerDelegate>delegate;

@end
