#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define MAX 20//���岻�ɼӷֺţ�Ҳ���ɼӵȺţ�
int count= 0;//��������
struct team//����ṹ��
{
	char name_stu[MAX];//ѧԺ
	char name[MAX];//���������ǵø����������ж���һ�����ַ�Χ
    int score;
};

struct team p[MAX];
void menu()//�˵�
{
	printf("\t\t**********************************\n");
	printf("\t\t***1--   �ǼǶ��������Լ�����   ***\n");
	printf("\t\t***2--�鿴�������ơ������Լ�����***\n");
	printf("\t\t***3--    �޸Ķ������ƻ����    ***\n");
	printf("\t\t***4--         ���ӻ���         ***\n");
	printf("\t\t***5--         ɾ������         ***\n");
	printf("\t\t***6--         �˳�         ***\n");
	printf("\n");
	printf("\t\t**********************************\n");
}
void add()//
{
	if (count <MAX)//������������
	{
		printf("\t\t**����רҵ����(���������֣�**��\n");
		scanf_s("%s", &p[count].name_stu, MAX);
		printf("\t\t**����������ƣ��������������֣�**��\n");
		scanf_s("%s", &p[count].name,MAX);
		for (int a = 0; a <= count - 1; a++)
		{
			if (p[count].name == p[a].name)
			{
				printf("�����ظ������������룺");
				scanf_s("%s", &p[count].name, MAX);
			}
		}
		printf("\t\t**����������**��\n");
		scanf_s("%d", &p[count].score);
		printf("\t\t**¼��ɹ�!**\n");
		count++;
		printf("\t\t**��������%d֧����**\n",count);
		printf("\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("\t\t****!!!�������������޸�!");
		return;//��������ѡ��
	}
	int j,t;
	int a;
	char name[MAX]={0};
	for(a=0;a<count;a++)
	{
		for (j = a + 1; j < count; j++)
		{
			if (p[a].score < p[j].score)//�Ƚ�����������С �������ߵĶ���ŵ�ǰ��
			{
				
				name, p[a].name;//�ȶ���һ�������� Ȼ�󽻻�����
				p[a].name, p[j].name;
				p[j].name, name;
				t = p[j].score;//�ȶ���һ���յĿռ� Ȼ�󽻻���������
				p[j].score = p[a].score;
				p[a].score = t;
				
			}
		}
	}
	}//
void show()
{
	int a;
	printf("**����\t*\tרҵ\t\t*\t��������\t*\t�ɼ�\t**\n");
	for (a = 0; a < count; a++)
	{
		if (p[a].score== p[a-1].score	 )
			printf("**%d\t*", a);
		else
		printf("**%d\t*",a+1);
		printf("\t%s\t*\t%s\t\t*\t%d\t**\n", p[a].name_stu,p[a].name, p[a].score);
		printf("\n");
		//��д���룬��ʾ����ַ��������ƶ������м���
		{
			char arr1[] = "��ϲ��һ�����飡������������ҲҪ����Ŭ��������";
			char arr2[] = "##############################################";
			int left = 0;
			int right = strlen(arr2) - 1;//strlen�������鳤�ȣ���string.h�У�  ������±��Ǵ�0��ʼ������-1.
			while (left <= right)
			{
				Sleep(100);
				system("cls");
				arr2[left] = arr1[left];
				arr2[right] = arr1[right];
				left++;
				right--;
				printf("%s\n", arr2);
			}
		}
	}
	printf("\n");
}
void modify()
{
	int j,t,f=0;
	int a;
	char name[MAX]={0};
	printf("\t**���������޸ĵĶ������ƣ�\n");
	scanf_s("%s", &name,MAX);
	for ( a= 0; a < count; a++)
	{
		if (strcmp(name, p[a].name) == 0)//strcmp���� ==0ʱ��ʾname=p[a].name
		{
			printf("\t**����ö��������ƣ�\n");
			scanf_s("%s", &p[a].name, MAX);
			printf("\t**�����·�����\n");
			scanf_s("%d", &p[a].score);
			printf("\t**���ĳɹ�\n");
			f = 1;
		}
	}
	if (f == 0)
	{
		printf("\t\t***û���ҵ��ö��飡\n");
	}
		for (a = 0; a< count - 1; a++)
		{
			for (j = a + 1; j < count; j++)
			{
				if (p[a].score < p[j].score)
				{
					t = p[j].score;//������������
					p[j].score = p[a].score;
					p[a].score = t;
					name, p[a].name;//������������
					p[a].name, p[j].name;
					p[j].name, name;
				}
			}
		}
		system("pause");
		system("cls");
	}
		
void Delete()
{
	int  j,f=0;
	int a;
	char name[MAX] = { 0 };
	printf(" \t**������Ҫɾ���Ķ������ƣ�\n");
	scanf_s("%s", &name,MAX);
	for (a = 0; a < count; a++)
	{
		if (strcmp(name, p[a].name) == 0)//Ѱ����ͬ������
		{
			for (j = a; j < count - 1; j++)  //��ȥ�ҵ��Ķ��飬���������ǰ����
			{
				p[j] = p[j + 1];
			}
			count--;
			printf("\t\t**�ɹ�ɾ��\n");
			f = 1;
		}
	}
		if(f==0)
		{
			printf("\t\t**û�д˶��飺\n");
		}
		system("pause");
		system("cls");
}
int main()
{
	printf("\t\t***��ӭʹ��������������ϵͳ��***\n");
	printf("\n");
	while (1)
	{
		menu();
		printf("\t**��ѡ������Ҫ��ѡ�\n");
		char input = _getch();
		switch (input)
		{
		case '1':
			add();//¼��ѧ����Ϣ
			break;
		case '2':
			show();
			break;
		case '3':
			modify();
			break;
		case '4':
			Delete();
			break;
		case '5':
			return;
		case 0:
			menu();
			break;
		default:
		{printf("\t\t**������� ����������\n");
		printf("\n");
		break; }
		}
	}
	return 0;
}                                    