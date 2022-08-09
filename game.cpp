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
		// 1.��ӡ  һ�е�����
		//printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
		//  ��д������low���������в���3*3ʱ����ֻ�����3��
		for (j = 0; j < col ; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		// 2.��ӡ  �ָ���
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
	printf("�����->\n");
	while (1)
	{
		printf("������Ҫ�ߵ����꣺");
		scanf("%d%d", &x, &y);
		//  �ж� x y ����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�ռ��");
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������:\n");
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

//	�ж� �Ƿ�ƽ�� - �����Ƿ�����
//  ���˷���1��û������0
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

//����״̬:
//  1. ���Ӯ - *   
//  2. ����Ӯ - #
//  3.ƽ��    - Q
//  4.����    - C

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//   �ж� ������ �Ƿ����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][1];
		}
	}
	//   �ж� ������ �Ƿ����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[1][i];
		}
	}
	//  �ж� ���Խ��� �Ƿ����
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