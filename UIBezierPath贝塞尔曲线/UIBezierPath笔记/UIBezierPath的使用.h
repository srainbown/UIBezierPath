//
//  UIBezierPath的使用.h
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/28.
//  Copyright © 2017年 View. All rights reserved.
//

#ifndef UIBezierPath____h
#define UIBezierPath____h

/*
 1.构造路径
        1)将 UIBezierPath 对象的 currentPoint 移动到指定的点
 
                * 设置起点
                * 如果当前有正在绘制的子路径, 该方法则会隐式的结束当前路径, 并将 currentPoint 设置为指定点.
                * @param point: 当前坐标系统中的某一点
             
                // Swift
                 func moveToPoint(_ point: CGPoint)
                // Objective-C
                 - (void)moveToPoint:(CGPoint)point;

         2)在当前子路径中追加一条直线
 
                * 添加一根线到终点
                * 该方法将会从 currentPoint 到 指定点 链接一条直线.
                * @param point: 绘制直线的终点坐标, 当前坐标系统中的某一点
                * Note: 在追加完这条直线后, 该方法将会更新 currentPoint 为 指定点
                * 调用该方法之前, 你必须先设置 currentPoint. 如果当前绘制路径
                * 为空, 并且未设置 currentPoint, 那么调用该方法将不会产生任何效果.
             
                 // Swift
                 func addLineToPoint(_ point: CGPoint)
                 // Objective-C
                 - (void)addLineToPoint:(CGPoint)point;

        3)在当前子路径中追加一条圆弧

                * 画指定一条圆弧
                * 该方法将会从 currentPoint 添加一条指定的圆弧.
                * 该方法的介绍和 bezierPathWithArcCenter构造方法中的一样. 请前往上文查看
                * @param center: 圆心
                * @param radius: 半径
                * @param startAngle: 开始角度
                * @param endAngle: 结束角度
                * @param clockwise: 是否顺时针绘制

                - (void)addArcWithCenter:(CGPoint)center radius:(CGFloat)radius startAngle:(CGFloat)startAngle endAngle:(CGFloat)endAngle clockwise:(BOOL)clockwise NS_AVAILABLE_IOS(4_0);

        4)在当前 子路经中追加一条 二次贝塞尔曲线
 
                 * 画二次贝塞尔曲线（由一个控制点来控制）
                 * 该方法将会从 currentPoint 到 指定的 endPoint 追加一条二次贝塞尔曲线.
                 * currentPoint、endPoint、controlPoint 三者的关系最终定义了二次贝塞尔曲线的形状.
                 * 二次贝塞尔曲线的弯曲由一个控制点来控制. 如下图所示
                 * Note: 调用该方法前, 你必须先设置 currentPoint, 如果路径为空,
                 * 并且尚未设置 currentPoint, 调用该方法则不会产生任何效果.
                 * 当添加完贝塞尔曲线后, 该方法将会自动更新 currentPoint 为
                 * 指定的结束点
                 * @param endPoint: 终点
                 * @param controlPoint: 弯曲方向点1

                 // Swift
                func addQuadCurveToPoint(_ endPoint: CGPoint,
                                         controlPoint controlPoint: CGPoint)
                 // Objective-C
                - (void)addQuadCurveToPoint:(CGPoint)endPoint controlPoint:(CGPoint)controlPoint;

        5)在当前 子路经中追加一条 三次贝塞尔曲线

                 * 画三次贝塞尔曲线（由两个控制点来控制）
                 * 该方法将会从 currentPoint 到 指定的 endPoint 追加一条三次贝塞尔曲线.
                 * 三次贝塞尔曲线的弯曲由两个控制点来控制. 如下图所示
                 * Note: 调用该方法前, 你必须先设置 currentPoint, 如果路径为空,
                 * 并且尚未设置 currentPoint, 调用该方法则不会产生任何效果.
                 * 当添加完贝塞尔曲线后, 该方法将会自动更新 currentPoint 为
                 * 指定的结束点
                 * @param endPoint: 终点
                 * @param controlPoint1: 弯曲方向点1
                 * @param controlPoint2: 弯曲方向点2

                // Swift
                func addCurveToPoint(_ endPoint: CGPoint,
                                     controlPoint1 controlPoint1: CGPoint,
                                     controlPoint2 controlPoint2: CGPoint)
                // Objective-C
                - (void)addCurveToPoint:(CGPoint)endPoint controlPoint1:(CGPoint)controlPoint1 controlPoint2:(CGPoint)controlPoint2;

        6)关闭当前子路经
 
                 * 闭合路径
                 * 该方法将会从 currentPoint 到子路经的起点 绘制一条直线,
                 * 以此来关闭当前的自路径. 紧接着该方法将会更新 currentPoint
                 * 为 刚添加的这条直线的终点, 也就是当前子路经的起点.

                // Swift
                func closePath()
                // Objective-C
                - (void)closePath;

        7)移除 UIBezierPath 对象中的所有点, 效果也就等同于移除所有子路经
 
                 // Swift
                 func removeAllPoints()
                 // Objective-C
                 - (void)removeAllPoints;

        8)将指定 UIBezierPath 中的内容添加到当前 UIBezierPath 对象中
 
                 * 追加路径
                 * 该方法将会在当前 UIBezierPath 对象的路径中追加
                 * 指定的 UIBezierPath 对象中的内容.

                // Swift
                func appendPath(_ bezierPath: UIBezierPath)
                // Objectiv e-C
                - (void)appendPath:(UIBezierPath *)bezierPath;

        9)UIBezierPath 中的 CGPath 对象
 
                 * 获取这个属性, 你将会获得一个不可变的 CGPathRef 对象,
                 * 他可以传入 CoreGraphics 提供的函数中
                 * 你可以是用 CoreGraphics 框架提供的方法创建一个路径,
                 * 并给这个属性赋值, 当时设置了一个新的路径后,
                 * 这个将会对你给出的路径对象进行 Copy 操作

                // Swift
                var CGPath: CGPath
                // Objective-C
                @property(nonatomic) CGPathRef CGPath;

        10)绘图路径中的当前点
 
                 * 该属性的值, 将会是下一条绘制的直线或曲线的起始点.
                 * 如果当前路径为空, 那么该属性的值将会是 CGPointZero

                // Swift
                var currentPoint: CGPoint { get }
                // Objective-C
                @property(nonatomic, readonly) CGPoint currentPoint;

 2.绘图属性
 
        1)线宽

                * 线宽属性定义了 `UIBezierPath` 对象中绘制的曲线规格. 默认为: 1.0

                // Swift
                var lineWidth: CGFloat
                // Objective-C
                @property(nonatomic) CGFloat lineWidth;

        2)曲线终点样式
 
                 * 该属性应用于曲线的终点和起点. 该属性在一个闭合子路经中是无效果的. 默认为: kCGLineCapButt

                // Swift
                var lineCapStyle: CGLineCap
                // Objective-C
                @property(nonatomic) CGLineCap lineCapStyle;
                // Line cap styles.
                typedef CF_ENUM(int32_t, CGLineCap) {
                    kCGLineCapButt,//
                    kCGLineCapRound,// 圆弧
                    kCGLineCapSquare //
                };
 
        3)曲线连接点样式

                * 默认为: kCGLineJoinMiter.

                // Swift
                var lineJoinStyle: CGLineJoin
                // Objective-C
                @property(nonatomic) CGLineJoin lineJoinStyle;
                // Line join styles.
                typedef CF_ENUM(int32_t, CGLineJoin) {
                    kCGLineJoinMiter,// 尖的
                    kCGLineJoinRound,// 圆弧
                    kCGLineJoinBevel // 斜面
                };

        4)内角和外角距离
 
                 * 斜接点长度
                 * 两条线交汇处内角和外角之间的最大距离, 只有当连接点样式为 kCGLineJoinMiter
                 * 时才会生效，最大限制为10
                 * 我们都知道, 两条直线相交时, 夹角越小, 斜接长度就越大.
                 * 该属性就是用来控制最大斜接长度的.
                 * 当我们设置了该属性, 如果斜接长度超过我们设置的范围,
                 * 则连接处将会以 kCGLineJoinBevel 连接类型进行显示.

                // Swift
                var miterLimit: CGFloat
                // Objective-C
                @property(nonatomic) CGFloat miterLimit;

        5)渲染精度
 
                 * 该属性用来确定渲染曲线路径的精确度.
                 * 该属性的值用来测量真实曲线的点和渲染曲线的点的最大允许距离.
                 * 值越小, 渲染精度越高, 会产生相对更平滑的曲线, 但是需要花费更
                 * 多的计算时间. 值越大导致则会降低渲染精度, 这会使得渲染的更迅速. flatness 的默认值为 0.6.
                 * Note: 大多数情况下, 我们都不需要修改这个属性的值. 然而当我们
                 希望以最小的消耗去绘制一个临时的曲线时, 我们也许会临时增
                 大这个值, 来获得更快的渲染速度.

                // Swift
                var flatness: CGFloat
                // Objective-C
                @property(nonatomic) CGFloat flatness;

         6)是否使用基偶填充规则
 
                 * 设置为 YES, 则路径将会使用 基偶规则 (even-odd) 进行填充.
                 * 设置为 NO,  则路径将会使用 非零规则 (non-zero) 规则进行填充.

                // Swift
                var usesEvenOddFillRule: Bool
                // Objective-C
                @property(nonatomic) BOOL usesEvenOddFillRule;

        7)虚线

                 * @param pattern: 该属性是一个 C 语言的数组, 其中每一个元素都是 CGFloat
                 数组中的元素代表着线段每一部分的长度, 第一个元素代表线段的第一条线,
                 第二个元素代表线段中的第一个间隙. 这个数组中的值是轮流的. 来解释一下
                 什么叫轮流的.
                 *                 举个例子: 声明一个数组 CGFloat dash[] = @{3.0, 1.0};
                 这意味着绘制的虚线的第一部分长度为3.0, 第一个间隙长度为1.0, 虚线的
                 第二部分长度为3.0, 第二个间隙长度为1.0. 以此类推.
                 * @param count: 这个参数是 pattern 数组的个数
                 * @param phase: 这个参数代表着, 虚线从哪里开始绘制.
                 *                 举个例子: 这是 phase 为 6. pattern[] = @{5, 2, 3, 2}; 那么虚线将会
                 第一个间隙的中间部分开始绘制, 如果不是很明白就请继续往下看,
                 下文实战部分会对虚线进行讲解.

                // Swift
                func setLineDash(_ pattern: UnsafePointer<CGFloat>,
                                 count count: Int,
                                 phase phase: CGFloat)
                // Objective-C
                - (void)setLineDash:(const CGFloat *)pattern
                count:(NSInteger)count
                phase:(CGFloat)phase;

        8)重新获取虚线的模式
 
                 * 该方法可以重新获取之前设置过的虚线样式.
                 *  Note:  pattern 这个参数的容量必须大于该方法返回数组的容量.
                 如果无法确定数组的容量, 那么可以调用两次该方法, 第一次
                 调用该方法的时候, 传入 count 参数, 然后在用 count 参数
                 来申请 pattern 数组的内存空间. 然后再第二次正常的调用该方法

                // Swift
                func getLineDash(_ pattern: UnsafeMutablePointer<CGFloat>,
                                 count count: UnsafeMutablePointer<Int>,
                                 phase phase: UnsafeMutablePointer<CGFloat>)
                // Objective-C
                - (void)getLineDash:(CGFloat *)pattern
                count:(NSInteger *)count
                phase:(CGFloat *)phase;

3.绘制路径
        1)填充路径

                 * 填充（实心）
                 * 该方法当前的填充颜色 和 绘图属性对路径的封闭区域进行填充.
                 * 如果当前路径是一条开放路径, 该方法将会隐式的将路径进行关闭后进行填充
                 * 该方法在进行填充操作之前, 会自动保存当前绘图的状态, 所以我们不需要
                 * 自己手动的去保存绘图状态了.

                // Swift
                func fill()
                // Objective-C
                - (void)fill;

        2)混合模式进行填充

                 * 该方法当前的填充颜色 和 绘图属性 (外加指定的混合模式 和 透明度)
                 * 对路径的封闭区域进行填充. 如果当前路径是一条开放路径, 该方法将
                 * 会隐式的将路径进行关闭后进行填充
                 * 该方法在进行填充操作之前, 会自动保存当前绘图的状态, 所以我们不需要
                 * 自己手动的去保存绘图状态了.
                 *
                 * @param blendMode: 混合模式决定了如何和已经存在的被渲染过的内容进行合成
                 * @param alpha: 填充路径时的透明度

                // Swift
                func fillWithBlendMode(_ blendMode: CGBlendMode,
                                       alpha alpha: CGFloat)
                // Objective-C
                - (void)fillWithBlendMode:(CGBlendMode)blendMode
                alpha:(CGFloat)alpha;

        3)描边路径
 
                 // Swift
                 func stroke()
                 // Objective-C
                 - (void)stroke;

         4)混合模式进行填充
 
                 * @param blendMode: 混合模式决定了如何和已经存在的被渲染过的内容进行合成
                 * @param alpha: 填充路径时的透明度

                // Swift
                func strokeWithBlendMode(_ blendMode: CGBlendMode,alpha alpha: CGFloat)
                // Objective-C
                - (void)strokeWithBlendMode:(CGBlendMode)blendMode
                alpha:(CGFloat)alpha;

 4.剪切路径
        1)剪切路径

                 *  该方法将会修改当前绘图上下文的可视区域.
                 *  当调用这个方法之后, 会导致接下来所有的渲染操作,
                 只会在剪切下来的区域内进行, 区域外的内容将不会被渲染.
                 *  如果你希望执行接下来的绘图时, 删除剪切区域,
                 那么你必须在调用该方法前, 先使用CGContextSaveGState 方法保存当前的绘图状态,
                 当你不再需要这个剪切区域的时候, 你只需要使用 CGContextRestoreGState 方法，
                 来恢复之前保存的绘图状态就可以了.
                 * @param blendMode: 混合模式决定了如何和已经存在的被渲染过的内容进行合成
                 * @param alpha: 填充路径时的透明度

                // Swift
                func addClip()
                // Objective-C
                - (void)addClip;

 5.Hit Detection
 
         1)是否包含某个点

                 * 该方法返回一个布尔值, 当曲线的覆盖区域包含
                 * 指定的点(内部点)， 则返回 YES, 否则返回 NO.
                 * Note: 如果当前的路径是一个开放的路径, 那么
                 就算指定点在路径覆盖范围内, 该方法仍然会
                 返回 NO, 所以如果你想判断一个点是否在一个
                 开放路径的范围内时, 你需要先Copy一份路径,
                 并调用 -(void)closePath; 将路径封闭, 然后
                 再调用此方法来判断指定点是否是内部点.
                 * @param point: 指定点.

                // Swift
                func containsPoint(_ point: CGPoint) -> Bool
                // Objective-C
                - (BOOL) containsPoint:(CGPoint)point;

         2)路径是否为空

                 * 检测当前路径是否绘制过直线或曲线.
                 * Note: 记住, 就算你仅仅调用了 moveToPoint 方法
                 那么当前路径也被看做不为空.

                // Swift
                var empty: Bool { get }
                // Objective-C
                @property (readonly, getter=isEmpty) BOOL empty;

        3)路径覆盖的矩形区域

                 * 该属性描述的是一个能够完全包含路径中所有点
                 *  的一个最小的矩形区域. 该区域包含二次贝塞尔
                 *  曲线和三次贝塞尔曲线的控制点.

                // Swift
                var bounds: CGRect { get }
                // Objective-C
                @property (nonatomic, readonly) CGRect bounds;

         4)Apply Transform
 
                 * 该方法将会直接对路径中的所有点进行指定的放射
                 * 变换操作.

                // Swift
                func applyTransform(_ transform: CGAffineTransform)
                // Objective-C
                - (void)applyTransform:(CGAffineTransform)transform;

 
                 // Swift
                 struct UIRectCorner : OptionSetType {
                 init(rawValue rawValue: UInt)
                 static var TopLeft: UIRectCorner { get }
                 static var TopRight: UIRectCorner { get }
                 static var BottomLeft: UIRectCorner { get }
                 static var BottomRight: UIRectCorner { get }
                 static var AllCorners: UIRectCorner { get }
                 }
                 // Objective-C
                 enum {
                 UIRectCornerTopLeft     = 1 << 0,
                 UIRectCornerTopRight    = 1 << 1,
                 UIRectCornerBottomLeft  = 1 << 2,
                 UIRectCornerBottomRight = 1 << 3,
                 UIRectCornerAllCorners  = ~0
                 };
                 typedef NSUInteger UIRectCorner;
                 常数(Constants):
                 UIRectCornerTopLeft
                 The top-left corner of the rectangle.
                 矩形的左上角.
                 Available in iOS 3.2 and later.
                 UIRectCornerTopRight
                 The top-right corner of the rectangle.
                 矩形的右上角.
                 Available in iOS 3.2 and later.
                 UIRectCornerBottomLeft
                 The bottom-left corner of the rectangle.
                 矩形的左下角.
                 Available in iOS 3.2 and later.
                 UIRectCornerBottomRight
                 The bottom-right corner of the rectangle.
                 矩形的右下角.
                 Available in iOS 3.2 and later.
                 UIRectCornerAllCorners
                 All corners of the rectangle.
                 矩形的所有的角.
                 Available in iOS 3.2 and later.
                 指定的常数反映了一个没有被 仿射变换修改和已经在默认坐标系上绘制的矩形的所有角.(原点在左上角和 ??扩散的值(positive values)向下延伸到右边).
                 导入声明(Import Statement)
                 // Swift
                 import UIKit
                 // Objective-C
                 @import UIKit;
 
 
 */


#endif /* UIBezierPath____h */




