#pragma once
#pragma once
#pragma once
#include "图的定义.h"
#include "图的读入.h"
#include <iostream>
#include <math.h>
using namespace std;

void Print(graph *p);//打印输出的函数


void Print(graph *p)
{
	cout << "打印输出如下所示(单位：KM)" << endl;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i != j)
			{
				cout << p->vex[i] << "  到  " << p->vex[j] << "  的距离为:  " << p->arcs[j][i] << endl;
				if (j == len - 1)
				{
					cout << endl;
				}
			}
		}
	}
	system("pause");
}