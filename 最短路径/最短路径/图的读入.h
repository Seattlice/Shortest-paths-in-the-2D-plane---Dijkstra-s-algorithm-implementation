#pragma once
#include <iostream>
#include "ͼ�Ķ���.h"

static int visited[num] = { 0 };
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

graph* CreateAdjArray(graph *G);//����ͼ���ڽӾ������㷨
void Creat(graph *G);//����ͼ�����㷨��������
void FreeVisit();//���visit�Է�ֹ���α���
void AllDFSA(graph *G, int i);//ͼ�ı������㷨
void Calcuate(graph *G);//������׾���ĺ���

void Calcuate(graph *G)
{
	float x, y, a;
	//��ʼ���ڽӾ���
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			G->arcs[i][j] = 0;
		}

	//������벢д���ڽӾ��� 
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			x = position[i][0] - position[j][0];
			y = position[i][1] - position[j][1];
			a = sqrt(x*x + y * y);
			//���ڽӾ���ֵ 
			G->arcs[i][j] = a;
			G->arcs[j][i] = a;
		}
	}

}

//����ͼ���ڽӾ������㷨
graph* CreateAdjArray(graph *G)
{
	int i = 0, j;
	char test[num];
	float x, y, a;
	printf("���� # �Խ�����������(�ص�����󳤶�Ϊ128���ص�������Ϊ128����λΪkm)\n");
	//for (i = 0; i < num; i++)
	while(true)
	{
		loop : scanf("%s", &test);
		if (strcmp(test,"#") == 0)
		{
			printf("***�ѽ������룬�Ѿ������ͼ�Ľ�������㣡������������***");
			break;
		}
		else
		{
			if (JudgeA(G, i, test))
			{
				strcpy(G->vex[i], test);
			}
			else
			{
				printf("��⵽��������ͬһ��������������ȷ�ϲ�������Ҫ����ĵ�����\n");
				goto loop;
			}
			
		}
		//scanf("%s", &G->vex[i]); //����ص� 
		
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &position[i][j]);//��������
		}

		if (JudgeB(G, i, position))
		{
			i++;
		}
		else
		{
			printf("��⵽���������ظ������꣬������ȷ�ϲ�������Ҫ����ĵ��������꣡\n");
			goto loop;
		}
	}
	len = i;

	Calcuate(G);

	return G;
}

//ͼ�ı���
void DFSA(graph *G, int i)
{
	int j;
	printf("%s	", G->vex[i]);
	visited[i] = 1;
	for (j = 0; j < len; j++)
	{
		if (G->arcs[i][j] != 0 && visited[j] == 0)
			DFSA(G, j);
	}
}

void FreeVisit()
{
	for (int i = 0; i < num; i++)
	{
		visited[i] = 0;
	}
}

void AllDFSA(graph *G, int i)
{
	printf("\n������ĵص�Ϊ:\n");
	DFSA(G, 0);
	FreeVisit();
}

void Creat(graph *G)
{
	G->i = 1;
	G = CreateAdjArray(G);
	AllDFSA(G, 0);
	system("pause");
}
