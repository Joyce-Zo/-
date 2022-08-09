#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		// 1.打印  一行的数据
		//printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
		//  该写法过于low，当行与列不是3*3时，他只能输出3列
		for (j = 0; j < col ; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		// 2.打印  分隔符
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j<col-1)
				printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走->\n");
	while (1)
	{
		printf("请输入要走的坐标：");
		scanf("%d%d", &x, &y);
		//  判断 x y 坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用");
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑走:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//	判断 是否平局 - 棋盘是否满了
//  满了返回1，没满返回0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//四种状态:
//  1. 玩家赢 - *   
//  2. 电脑赢 - #
//  3.平局    - Q
//  4.继续    - C

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//   判断 横三行 是否相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][1];
		}
	}
	//   判断 纵三行 是否相等
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[1][i];
		}
	}
	//  判断 两对角线 是否相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][0] != ' ')
	{
		return board[0][2];
	}
	if (1 == IsFull(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}