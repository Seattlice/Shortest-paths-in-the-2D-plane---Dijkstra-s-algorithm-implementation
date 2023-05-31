#pragma once
//图的结构定义 

#define num 128 
#define ege 28 

int len ;//结点的个数
int position[num][2];//记录坐标的数组

typedef struct
{
	int i = 0;//定义是否创建了图
	char vex[num][num];//地点名称
	float arcs[num][num];//邻接矩阵
}graph;

int JudgeA(graph *G, int i, char test[num]);//判断地名是否重复输入
int JudgeB(graph *G, int i, int position[num][2]);//判断坐标是否重复输入

int JudgeB(graph *G, int i, int position[num][2])
{
	for (int k = 0; k < i; k++)
	{
		if ((position[i][1] == position[k][1]) && (position[i][0] == position[k][0]))
		{
			return 0;
		}
	}
	return 1;
}

int JudgeA(graph *G, int i, char test[num])
{
	for (int j = 0; j < i; j++)
	{
		if (strcmp(test, G->vex[j]) == 0)
		{
			return 0;
		}
	}
	return 1;
}
