//
//  LineMath.h
//  DropAnimation
//
//  Created by apple on 16/2/18.
//  Copyright © 2016年 apple. All rights reserved.
//


//  角度转弧度
#define degreesToRadian(x) (M_PI * x / 180.0)

//  弧度转角度
#define radiansToDegrees(x) (180.0 * x / M_PI)

typedef enum {
    kLineNormal,        //正常
    kLineHorizontal,    //水平
    kLineVertical,      //竖直
}kLineStatus;

typedef enum {
    kNear,
    kFar,
}kPointCondition;       //判断点的关系

#import <Foundation/Foundation.h>

@interface LineMath : NSObject

@property (assign, nonatomic) CGPoint point1;
@property (assign, nonatomic) CGPoint point2;
@property (assign, nonatomic) CGPoint tempCenter;   //临时点，当处于垂直状态时可以使用
@property (assign, nonatomic) CGFloat degrees;
@property (strong, nonatomic) UIView  *InView;
@property (assign, nonatomic) kLineStatus lineStatus;

//  直线方程 y=kx+b;
@property (assign, nonatomic) CGFloat k;
@property (assign, nonatomic) CGFloat b;
@property (assign, nonatomic) CGFloat x;
@property (assign, nonatomic) CGFloat y;


- (instancetype)initWithPoint1:(CGPoint)point1 point2:(CGPoint)point2 inView:(UIView *)inView;

//  计算两点间的距离
+ (CGFloat)calucateDistanceBetweenPoint1:(CGPoint)point1 withPoint2:(CGPoint)point2;

//  计算任意两点和某一点距离更近／远的点
+ (CGPoint)calucatePointWithOriginPoint:(CGPoint)originPoint point1:(CGPoint)point1 point2:(CGPoint)point2 condition:(kPointCondition)condition;

//  计算两条线的交点
+ (CGPoint)calucateAcrossPointBetweenLine1:(LineMath *)line1 withLine2:(LineMath *)line2;

//  计算两点的中点
+ (CGPoint)calucateCenterPointBetweenPoint1:(CGPoint)point1 withPoint2:(CGPoint)point2;

//  计算某值在某值在某区域内所占比例
+ (CGFloat)calucateRatioBetweenMin:(CGFloat)min Max:(CGFloat)max Now:(CGFloat)now;

//  根据比例计算在某区域内对应的值
+ (CGFloat)calucateValueBetweenMin:(CGFloat)min Max:(CGFloat)max Ratio:(CGFloat)ratio;

@end
