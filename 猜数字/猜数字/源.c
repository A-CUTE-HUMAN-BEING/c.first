#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**************\n");
	printf("****1--play***\n");
	printf("****0--����***\n");
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
			printf("�´��ˣ�\n");
		else if (rat >guess)
			printf("��С��!\n");
		else
			printf("��ϲ�� �¶��ˣ�����\n");
	}
}
int main()
{
	int input = 0;
	int srand = ((unsigned int)time(NULL));
	menu();
	printf("��ѡ��:\n");
	scanf_s("%d", &input);
	do {
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ:\n");
			printf("������������֣���");
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("������󣡣���\n");
			break;
		}
		}while (input);
		return 0;
}