#pragma once
#include "ͼ�Ķ���.h"
#include "ͼ�Ķ���.h"
#include <iostream>
#include <math.h>
using namespace std;

void Add(graph* G);//����ͼ�ĺ���
void AllAdd(graph *G);//����ͼ���ܺ���

void Add(graph *G)
{
	char test[num];
	printf("���� # �Խ�����������(�ص�����󳤶�Ϊ128���ص�������Ϊ128����λΪkm)\n");

	while (true)
	{
	loop: scanf("%s", &test);

			if (strcmp(test, "#") == 0)
			{
				printf("\n***�ѽ������룬�Ѿ������ͼ�Ľ�������㣡������������***\n");
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
					printf("��⵽��������ͬһ��������������ȷ�ϲ�������Ҫ����ĵ�����\n");
					goto loop;
				}

			}

			for (int j = 0; j < 2; j++)
			{
				scanf("%d", &position[len][j]);//��������
			}

			if (JudgeB(G, len, position))
			{
				len++;
			}
			else
			{
				printf("��⵽���������ظ������꣬������ȷ�ϲ�������Ҫ����ĵ��������꣡\n");
				goto loop;
			}
	}

}


void AllAdd(graph *G)
{
	cout << "��������Ҫ����ĵص�������" << endl;
	Add(G);
	AllDFSA(G, 0);
	Calcuate(G);
	cout << "\n����ص㹦���Ѿ���ɣ����������\n" << endl;
	system("pause");
}