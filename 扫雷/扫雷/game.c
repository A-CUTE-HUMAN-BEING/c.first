#include"game.h"

void InitBoard(char board[ROWS][COWS], int row, int cow,char some)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<cow;j++)
		{
			board[i][j] = some;
		}
	}
}
void DisPlay(char board[ROWS][COWS], int row, int cow)
{
	int i = 0;
	int j = 0;
	printf("**********ÓÎÏ·¿ªÊ¼**********\n");
	for (i = 0; i < row+1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row+1; i++)
	{
		printf("%d", i);
		for (j = 1; j < cow+1; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}

void GetMind(char board[ROWS][COWS], int row, int cow)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int Count(char mind[ROWS][COWS], int x, int y)
{
	int num = 0;
	if(mind[x - 1][y] == '1')
	{
		num++;
	}
	if (mind[x + 1][y] == '1')
	{
		num++;
	}
	if (mind[x][y - 1] == '1')
	{
		num++;
	}
	if (mind[x][y + 1] == '1')
	{
		num++;
	}
	if (mind[x - 1][y - 1] == '1')
	{
		num++;
	}
	if (mind[x - 1][y + 1] == '1')
	{
		num++;
	}
	if (mind[x + 1][y - 1] == '1')
	{
		num++;
	}
	if (mind[x + 1][y + 1] == '1')
	{
		num++;
	}
	return num;
}
void FindMind(char mind[ROWS][COWS], char show[ROWS][COWS], int row, int cow)
{
	int x=0;
	int y=0;
	int win = 0;
	while (ROW * COW - EASY_COUNT >win)
	{
		printf("ÇëÊäÈë×ø±ê\n");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= cow)
		{
			if (mind[x][y] == '1')
			{
				printf("**********************\n");
				printf("********²ÈÀ×À²********\n");
				printf("**********************\n");
				break;
			}
			else
			{
				int count = 0;
				count = Count(mind, x, y);
				show[x][y] =count + '0';
				DisPlay(show, ROW, COW);
				win++;
			}
		}
		else
		{
			printf("ÊäÈë´íÎó\n");
		}
	}
	if(ROW * COW - EASY_COUNT == win)
	{
		printf("**********************\n");
		printf("***¹§Ï²Äã£¬É¨À×³É¹¦***\n");
		printf("**********************\n");
	}
}