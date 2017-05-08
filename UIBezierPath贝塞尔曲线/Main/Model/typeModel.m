
//
//  typeModel.m
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/28.
//  Copyright © 2017年 View. All rights reserved.
//

#import "typeModel.h"

@implementation typeModel

-(instancetype)initWithTitle:(NSString *)title andShapeType:(shapeType)type{
    
    self = [super init];
    
    if (self) {
        self.title = title;
        self.type = type;
    }
    
    return self;
    
}



@end
