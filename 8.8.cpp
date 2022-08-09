#include "game.h"

void menu()
{
	printf("************************\n");
	printf("**** 1.Play  0.Quit ****\n");
	printf("************************\n");
}

void game()
{
	char ret = 0;
	// 1 ��������-���������Ϣ
	char board[ROW][COL] = { 0 };
	// 2.��ʼ�����̣�ȫ����ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);
	// 3.��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		// 1. �����
		PlayerMove(board, ROW, COL);
		//  ��ӡ����
		DisplayBoard(board, ROW, COL);
		// �ж�����Ƿ�Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		// 2.������
		ComputerMove(board, ROW, COL);
		//  ��ӡ����
		DisplayBoard(board, ROW, COL);
		// �жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

void game_1()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (input);
}

int main()
{
	game_1();
	return 0;
}