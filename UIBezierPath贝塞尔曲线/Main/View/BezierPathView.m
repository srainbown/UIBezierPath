//
//  BezierPathView.m
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/27.
//  Copyright © 2017年 View. All rights reserved.
//

#import "BezierPathView.h"

@interface BezierPathView()

@property (nonatomic, assign) shapeType type;

@end

@implementation BezierPathView

-(instancetype)initWithFrame:(CGRect)frame andshapeType:(shapeType)shapeType{
    
    self = [super initWithFrame:frame];
    if (self) {
     
        self.type = shapeType;
        self.backgroundColor = [UIColor whiteColor];

    }
    return self;

}

-(void)drawRect:(CGRect)rect{

    switch (_type) {
        case shapeTypeStraightLine:{//画直线
        
            //竖线
            //创建1个UIBezierPath对象
            UIBezierPath *path1 = [UIBezierPath bezierPath];
            //用moveToPoint设置初始线段的起点
            [path1 moveToPoint:CGPointMake(50, 100)];
            //添加线段，定义1个或者多个子路径
            [path1 addLineToPoint:CGPointMake(50, 200)];
            //线宽
            path1.lineWidth = 5.0;
            //拐角样式
            //kCGLineJoinMiter尖角
            //kCGLineJoinRound圆角
            //kCGLineJoinBevel缺角
            path1.lineJoinStyle = kCGLineJoinRound;
            [path1 stroke];
            
            //横线
            UIBezierPath *path2 = [UIBezierPath bezierPath];
            [path2 moveToPoint:CGPointMake(100, 200)];
            [path2 addLineToPoint:CGPointMake(200, 200)];
            path2.lineWidth = 20.0;
            //颜色
            [[UIColor orangeColor]setStroke];
            [path2 stroke];
            
            //斜线
            UIBezierPath *path3 = [UIBezierPath bezierPath];
            [path3 moveToPoint:CGPointMake(150, 300)];
            [path3 addLineToPoint:CGPointMake(200, 400)];
            //颜色
            [[UIColor orangeColor]set];
            [path3 stroke];
    
        }
            break;
        case shapeTypeRectangle:{//画矩形，该方法将会创建一个闭合路径, 起始点是 rect 参数的的 origin, 并且按照顺时针方向添加直线, 最终形成矩形
            
            //描边
            UIBezierPath *path1 = [UIBezierPath bezierPathWithRect:CGRectMake(150, 50, 70, 150)];
            [[UIColor orangeColor]set];
            [path1 stroke];
            
            //填充
            UIBezierPath *path2 = [UIBezierPath bezierPathWithRect:CGRectMake(100, 300, 150, 150)];
            [[UIColor redColor]set];
            [path2 fill];
            
        }
            break;
        case shapeTypeCircular:{//画圆，该方法将会创建一个闭合路径,  该方法会通过  《 顺时针 》 的绘制贝塞尔曲线, 绘制出一个近似椭圆的形状. 如果 rect 参数指定了一个  《 矩形 》  , 那么该 UIBezierPath 对象将会描述一个圆形.
            //画圆（width = height）、画椭圆（width != height）
            
            //圆
            UIBezierPath *path1 = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(100, 50, 150, 150)];
            [[UIColor orangeColor]set];
            [path1 stroke];
            
            //椭圆
            UIBezierPath *path2 = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(100, 250, 200, 100)];
            [[UIColor redColor]set];
            [path2 fill];
            
        }
            break;
          
        case shapeTypeRoundedRectangle:{//该方法将会创建一个闭合路径,  该方法会顺时针方向连续绘制直线和曲线.  当 rect 为正方形时且 cornerRadius 等于边长一半时, 则该方法会描述一个圆形路径.
            
            //圆
            UIBezierPath *path1 = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(100, 100, 150, 150) cornerRadius:75];
            [[UIColor orangeColor]set];
            [path1 stroke];
            
            //圆角矩形 矩形路径的 Frame   ,  cornerRadius: 矩形的圆角半径
            UIBezierPath *path2 = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(100, 300, 200, 100) cornerRadius:50];
            [[UIColor blueColor]set];
            [path2 fill];
        
        }
            break;
            
        case shapeTypeRoundedRectangleDIY:{//画指定角为圆角的矩形   该方法将会创建一个闭合路径,  该方法会顺时针方向连续绘制直线和曲线.rect: 矩形路径的 Frame , corners: UIRectCorner 枚举类型, 指定矩形的哪个角变为圆角 , cornerRadii: 矩形的圆角半径
        
            UIBezierPath *path1 = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(100, 50, 150, 150) byRoundingCorners:UIRectCornerTopLeft cornerRadii:CGSizeMake(75, 75)];
            [[UIColor orangeColor]set];
            [path1 stroke];
            
            UIBezierPath *path2 = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(100, 250, 200, 100) byRoundingCorners:UIRectCornerAllCorners cornerRadii:CGSizeMake(50, 50)];
            [[UIColor blueColor]set];
            [path2 fill];
            
            UIBezierPath *path3 = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(100, 380, 200, 100) byRoundingCorners:UIRectCornerBottomRight cornerRadii:CGSizeMake(60, 60)];
            [[UIColor redColor]set];
            path3.lineWidth = 10;
            [path3 stroke];
            
        }
            break;
            
        case shapeTypeArc:{//画圆弧  该方法会创建出一个开放路径, 创建出来的圆弧是圆的一部分. 在默认的坐标系统中, 开始角度 和 结束角度 都是基于单位圆的, 调用这个方法之后, currentPoint 将会设置为圆弧的结束点.  center: 弧所在的圆心（这里不能直接用self.center,因为它是相对于它的父控件的,采用rect 宽度*0.5、高度*0.5） ,  radius: 圆的半径 ,  startAngle: 开始角度 ,  endAngle:  结束角度  ,  clockwise: 是否顺时针绘制（YES顺时针 NO逆时针）
//        圆的周长 = 圆周率 * 圆的直径
            
            UIBezierPath *path1 = [UIBezierPath bezierPathWithArcCenter:CGPointMake(200, 100) radius:50 startAngle:KDegreesToRadian(0) endAngle:KDegreesToRadian(180) clockwise:YES];
            path1.lineWidth = 5;
            [[UIColor orangeColor]set];
            [path1 stroke];
            
            UIBezierPath *path2 = [UIBezierPath bezierPathWithArcCenter:CGPointMake(200, 250) radius:30 startAngle:KDegreesToRadian(90) endAngle:KDegreesToRadian(-90) clockwise:NO];
            path2.lineWidth = 3;
            [[UIColor blueColor]set];
            [path2 stroke];
            
            UIBezierPath *path3 = [UIBezierPath bezierPathWithArcCenter:CGPointMake(200, 350) radius:100 startAngle:KDegreesToRadian(45) endAngle:KDegreesToRadian(150) clockwise:YES];
            [UIColor redColor];
            [path3 fill];
            
        }
            break;
            
        case shapeTypeCreateAnotherPathBasedOnAPath:{//根据路径A去创建路径B
            
            //路径A
            UIBezierPath *pathA = [UIBezierPath bezierPath];
            [pathA moveToPoint:CGPointMake(100, 100)];
            [pathA addLineToPoint:CGPointMake(250, 100)];
            pathA.lineWidth = 3;
            [pathA stroke];
            //避免两条线重合在一起，我们给第一条线做个平移
            CGAffineTransform transform = CGAffineTransformMakeTranslation(0, 100);
            [pathA applyTransform:transform];
            
            //路径B
            UIBezierPath *pathB = [UIBezierPath bezierPathWithCGPath:pathA.CGPath];
            [pathB stroke];
            
            }
            break;
        case  shapeTypePathReversal:{//路径反转  通过该方法反转一条路径, 并不会修改该路径的样子. 它仅仅是修改了绘制的方向.  返回一个新的 UIBezierPath 对象, 形状和原来路径的形状一样,但是绘制的方向相反.
  
            UIBezierPath *pathA = [UIBezierPath bezierPath];
            [pathA moveToPoint:CGPointMake(50, 100)];
            [pathA addLineToPoint:CGPointMake(100, 150)];
            [pathA addLineToPoint:CGPointMake(150, 70)];
            [pathA addLineToPoint:CGPointMake(200, 300)];
            
            //反向绘制
            UIBezierPath *pathB = [pathA bezierPathByReversingPath];
    
            //为避免两条线重合在一起我们给第一条线做个平移
            CGAffineTransform tansform = CGAffineTransformMakeTranslation(130, 0);
            [pathA applyTransform:tansform];
            
            pathA.lineWidth = 3;
            [[UIColor orangeColor]set];
            [pathA stroke];
            
            pathB.lineWidth = 5;
            [[UIColor redColor]set];
            [pathB stroke];

        }
            break;
           
        case shapeTypeTheDottedLine:{//虚线 pattern: 该属性是一个 C 语言的数组, 其中每一个元素都是 CGFloat  数组中的元素代表着线段每一部分的长度, 第一个元素代表线段的第一条线, 第二个元素代表线段中的第一个间隙. 这个数组中的值是轮流的. 来解释一下 什么叫轮流的.  举个例子: 声明一个数组 CGFloat dash[] = @{3.0, 1.0};  这意味着绘制的虚线的第一部分长度为3.0, 第一个间隙长度为1.0, 虚线的   第二部分长度为3.0, 第二个间隙长度为1.0. 以此类推. , count: 这个参数是 pattern 数组的个数 ，  phase: 这个参数代表着, 虚线从哪里开始绘制.
        
            UIBezierPath *path1 = [UIBezierPath bezierPath];
            [path1 moveToPoint:CGPointMake(100, 100)];
            [path1 addLineToPoint:CGPointMake(150, 150)];
            [path1 addLineToPoint:CGPointMake(100, 200)];
            path1.lineWidth = 2;
            [[UIColor orangeColor]set];
            //设置为虚线
            CGFloat dashLineConfig[] = {10.0,5.0};//前一个是虚线的长度，后一个是虚线的间隔
            [path1 setLineDash:dashLineConfig count:2 phase:0];
            [path1 stroke];
            
            
            UIBezierPath *path2 = [UIBezierPath bezierPath];
            [path2 moveToPoint:CGPointMake(100, 250)];
            [path2 addLineToPoint:CGPointMake(300, 250)];
            path2.lineWidth = 5;
            [[UIColor redColor]set];
            //设置为虚线
            CGFloat pathArray[] = {20.0,5.0,10.0,2.5};
            [path2 setLineDash:pathArray count:4 phase:0];
            [path2 stroke];
            
        }
            break;
            
        default:
            break;
    }
    
}




@end
