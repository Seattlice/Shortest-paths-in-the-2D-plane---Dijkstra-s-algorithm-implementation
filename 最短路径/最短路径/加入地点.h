#pragma once
#include "图的定义.h"
#include "图的读入.h"
#include <iostream>
#include <math.h>
using namespace std;

void Add(graph* G);//加入图的函数
void AllAdd(graph *G);//加入图的总函数

void Add(graph *G)
{
	char test[num];
	printf("输入 # 以结束您的输入(地点名最大长度为128，地点最大个数为128，单位为km)\n");

	while (true)
	{
	loop: scanf("%s", &test);

			if (strcmp(test, "#") == 0)
			{
				printf("\n***已结束输入，已经完成了图的建立与计算！请您继续操作***\n");
				break;
			}
			else
			{
				if (JudgeA(G, len, test))
				{
					strcpy(G->vex[len], test);
				}
				else
				{
					printf("检测到您输入了同一个地名，请重新确认并输入您要输入的地名！\n");
					goto loop;
				}

			}

			for (int j = 0; j < 2; j++)
			{
				scanf("%d", &position[len][j]);//输入坐标
			}

			if (JudgeB(G, len, position))
			{
				len++;
			}
			else
			{
				printf("检测到您输入了重复的坐标，请重新确认并输入您要输入的地名与坐标！\n");
				goto loop;
			}
	}

}


void AllAdd(graph *G)
{
	cout << "请输入您要加入的地点与坐标" << endl;
	Add(G);
	AllDFSA(G, 0);
	Calcuate(G);
	cout << "\n加入地点功能已经完成，请继续操作\n" << endl;
	system("pause");
}