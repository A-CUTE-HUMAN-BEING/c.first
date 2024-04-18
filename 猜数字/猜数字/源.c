#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**************\n");
	printf("****1--play***\n");
	printf("****0--结束***\n");
	printf("**************\n");
}
void game()
{
	int rat = rand()%100+1;
	int guess = 0;
	while(1)
	{
		scanf_s("%d", &guess);
		if (rat < guess)
			printf("猜大了！\n");
		else if (rat >guess)
			printf("猜小了!\n");
		else
			printf("恭喜你 猜对了！！！\n");
	}
}
int main()
{
	int input = 0;
	int srand = ((unsigned int)time(NULL));
	menu();
	printf("请选择:\n");
	scanf_s("%d", &input);
	do {
		switch (input)
		{
		case 1:
			printf("开始游戏:\n");
			printf("输入你想的数字！！");
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("输入错误！！！\n");
			break;
		}
		}while (input);
		return 0;
}