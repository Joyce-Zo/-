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
	// 1 创建数组-存放棋盘信息
	char board[ROW][COL] = { 0 };
	// 2.初始化棋盘，全部初始化为空格
	InitBoard(board, ROW, COL);
	// 3.打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		// 1. 玩家走
		PlayerMove(board, ROW, COL);
		//  打印棋盘
		DisplayBoard(board, ROW, COL);
		// 判断玩家是否赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		// 2.电脑走
		ComputerMove(board, ROW, COL);
		//  打印棋盘
		DisplayBoard(board, ROW, COL);
		// 判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void game_1()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
}

int main()
{
	game_1();
	return 0;
}