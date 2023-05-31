#pragma once
#pragma once
#include "图的定义.h"
#include "图的读入.h"
#include <iostream>
#include <math.h>
using namespace std;

void AllKill(graph *p);//删除的总函数
void Kill(graph *p,int i);//删除的节点函数
int Judge(graph *p,char test[num]);//判断地点的函数

int Judge(graph *p,char test[num])
{
	for (int j = 0; j < len; j++)
	{
		if (strcmp(test, p->vex[j]) == 0)
		{
			cout << "***已找到您要删除的结点,正在进行删除***" << endl;
			return j;
		}
	}
	return -1;
}

void Kill(graph *p,int i)
{
	for (int j = i; j < len - 1; j++)
	{
		strcpy(p->vex[j], p->vex[j + 1]);
		position[j][0] = position[j + 1][0];
		position[j][1] = position[j + 1][1];
		Calcuate(p);
	}
	len--;
	cout << "***已经删除了您要删除的结点,请继续输入或者退出***" << endl;

	AllDFSA(p, 0);
	cout <<endl;
}

void AllKill(graph *p)
{
	char test[num];
	AllDFSA(p, 0);
	cout << "\n***请输入您要删除的地点！***\n" << endl;
	cout << "输入 # 以结束您的输入(地点名最大长度为128)\n" << endl;

	while (true)
	{
		 scanf("%s", &test);

		if (strcmp(test, "#") == 0)
		{
			break;
		}
		else
		{
			int i = Judge(p, test);
			if (i == -1)
			{
				cout << "未找到您输入的结点，请重新输入" << endl;
			}
			else
			{
				Kill(p, i);
				if (len == 0)
				{
					cout << "已经完全删除了图中的地点，请重新输入并建立图" << endl;
					free(p);
					p->i = 0;
					system("pause");
					return;
				}
			}
		}
	}
	system("pause");
}