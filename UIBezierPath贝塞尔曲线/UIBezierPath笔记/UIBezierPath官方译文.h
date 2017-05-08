//
//  UIBezierPath官方译文.h
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/28.
//  Copyright © 2017年 View. All rights reserved.
//

#ifndef UIBezierPath_____h
#define UIBezierPath_____h

/*
 笔记
 
 1.
 注意：是自定义view中，不是控制器中
 UIBezierPath类允许你在 《自定义view中》 绘制和渲染直线和曲线组成的路径。你可以在初始化的时候，直接为你的UIBezierPath制定一个几个路径。路径可以是简单的几何图形。
 例如:矩形，椭圆，弧线之类的，也可以是相对比较复杂的由直线和曲线组成的多边形。
 当你定义完，这些图形之后，你可以使用这个类的其他方法将你的路径直接绘制在当前绘图的上下文中。
 
 2.
 UIBezierPath是由几何路径和属性描述组成的，属性是用来在渲染阶段描绘几何路径的
 比如：线宽之类的东西。
 路径和属性是完全独立的，他们并不互相依赖，你可以分开去设置他们。一旦你以自己喜欢的方式配置了UIBezierPath对象，你就可以调用方法通知UIBezierPath在当前的绘图上下文中绘制图形了。因为创建，配置，渲染路径等操作，都是完全不同的步骤，所以你可以在你的代码中非常容易的对UIBezierPath对象进行复用。你甚至可以使用同一个UIBezierPath对象去渲染同一个图形很多次，你也可以再多次渲染的间隔中，修改属性来渲染出不同样式的路径。
 
 3.
 你可以通过控制路径的当前(起点)来设置一条路径的形状，当你创建了一个空的UIBezierPath对象时，起点currentPoint这个属性是未定义的，你需要手动的区设置.currentPoint。如果你希望在不绘制任何线条的情况下移动currentPoint,你可以使用moveToPoint:方法。其他的方法会导致你在路径中添加额外的直线或曲线。所有构造路径相关的方法，都会以当前路径的currentPoint为起点，以你制定的endPoint为终点进行绘制。当完成绘制之后，会自动将新增的这条线的终点设置为UIBezierPath对象的currentPoint.
 
 4.
 一个单一的贝塞尔路径对象能够包含任意数量的开放和闭合的子路径，在这些路径的线段中，没一个线段都是串联的。调用closePath方法将会闭合路径，它将会从currentPoint到子路径的firstPoint起点绘制一条直线。调用moveToPoint:方法将会结束当前的子路径，但是并不会自动闭合当前的子路径，并且会将currentPoint移动到制定的点，也就是下一条绘制路径的起始点.UIBezierPath中所有的子路径都会共享同样的绘图属性。如果你希望绘制一些子路径，但是不适用相同的绘图属性，那么你就只能创建很多的UIBezierPath对象来承载每一条路径。
 
 5.
 当你为UIBezierPath对象配置完几何路径和绘图属性之后，你就可以使用stroke描边（空心）和fill（填充）方法在当前的绘图上下文中进行绘制了。stroke方法将会使用当前的strokeColor和绘图属性来描绘曲线的轮廓。同样的，fill方法将会使用fillColor来填充路径所围成的图形(使用UIColor类方法来设置strokeColor和fillColor).
 
 6.
 除了可以用贝塞尔路径对象去绘制图形，你还可以利用它去定义个新的裁剪区域，addClip方法通过当前图形上下文裁剪的区域的路径对象来表示两个圆形的相交。在随后的绘制过程中，只有处在新的交集区域内的内容实际上是被图形上下文绘制的。
 
 */


#endif /* UIBezierPath_____h */




