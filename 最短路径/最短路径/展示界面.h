#pragma once
#include <iostream>
#include "图的定义.h"

using namespace std;

void Show_Menu();//展示的函数
void exitSystem();//退出的函数
void DeleteGraph(graph *G);//删除图的函数

void Show_Menu()//展示的函数
{
	cout << "******************************************************" << endl;
	cout << "******欢迎使用旅行计算图，请输入数字以执行操作：******" << endl;
	cout << "************* 1、请输入您要读入的地点以及坐标 ********" << endl;
	cout << "************* 2、生成要寻找的最短路径         ********" << endl;
	cout << "************* 3、继续输入地点与坐标           ********" << endl;
	cout << "************* 4、输出已经输入的地点与权值     ********" << endl;
	cout << "************* 5、清空当前记录的地点与坐标     ********" << endl;
	cout << "************* 6、删除记录的地点与坐标         ********" << endl;
	cout << "************* 0、退出系统		      ********" << endl;
	cout << "******************************************************" << endl;
	cout << "请输入您的选择:" << endl;
}

void exitSystem()//退出的函数
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void DeleteGraph(graph *G)
{
	cout << "请再次确定您是否要清空图呢？" << endl;
	cout << "1、是的" << endl;
	cout << "0、返回上一步" << endl;
	int a;
	cin >> a;
	while (true)
	{
		switch(a)
		{
			case 1:
				free(G);
				G = new graph;
				G->i = 0;
				cout << "图已经清空" << endl;
			case 0:
				return;
				cout << "已返回" << endl;

		}
	}

}