//
//  MainViewController.m
//  UIBezierPath贝塞尔曲线
//
//  Created by 李自杨 on 2017/4/27.
//  Copyright © 2017年 View. All rights reserved.
//

#import "MainViewController.h"
#import "SelectViewController.h"
#import "typeModel.h"

@interface MainViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, strong) NSMutableArray *dataArray;

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.navigationItem.title = @"贝塞尔曲线选择";
    self.view.backgroundColor = [UIColor whiteColor];
        
    [self getData];
    [self createTableView];

}

#pragma mark -- 懒加载
-(NSMutableArray *)dataArray{
    
    if (_dataArray == nil) {
        _dataArray = [NSMutableArray array];
    }
    return _dataArray;
    
}    

#pragma mark -- 数据
-(void)getData{
    
    typeModel *model1 = [[typeModel alloc]initWithTitle:@"画直线" andShapeType:shapeTypeStraightLine];
    [self.dataArray addObject:model1];
    
    typeModel *model2 = [[typeModel alloc]initWithTitle:@"画矩形" andShapeType:shapeTypeRectangle];
    [self.dataArray addObject:model2];
    
    typeModel *model3 = [[typeModel alloc]initWithTitle:@"画圆" andShapeType:shapeTypeCircular];
    [self.dataArray addObject:model3];
    
    typeModel *model4 = [[typeModel alloc]initWithTitle:@"圆角矩形" andShapeType:shapeTypeRoundedRectangle];
    [self.dataArray addObject:model4];
    
    typeModel *model5 = [[typeModel alloc]initWithTitle:@"指定角为圆的圆角矩形" andShapeType:shapeTypeRoundedRectangleDIY];
    [self.dataArray addObject:model5];
    
    typeModel *model6 = [[typeModel alloc]initWithTitle:@"画圆弧" andShapeType:shapeTypeArc];
    [self.dataArray addObject:model6];
    
    typeModel *model7 = [[typeModel alloc]initWithTitle:@"根据路径A去创建路径B" andShapeType:shapeTypeCreateAnotherPathBasedOnAPath];
    [self.dataArray addObject:model7];
    
    typeModel *model8 = [[typeModel alloc]initWithTitle:@"反向绘制" andShapeType: shapeTypePathReversal];
    [self.dataArray addObject:model8];
    
    typeModel *model9 = [[typeModel alloc]initWithTitle:@"虚线" andShapeType: shapeTypeTheDottedLine];
    [self.dataArray addObject:model9];
    
}

#pragma mark -- 创建TableView
-(void)createTableView{
    
    UITableView *tableView = [[UITableView alloc]initWithFrame:self.view.bounds style:UITableViewStylePlain];
    [self.view addSubview:tableView];
    tableView.delegate = self;
    tableView.dataSource = self;
    
    UIView *foot = [[UIView alloc]init];
    tableView.tableFooterView = foot;
    
}

#pragma mark -- UITableViewDelegate,UITableViewDataSource
-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    
    return _dataArray.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{

    return 50;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{

    static NSString *cellID = @"cellID";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellID];
    }
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    typeModel *model = _dataArray[indexPath.row];
    
    cell.textLabel.text = model.title;

    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    
    NSLog(@"点击了第%ld个cell",indexPath.row);
    
    SelectViewController *vc = [[SelectViewController alloc]init];

    typeModel *model = _dataArray[indexPath.row];
    vc.model = model;
    
    [self.navigationController pushViewController:vc animated:YES];
    
}

@end
