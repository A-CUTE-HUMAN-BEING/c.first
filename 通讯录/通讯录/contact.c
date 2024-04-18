#include"contact.h"

void InitContact(Contact* ct)
{
	ct->PI =(P_Info *)malloc(sizeof(P_Info)*4);
	if (ct->PI == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	ct->size = 0;
	ct->capacity = 4;
}

void AddContact(Contact* ct)
{
	if(ct->size==ct->capacity)
	{
		P_Info* tmp = (P_Info*)realloc(ct->PI, ct->capacity * 2 * sizeof(P_Info));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ct->PI = tmp;
		ct->capacity *= 2;
	}
	int flag = 0;
	do {
		printf("请输入名字->");
		scanf("%s", ct->PI[ct->size].name);
		int i = 0;
		for (i = 0; i < ct->size; i++)
		{
			if (strcmp(ct->PI[ct->size].name,ct->PI[i].name)==0)
			{
				printf("名字重复，请另外给他/她取个昵称吧^_^\n");
				flag = 1;
				break;
			}
			else
			{
				flag = 0;
			}
		}
	} while (flag==1);

	printf("请输入性别->");
	scanf("%s", ct->PI[ct->size].sex);
	printf("请输入年龄->");
	scanf("%d", &ct->PI[ct->size].age);
	do {
		printf("请输入电话->");
		scanf("%s", ct->PI[ct->size].tel);
		if(strlen(ct->PI[ct->size].tel)!=11)
		{
			printf("电话号码不合法，请重新输入\n");
		}
		else
		{
			break;
		}
	} while (1);
	printf("请输入地址->");
	scanf("%s", ct->PI[ct->size].address);
	ct->size++;
}

void ShowContact(const Contact* ct)
{
	if (ct->size==0)
	{
		printf("通讯录为空\n");
		return;
	}
	for (int i = 0; i < ct->size; i++)
	{
		printf("%d:\n名字：%s \n性别：%s \n年龄：%d \n电话：%s \n地址：%s\n",
			i+1,ct->PI[i].name, ct->PI[i].sex, ct->PI[i].age, ct->PI[i].tel, ct->PI[i].address);
	}
}

void DelContact(Contact* ct)
{
	if(ct->size==0)
	{
		printf("\n通讯录为空!\n");
		return;
	}
	printf("你想删谁？\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < ct->size; i++)
	{
		if(strcmp(ct->PI[i].name,name)==0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("没有这个人\n");
		return;
	}
	for (j = i; j < ct->size - 1; j++)
	{
		ct->PI[j] = ct->PI[j + 1];
	}
	ct->size--;
	printf("删除完毕！\n");
}

void FindContact(Contact* ct)
{
	if (ct->size == 0)
	{
		printf("\n通讯录为空!\n");
		return;
	}
	printf("你想找谁->");
	char name[MAX_NAME];
	scanf("%s", name);
	int i = 0;
	int flag = 0;
	for (i = 0; i < ct->size; i++)
	{
		if (strcmp(ct->PI[i].name, name) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("没有这个人\n");
		return;
	}
	else
	{
		printf("名字：%s \n性别：%s \n年龄：%d \n电话：%s \n地址：%s\n",
			ct->PI[i].name, ct->PI[i].sex, ct->PI[i].age, ct->PI[i].tel, ct->PI[i].address);
	}
}

void ModContact(Contact* ct)
{
	if (ct->size == 0)
	{
		printf("\n通讯录为空!\n");
		return;
	}
	printf("你想修改谁的信息->");
	char name[MAX_NAME];
	scanf("%s", name);
	int i = 0;
	int flag = 0;
	for (i = 0; i < ct->size; i++)
	{
		if (strcmp(ct->PI[i].name, name) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("没有这个人\n");
		return;
	}
	else
	{
		int cflag = 0;
		do {
			printf("你想修改他/她的什么信息?\n");
			printf("1.名字\n");
			printf("2.性别\n");
			printf("3.年龄\n");
			printf("4.电话\n");
			printf("5.地址\n");
			int choice = 0;
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				printf("请输入新的名字->");
				scanf("%s", ct->PI[i].name);
				break;
			case 2:
				printf("请输入新的性别->");
				scanf("%s", ct->PI[i].sex);
				break;
			case 3:
				printf("请输入新的年龄->");
				scanf("%d", &(ct->PI[i].age));
				break;
			case 4:
				printf("请输入新的电话->");
				scanf("%s", ct->PI[i].tel);
				break;
			case 5:
				printf("请输入新的地址->");
				scanf("%s", ct->PI[i].address);
				break;
			default:
				printf("请重新选择\n");
				break;
			}
			printf("修改成功，是否继续修改？(y/n)\n");
			char a;
			scanf(" %c", &a);
			if (a == 'y')
			{
				cflag = 1;
			}
			if (a == 'n')
			{
				cflag = 0;
			}
		} while (cflag == 1);
	}
}