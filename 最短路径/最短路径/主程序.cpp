#include "Dj算法调用.h"
#include "图的读入.h"
#include <iostream>
#include "展示界面.h"
#include "图的定义.h"
#include "加入地点.h"
#include "删除地点.h"
#include "打印输出.h"
using namespace std;

int main()
{
	graph *G;
	G = new graph;
	int choice;//选择的flag
	while (true)
	{
		Show_Menu();//展示的函数
		cin >> choice;
		switch (choice)
		{
			case 1://创建图读入图的数据
				if (G->i)
				{
					cout << "您已经读入了并创建了一个图，请选择重新输入地点或者继续添加地点" << endl;
					system("pause");
				}
				else
				{
					Creat(G);
				}
				
				system("cls");
				break;
			case 2:
				if (G->i)
				{
					Dj(G);
				}
				else
				{
					cout << "***您尚未创建图，请输入地点创建一个图哦！***" << endl;
					system("pause");
				}				
				system("cls");
				break;
			case 3://继续输入地点
				if (G->i)
				{
					AllAdd(G);
				}
				else
				{
					cout << "***您尚未创建图，请输入地点创建一个图哦！***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 4://输出图以及各边的权值
				if (G->i)
				{
					Print(G);
				}
				else
				{
					cout << "***您尚未创建图，请输入地点创建一个图哦！***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 5://删除图
				if (G->i)
				{
					DeleteGraph(G);
					cout << "****您创建的图已经被删除了***" << endl;
					system("pause");
				}
				else
				{
					cout << "***您尚未创建图，请输入地点创建一个图哦！***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 6://删除图
				if (G->i)
				{
					AllKill(G);
				}
				else
				{
					cout << "***您尚未创建图，请输入地点创建一个图哦！***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 0://退出循环
				exitSystem();

			default://清屏
				system("cls");
				cout << "*********请输入正确的选择！**************" << endl;
				cout << endl;
				break;
		}
		cin.clear();
		cin.ignore();
	}
	system("pause");
	return 0;
}
/*
南宁 378 78
河内 327 119
曼谷 232 266
金边 314 311
吉隆坡 255 477
新加坡 296 513
文莱 510 438
马尼拉 628 246
*/