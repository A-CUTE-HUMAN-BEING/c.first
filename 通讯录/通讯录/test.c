#include"contact.h"

void menu()
{
	printf("\n********  通讯录  ********\n");
	printf("**************************\n");
	printf("***   1、add  2、del   ***\n");
	printf("***   3、find 4、mod   ***\n");
	printf("***   5、show          ***\n");
	printf("***   0、exit          ***\n");
	printf("**************************\n");
	printf("**************************\n\n");
}
void test()
{
	Contact ct;
	InitContact(&ct);
	do
	{
		menu();
		int input = 0;
		printf("请选择你想进行的操作->");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				AddContact(&ct);
				break;
			case DEL:
				DelContact(&ct);
				break;
			case FIND:
				FindContact(&ct);
				break;
			case MOD:
				ModContact(&ct);
				break;
			case SHOW:
				ShowContact(&ct);
				break;
			case EXIT:
				exit(0);
				break;
			default:
				printf("\n输入错误，请重新输入:\n");
				break;
		}
	}while(1);
}

int main()
{
	test();
	return 0;
}