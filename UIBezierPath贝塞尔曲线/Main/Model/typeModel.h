//
//  typeModel.h
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/28.
//  Copyright © 2017年 View. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface typeModel : NSObject

@property (nonatomic, copy) NSString *title;

@property (nonatomic, assign) shapeType type;

-(instancetype)initWithTitle:(NSString *)title andShapeType:(shapeType)type;

@end
