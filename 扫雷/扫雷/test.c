#include"game.h"

void menu()
{
	printf("***********************\n");
	printf("******  1.play  *******\n");
	printf("******  2.exit  *******\n");
	printf("***********************\n");
}
void game()
{
	char mind[ROWS][COWS] = { 0 };
	char show[ROWS][COWS] = { 0 };
	//初始化棋盘
	InitBoard(mind, ROWS, COWS,'0');
	InitBoard(show, ROWS, COWS,'*');
	//打印棋盘
	//DisPlay(mind, ROW, COW);
	DisPlay(show, ROW, COW);
	//布雷
	GetMind(mind, ROW, COW);
	DisPlay(mind, ROW, COW);
	FindMind(mind,show, ROW,COW);
	
}
int main()
{
	while (1)
	{
		menu();
		printf("->");
		int input;
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			exit(0);
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}
}