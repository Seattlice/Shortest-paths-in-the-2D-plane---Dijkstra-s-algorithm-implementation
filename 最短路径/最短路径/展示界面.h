#pragma once
#include <iostream>
#include "ͼ�Ķ���.h"

using namespace std;

void Show_Menu();//չʾ�ĺ���
void exitSystem();//�˳��ĺ���
void DeleteGraph(graph *G);//ɾ��ͼ�ĺ���

void Show_Menu()//չʾ�ĺ���
{
	cout << "******************************************************" << endl;
	cout << "******��ӭʹ�����м���ͼ��������������ִ�в�����******" << endl;
	cout << "************* 1����������Ҫ����ĵص��Լ����� ********" << endl;
	cout << "************* 2������ҪѰ�ҵ����·��         ********" << endl;
	cout << "************* 3����������ص�������           ********" << endl;
	cout << "************* 4������Ѿ�����ĵص���Ȩֵ     ********" << endl;
	cout << "************* 5����յ�ǰ��¼�ĵص�������     ********" << endl;
	cout << "************* 6��ɾ����¼�ĵص�������         ********" << endl;
	cout << "************* 0���˳�ϵͳ		      ********" << endl;
	cout << "******************************************************" << endl;
	cout << "����������ѡ��:" << endl;
}

void exitSystem()//�˳��ĺ���
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void DeleteGraph(graph *G)
{
	cout << "���ٴ�ȷ�����Ƿ�Ҫ���ͼ�أ�" << endl;
	cout << "1���ǵ�" << endl;
	cout << "0��������һ��" << endl;
	int a;
	cin >> a;
	while (true)
	{
		switch(a)
		{
			case 1:
				free(G);
				G = new graph;
				G->i = 0;
				cout << "ͼ�Ѿ����" << endl;
			case 0:
				return;
				cout << "�ѷ���" << endl;

		}
	}

}