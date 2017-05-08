//
//  SelectViewController.m
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/28.
//  Copyright © 2017年 View. All rights reserved.
//

#import "SelectViewController.h"
#import "BezierPathView.h"

@interface SelectViewController ()

@end

@implementation SelectViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.navigationItem.title = _model.title;
    
    BezierPathView *bezierPathView = [[BezierPathView alloc]initWithFrame:CGRectMake(0, 64,KWidth , KHeight - 64) andshapeType:_model.type];
    [self.view addSubview:bezierPathView];
    
}


@end
