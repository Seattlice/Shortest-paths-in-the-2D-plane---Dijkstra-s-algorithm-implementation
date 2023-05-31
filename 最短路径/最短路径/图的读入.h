#pragma once
#include <iostream>
#include "图的定义.h"

static int visited[num] = { 0 };
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

graph* CreateAdjArray(graph *G);//无向图的邻接矩阵建立算法
void Creat(graph *G);//无向图建立算法的主程序
void FreeVisit();//清空visit以防止二次便利
void AllDFSA(graph *G, int i);//图的遍历总算法
void Calcuate(graph *G);//计算零阶矩阵的函数

void Calcuate(graph *G)
{
	float x, y, a;
	//初始化邻接矩阵
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			G->arcs[i][j] = 0;
		}

	//计算距离并写入邻接矩阵 
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			x = position[i][0] - position[j][0];
			y = position[i][1] - position[j][1];
			a = sqrt(x*x + y * y);
			//给邻接矩阵赋值 
			G->arcs[i][j] = a;
			G->arcs[j][i] = a;
		}
	}

}

//无向图的邻接矩阵建立算法
graph* CreateAdjArray(graph *G)
{
	int i = 0, j;
	char test[num];
	float x, y, a;
	printf("输入 # 以结束您的输入(地点名最大长度为128，地点最大个数为128，单位为km)\n");
	//for (i = 0; i < num; i++)
	while(true)
	{
		loop : scanf("%s", &test);
		if (strcmp(test,"#") == 0)
		{
			printf("***已结束输入，已经完成了图的建立与计算！请您继续操作***");
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
				printf("检测到您输入了同一个地名，请重新确认并输入您要输入的地名！\n");
				goto loop;
			}
			
		}
		//scanf("%s", &G->vex[i]); //读入地点 
		
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &position[i][j]);//输入坐标
		}

		if (JudgeB(G, i, position))
		{
			i++;
		}
		else
		{
			printf("检测到您输入了重复的坐标，请重新确认并输入您要输入的地名与坐标！\n");
			goto loop;
		}
	}
	len = i;

	Calcuate(G);

	return G;
}

//图的遍历
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
	printf("\n您输入的地点为:\n");
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
