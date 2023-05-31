#pragma once
#include <iostream>
#include "图的定义.h"
#include "图的读入.h"
float sum = 0;
using namespace std;
void Dj(graph *p);//总的概括算法
void Dijkstra(int v, float dis[][num],graph *p);//最短路径计算算法
int Chose(graph *p);//选择起点的算法

int Chose(graph *p)
{
	AllDFSA(p, 0);//打印输出输入的地点
	int i;//变量

	cout << "\n请输入您要查询路径的起点:" << endl;
	char space[num];
	cin >> space;
	while (true)
	{
		for ( i = 0; i < len; i++)
		{
			if (strcmp(space, p->vex[i]) == 0)
			{
				cout << "\n***已找到您要查询的起点***\n" << endl;
				return i;
			}
		}
		if (i == len )
		{
			cout << "\n***未找到该地点，请重新输入!***" << endl;
			cin.clear();
			cin.ignore();
			cin >> space;
		}
	}
}

void Dijkstra(int v, float dis[][num],graph *p)
{
	int i, j, v1, max = 10000,m=1,n1=0;
	float min, sum = 0;
	int path[num],s[num];
	path[0] = v;
	v1 = v;

	for (i = 0; i < len; i++)  //各组数据初始化
	{
		s[i] = 0;
	}

	s[v1] = 1;

	for (i = 0; i < len - 1; i++)
	{
		min = 10001;
		for (j = 0; j < len; j++)
		{
			if ((!s[j]) && (dis[v1][j] < min))
			{
				min = dis[v1][j];
				v = j;
			}
		}
		v1 = v;
		s[v] = 1;
		path[m] = v;
		sum += min;
		m++;

	}

	cout << "***************路径输出如下******************" << endl;
	for (i = 0; i < len; i++)
	{
		if (i == len - 1)
		{
			printf(" ->%s ", p->vex[path[i]]);
		}
		else
		{
			n1= path[i];
			m = path[i + 1];
			printf(" %s->(%f) ",p->vex[path[i]], dis[n1][m]);
		}
		
		
	}
	cout << endl << endl;
	cout << "********最短路径之和为 " << sum <<"   ***********"<< endl;
	sum = 0;//最后清空总长度，防止再次读入出现错误
}
void Dj(graph *p)
{
	int i = Chose(p);
	Dijkstra(i, p->arcs,p);
	system("pause");

}