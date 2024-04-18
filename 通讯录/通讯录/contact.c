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
		printf("����������->");
		scanf("%s", ct->PI[ct->size].name);
		int i = 0;
		for (i = 0; i < ct->size; i++)
		{
			if (strcmp(ct->PI[ct->size].name,ct->PI[i].name)==0)
			{
				printf("�����ظ������������/��ȡ���ǳư�^_^\n");
				flag = 1;
				break;
			}
			else
			{
				flag = 0;
			}
		}
	} while (flag==1);

	printf("�������Ա�->");
	scanf("%s", ct->PI[ct->size].sex);
	printf("����������->");
	scanf("%d", &ct->PI[ct->size].age);
	do {
		printf("������绰->");
		scanf("%s", ct->PI[ct->size].tel);
		if(strlen(ct->PI[ct->size].tel)!=11)
		{
			printf("�绰���벻�Ϸ�������������\n");
		}
		else
		{
			break;
		}
	} while (1);
	printf("�������ַ->");
	scanf("%s", ct->PI[ct->size].address);
	ct->size++;
}

void ShowContact(const Contact* ct)
{
	if (ct->size==0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	for (int i = 0; i < ct->size; i++)
	{
		printf("%d:\n���֣�%s \n�Ա�%s \n���䣺%d \n�绰��%s \n��ַ��%s\n",
			i+1,ct->PI[i].name, ct->PI[i].sex, ct->PI[i].age, ct->PI[i].tel, ct->PI[i].address);
	}
}

void DelContact(Contact* ct)
{
	if(ct->size==0)
	{
		printf("\nͨѶ¼Ϊ��!\n");
		return;
	}
	printf("����ɾ˭��\n");
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
		printf("û�������\n");
		return;
	}
	for (j = i; j < ct->size - 1; j++)
	{
		ct->PI[j] = ct->PI[j + 1];
	}
	ct->size--;
	printf("ɾ����ϣ�\n");
}

void FindContact(Contact* ct)
{
	if (ct->size == 0)
	{
		printf("\nͨѶ¼Ϊ��!\n");
		return;
	}
	printf("������˭->");
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
		printf("û�������\n");
		return;
	}
	else
	{
		printf("���֣�%s \n�Ա�%s \n���䣺%d \n�绰��%s \n��ַ��%s\n",
			ct->PI[i].name, ct->PI[i].sex, ct->PI[i].age, ct->PI[i].tel, ct->PI[i].address);
	}
}

void ModContact(Contact* ct)
{
	if (ct->size == 0)
	{
		printf("\nͨѶ¼Ϊ��!\n");
		return;
	}
	printf("�����޸�˭����Ϣ->");
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
		printf("û�������\n");
		return;
	}
	else
	{
		int cflag = 0;
		do {
			printf("�����޸���/����ʲô��Ϣ?\n");
			printf("1.����\n");
			printf("2.�Ա�\n");
			printf("3.����\n");
			printf("4.�绰\n");
			printf("5.��ַ\n");
			int choice = 0;
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				printf("�������µ�����->");
				scanf("%s", ct->PI[i].name);
				break;
			case 2:
				printf("�������µ��Ա�->");
				scanf("%s", ct->PI[i].sex);
				break;
			case 3:
				printf("�������µ�����->");
				scanf("%d", &(ct->PI[i].age));
				break;
			case 4:
				printf("�������µĵ绰->");
				scanf("%s", ct->PI[i].tel);
				break;
			case 5:
				printf("�������µĵ�ַ->");
				scanf("%s", ct->PI[i].address);
				break;
			default:
				printf("������ѡ��\n");
				break;
			}
			printf("�޸ĳɹ����Ƿ�����޸ģ�(y/n)\n");
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