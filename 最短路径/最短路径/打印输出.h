#pragma once
#pragma once
#pragma once
#include "ͼ�Ķ���.h"
#include "ͼ�Ķ���.h"
#include <iostream>
#include <math.h>
using namespace std;

void Print(graph *p);//��ӡ����ĺ���


void Print(graph *p)
{
	cout << "��ӡ���������ʾ(��λ��KM)" << endl;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i != j)
			{
				cout << p->vex[i] << "  ��  " << p->vex[j] << "  �ľ���Ϊ:  " << p->arcs[j][i] << endl;
				if (j == len - 1)
				{
					cout << endl;
				}
			}
		}
	}
	system("pause");
}