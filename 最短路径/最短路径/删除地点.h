#pragma once
#pragma once
#include "ͼ�Ķ���.h"
#include "ͼ�Ķ���.h"
#include <iostream>
#include <math.h>
using namespace std;

void AllKill(graph *p);//ɾ�����ܺ���
void Kill(graph *p,int i);//ɾ���Ľڵ㺯��
int Judge(graph *p,char test[num]);//�жϵص�ĺ���

int Judge(graph *p,char test[num])
{
	for (int j = 0; j < len; j++)
	{
		if (strcmp(test, p->vex[j]) == 0)
		{
			cout << "***���ҵ���Ҫɾ���Ľ��,���ڽ���ɾ��***" << endl;
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
	cout << "***�Ѿ�ɾ������Ҫɾ���Ľ��,�������������˳�***" << endl;

	AllDFSA(p, 0);
	cout <<endl;
}

void AllKill(graph *p)
{
	char test[num];
	AllDFSA(p, 0);
	cout << "\n***��������Ҫɾ���ĵص㣡***\n" << endl;
	cout << "���� # �Խ�����������(�ص�����󳤶�Ϊ128)\n" << endl;

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
				cout << "δ�ҵ�������Ľ�㣬����������" << endl;
			}
			else
			{
				Kill(p, i);
				if (len == 0)
				{
					cout << "�Ѿ���ȫɾ����ͼ�еĵص㣬���������벢����ͼ" << endl;
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