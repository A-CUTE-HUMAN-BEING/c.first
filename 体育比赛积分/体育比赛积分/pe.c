#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define MAX 20//定义不可加分号，也不可加等号，
int count= 0;//队伍数量
struct team//定义结构体
{
	char name_stu[MAX];//学院
	char name[MAX];//定义姓名记得给姓名数组中定义一个数字范围
    int score;
};

struct team p[MAX];
void menu()//菜单
{
	printf("\t\t**********************************\n");
	printf("\t\t***1--   登记队伍名称以及分数   ***\n");
	printf("\t\t***2--查看队伍名称、分数以及排名***\n");
	printf("\t\t***3--    修改队伍名称或分数    ***\n");
	printf("\t\t***4--         增加积分         ***\n");
	printf("\t\t***5--         删除队伍         ***\n");
	printf("\t\t***6--         退出         ***\n");
	printf("\n");
	printf("\t\t**********************************\n");
}
void add()//
{
	if (count <MAX)//定义限制条件
	{
		printf("\t\t**输入专业名称(请输入四字）**：\n");
		scanf_s("%s", &p[count].name_stu, MAX);
		printf("\t\t**输入队伍名称（请输入三到四字）**：\n");
		scanf_s("%s", &p[count].name,MAX);
		for (int a = 0; a <= count - 1; a++)
		{
			if (p[count].name == p[a].name)
			{
				printf("名字重复，请重新输入：");
				scanf_s("%s", &p[count].name, MAX);
			}
		}
		printf("\t\t**输入队伍分数**：\n");
		scanf_s("%d", &p[count].score);
		printf("\t\t**录入成功!**\n");
		count++;
		printf("\t\t**现在已有%d支队伍**\n",count);
		printf("\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("\t\t****!!!队伍已满，请修改!");
		return;//返回重新选择
	}
	int j,t;
	int a;
	char name[MAX]={0};
	for(a=0;a<count;a++)
	{
		for (j = a + 1; j < count; j++)
		{
			if (p[a].score < p[j].score)//比较两个分数大小 将分数高的队伍放到前面
			{
				
				name, p[a].name;//先定义一个空数组 然后交换名字
				p[a].name, p[j].name;
				p[j].name, name;
				t = p[j].score;//先定义一个空的空间 然后交换两个数字
				p[j].score = p[a].score;
				p[a].score = t;
				
			}
		}
	}
	}//
void show()
{
	int a;
	printf("**排名\t*\t专业\t\t*\t队伍名称\t*\t成绩\t**\n");
	for (a = 0; a < count; a++)
	{
		if (p[a].score== p[a-1].score	 )
			printf("**%d\t*", a);
		else
		printf("**%d\t*",a+1);
		printf("\t%s\t*\t%s\t\t*\t%d\t**\n", p[a].name_stu,p[a].name, p[a].score);
		printf("\n");
		//编写代码，演示多个字符从两端移动，向中间汇聚
		{
			char arr1[] = "恭喜第一名队伍！！！其他队伍也要继续努力！！！";
			char arr2[] = "##############################################";
			int left = 0;
			int right = strlen(arr2) - 1;//strlen是求数组长度，在string.h中，  数组的下标是从0开始，所以-1.
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
	printf("\t**输入你想修改的队伍名称：\n");
	scanf_s("%s", &name,MAX);
	for ( a= 0; a < count; a++)
	{
		if (strcmp(name, p[a].name) == 0)//strcmp函数 ==0时表示name=p[a].name
		{
			printf("\t**输入该队伍新名称：\n");
			scanf_s("%s", &p[a].name, MAX);
			printf("\t**输入新分数：\n");
			scanf_s("%d", &p[a].score);
			printf("\t**更改成功\n");
			f = 1;
		}
	}
	if (f == 0)
	{
		printf("\t\t***没有找到该队伍！\n");
	}
		for (a = 0; a< count - 1; a++)
		{
			for (j = a + 1; j < count; j++)
			{
				if (p[a].score < p[j].score)
				{
					t = p[j].score;//交换两个数字
					p[j].score = p[a].score;
					p[a].score = t;
					name, p[a].name;//交换两个名字
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
	printf(" \t**请输入要删除的队伍名称：\n");
	scanf_s("%s", &name,MAX);
	for (a = 0; a < count; a++)
	{
		if (strcmp(name, p[a].name) == 0)//寻找相同的名字
		{
			for (j = a; j < count - 1; j++)  //除去找到的队伍，其余队伍向前排列
			{
				p[j] = p[j + 1];
			}
			count--;
			printf("\t\t**成功删除\n");
			f = 1;
		}
	}
		if(f==0)
		{
			printf("\t\t**没有此队伍：\n");
		}
		system("pause");
		system("cls");
}
int main()
{
	printf("\t\t***欢迎使用体育比赛积分系统！***\n");
	printf("\n");
	while (1)
	{
		menu();
		printf("\t**请选择你需要的选项：\n");
		char input = _getch();
		switch (input)
		{
		case '1':
			add();//录入学生信息
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
		{printf("\t\t**输入错误 请重新输入\n");
		printf("\n");
		break; }
		}
	}
	return 0;
}                                    