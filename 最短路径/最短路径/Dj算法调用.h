#pragma once
#include <iostream>
#include "ͼ�Ķ���.h"
#include "ͼ�Ķ���.h"
float sum = 0;
using namespace std;
void Dj(graph *p);//�ܵĸ����㷨
void Dijkstra(int v, float dis[][num],graph *p);//���·�������㷨
int Chose(graph *p);//ѡ�������㷨

int Chose(graph *p)
{
	AllDFSA(p, 0);//��ӡ�������ĵص�
	int i;//����

	cout << "\n��������Ҫ��ѯ·�������:" << endl;
	char space[num];
	cin >> space;
	while (true)
	{
		for ( i = 0; i < len; i++)
		{
			if (strcmp(space, p->vex[i]) == 0)
			{
				cout << "\n***���ҵ���Ҫ��ѯ�����***\n" << endl;
				return i;
			}
		}
		if (i == len )
		{
			cout << "\n***δ�ҵ��õص㣬����������!***" << endl;
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

	for (i = 0; i < len; i++)  //�������ݳ�ʼ��
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

	cout << "***************·���������******************" << endl;
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
	cout << "********���·��֮��Ϊ " << sum <<"   ***********"<< endl;
	sum = 0;//�������ܳ��ȣ���ֹ�ٴζ�����ִ���
}
void Dj(graph *p)
{
	int i = Chose(p);
	Dijkstra(i, p->arcs,p);
	system("pause");

}