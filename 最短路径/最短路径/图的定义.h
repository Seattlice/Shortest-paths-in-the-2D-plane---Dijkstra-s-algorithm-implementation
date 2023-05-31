#pragma once
//ͼ�Ľṹ���� 

#define num 128 
#define ege 28 

int len ;//���ĸ���
int position[num][2];//��¼���������

typedef struct
{
	int i = 0;//�����Ƿ񴴽���ͼ
	char vex[num][num];//�ص�����
	float arcs[num][num];//�ڽӾ���
}graph;

int JudgeA(graph *G, int i, char test[num]);//�жϵ����Ƿ��ظ�����
int JudgeB(graph *G, int i, int position[num][2]);//�ж������Ƿ��ظ�����

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
