#include "Dj�㷨����.h"
#include "ͼ�Ķ���.h"
#include <iostream>
#include "չʾ����.h"
#include "ͼ�Ķ���.h"
#include "����ص�.h"
#include "ɾ���ص�.h"
#include "��ӡ���.h"
using namespace std;

int main()
{
	graph *G;
	G = new graph;
	int choice;//ѡ���flag
	while (true)
	{
		Show_Menu();//չʾ�ĺ���
		cin >> choice;
		switch (choice)
		{
			case 1://����ͼ����ͼ������
				if (G->i)
				{
					cout << "���Ѿ������˲�������һ��ͼ����ѡ����������ص���߼�����ӵص�" << endl;
					system("pause");
				}
				else
				{
					Creat(G);
				}
				
				system("cls");
				break;
			case 2:
				if (G->i)
				{
					Dj(G);
				}
				else
				{
					cout << "***����δ����ͼ��������ص㴴��һ��ͼŶ��***" << endl;
					system("pause");
				}				
				system("cls");
				break;
			case 3://��������ص�
				if (G->i)
				{
					AllAdd(G);
				}
				else
				{
					cout << "***����δ����ͼ��������ص㴴��һ��ͼŶ��***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 4://���ͼ�Լ����ߵ�Ȩֵ
				if (G->i)
				{
					Print(G);
				}
				else
				{
					cout << "***����δ����ͼ��������ص㴴��һ��ͼŶ��***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 5://ɾ��ͼ
				if (G->i)
				{
					DeleteGraph(G);
					cout << "****��������ͼ�Ѿ���ɾ����***" << endl;
					system("pause");
				}
				else
				{
					cout << "***����δ����ͼ��������ص㴴��һ��ͼŶ��***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 6://ɾ��ͼ
				if (G->i)
				{
					AllKill(G);
				}
				else
				{
					cout << "***����δ����ͼ��������ص㴴��һ��ͼŶ��***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 0://�˳�ѭ��
				exitSystem();

			default://����
				system("cls");
				cout << "*********��������ȷ��ѡ��**************" << endl;
				cout << endl;
				break;
		}
		cin.clear();
		cin.ignore();
	}
	system("pause");
	return 0;
}
/*
���� 378 78
���� 327 119
���� 232 266
��� 314 311
��¡�� 255 477
�¼��� 296 513
���� 510 438
������ 628 246
*/