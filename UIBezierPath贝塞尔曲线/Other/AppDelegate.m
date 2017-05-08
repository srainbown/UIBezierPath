//
//  AppDelegate.m
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/27.
//  Copyright © 2017年 View. All rights reserved.
//

#import "AppDelegate.h"
#import "MainViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    [self.window makeKeyAndVisible];
    
    MainViewController *vc = [[MainViewController alloc]init];
    UINavigationController *navi = [[UINavigationController alloc]initWithRootViewController:vc];
    
    self.window.rootViewController = navi;
    
    return YES;
}

@end
