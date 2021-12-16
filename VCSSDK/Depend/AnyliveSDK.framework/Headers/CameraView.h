//
//  CameraView.h
//  AnyliveSDK
//
//  Created by huangkexing on 2019/8/14.
//  Copyright © 2019年 huangkexing. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>

#define kFCScreenWidth  ([UIScreen mainScreen ].bounds.size.width)
#define kFCScreenHeight ([UIScreen mainScreen ].bounds.size.height)
#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define GXFileManager          [NSFileManager defaultManager]
#define degreesToRadians(x) (M_PI*(x)/180.0)//弧度aq
#define random(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)/255.0]
#define randomColor random(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256), 255.0)
#define kFaceUColor [UIColor colorWithRed:66 / 255.0 green:222 / 255.0 blue:182 / 255.0 alpha:1]
#define kMARGap 10.0
#define kMARSwitchW 30
@protocol CameraViewDelegate<NSObject>
//采集出来的实际数据
-(void)VideoOutPut:(CVPixelBufferRef)pixelBuffer videoW:(int)videoWidth videH:(int)videoHeight stamp:(CMTime)stamp;
//layout 单击 双击
-(void)ViewTouchTag:(CGFloat)tag tapcount:(int)tapCount;
@end
@interface CameraView : UIView
{
    CALayer *_focusLayer;
    CGSize outpoutSize;
    BOOL flash;
    int outvideoWidth;
    int outvideoHeight;
    BOOL recording;
    NSString*resolustion;
    BOOL islandscape;
}
@property (nonatomic, weak) id<CameraViewDelegate> delegate;
@property(nonatomic,assign)BOOL stop;
@property(readwrite,nonatomic)UIInterfaceOrientation outputImageOrientation;//默认 UIInterfaceOrientationPortrait; //竖屏显示
@property(readwrite,nonatomic)BOOL horizontallyMirrorFrontFacingCamera;//default YES;
@property(readwrite,nonatomic)BOOL horizontallyMirrorRearFacingCamera;//default  NO;
//支持的预览分辨率 AVCaptureSessionPreset352x288
//AVCaptureSessionPreset640x480
//AVCaptureSessionPresetiFrame960x540
//AVCaptureSessionPreset1280x720
-(void)vcs_switchCamera:(BOOL)isFront;//切换摄像头
-(BOOL)vcs_Camera_Light:(BOOL)open;//打开灯光
-(void)vcs_startCapture;//开始视频采集
-(void)vcs_stopCapture;//停止视频采集
-(void)vcs_reSetCameraSize:(NSString*)AVCaptureSessionPresetiFrame Orientation:(BOOL)landscape;
-(void)vcs_CloseCamera;//关闭摄像头
-(void)vcs_setCameraViewSize:(CGRect)rect;//设置camera viewlayout 大小
-(void)vcs_chanVideoOrientation:(BOOL)landscape; //视频横竖屏切换
-(void)vcs_OpenCamera:(NSString*)AVCaptureSessionPresetiFrame isFront:(BOOL)isFront Orientation:(BOOL)landscape; //打开摄像头 [预览分辨率 不设置 默认 640x480 isFront 默认true ]
-(void)vcs_CreateCameraOut:(int)outWidth outHeight:(int)outHeight; //设置最后的输出大小 默认 320x240
-(void)vcs_CameraOutputType:(BOOL)CenterInside;//设置输出视频缩放样式 在源和输出比例不一致时 是否加黑边 默认加黑边
-(void)vcs_Use_Center_Inside:(BOOL)CenterInside;
-(void)vcs_setOutputImageOrientation:(UIInterfaceOrientation)value;
-(void)vcs_changeOrientation:(UIInterfaceOrientation)value;

@end
