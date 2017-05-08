//
//  Header.h
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/27.
//  Copyright © 2017年 View. All rights reserved.
//

#ifndef Header_h
#define Header_h

#import <Masonry.h>
#define KWidth [UIScreen mainScreen].bounds.size.width
#define KHeight [UIScreen mainScreen].bounds.size.height

typedef NS_ENUM(NSInteger, shapeType){
    
    shapeTypeStraightLine     = 0,              //直线
    shapeTypeRectangle,                         //矩形
    shapeTypeCircular,                          //圆
    shapeTypeRoundedRectangle,                  //圆角矩形
    shapeTypeRoundedRectangleDIY,               //指定角为圆角的圆角矩形
    shapeTypeArc,                               //圆弧
    shapeTypeCreateAnotherPathBasedOnAPath,     //根据一个路径去创建另一条路径
    shapeTypePathReversal,                      //路径反转
    shapeTypeTheDottedLine                      //虚线
    
};

//由角度转弧度
#define KDegreesToRadian(x) (M_PI * (x) / 180.0)

//由弧度转角度
#define KRadianToDegress(radian) (radian * 180.0) / (M_PI)


#endif /* Header_h */

