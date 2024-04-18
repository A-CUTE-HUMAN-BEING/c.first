#include<stdio.h>
#include<string.h>
struct dingcan {
    char name[10];
    int s;
    char time[10];
    int number;
}GuestList[3];
void Insert(int* count)
{
    int i, anumber;
    if (*count == 3)
    {
        printf("没位置了\n");
        return;
    }
    printf("输入房间编号：");
    scanf_s("%d", &anumber);
    for (i = 0; i < *count; i++)
        if (GuestList[i].number == anumber)
        {
            printf("已经有相同的编号:\n");
            return;
        }
    GuestList[i].number = anumber;
    printf("请输入姓名:");
    scanf_s("%s", GuestList[i].name, 11);
    printf("请输入人数:");
    scanf_s("%d", &GuestList[i].s);
    printf("请输入用餐时间:");
    scanf_s("%s", GuestList[i].time, 11);
    (*count)++;
}
void Search(int count)
{
    int i, anumber, flag = 1;
    printf("请输入要查询的编号:\n");
    scanf_s("%d", &anumber);
    for (i = 0; i < count; i++)
        if (GuestList[i].number == anumber)
        {
            printf("姓名:%s", GuestList[i].name);
            printf("人数:%d", GuestList[i].s);
            printf("用餐时间:%s\n", GuestList[i].time);
            flag = 0;
            break;
        }
    if (flag == 1)
        printf("没查询到\n");
}
void Update(int count)
{
    int i, anumber, flag = 1;
    printf("请输入要修改数据的编号\n:");
    scanf_s("%d", &anumber);
    for (i = 0; i < count; i++)
        if (GuestList[i].number == anumber)
        {
            printf("请输入新人数:");
            scanf_s("%d", &GuestList[i].s);
            printf("请输入新用餐时间:");
            scanf_s("%s", GuestList[i].time, 11);
            flag = 0;
            break;
        }
    if (flag == 1)
        printf("没有查询到可以修改的数据\n");
}
void Delete(int* count)
{
    int i, j, anumber, flag = 0;
    printf("请输人要删除数据的编号:\n");
    scanf_s("%d", &anumber);
    for (i = 0; i < *count; i++)
    {
        if (GuestList[i].number == anumber)
        {
            for (j = i; j < *count - 1; j++)
                GuestList[j] = GuestList[j + 1];
            (*count)--;
            flag = 0;
            break;
        }
        if (flag == 1)
            printf("没有查询到数据\n");
    }
}
void Show(int count)
{
    int i;
    printf("\n");
    for (i = 0; i < count; i++)
    {
        printf("编号：%d", GuestList[i].number);
        printf(" 姓名：%s", GuestList[i].name);
        printf(" 人数：%d", GuestList[i].s);
        printf(" 用餐时间：%s\n", GuestList[i].time);
    }
}
int main()
{
    int i, count = 0;
    do {
        printf("1--插入\n");
        printf("2--查找\n");
        printf("3--修改\n");
        printf("4--显示\n");
        printf("5--删除\n");
        printf("6--退出\n");
        scanf_s("%d", &i);
        switch (i)
        {
        case 1:
            Insert(&count); break;
        case 2:
            Search(count); break;
        case 3:
            Update(count); break;
        case 4:
            Show(count); break;
        case 5:
            Delete(&count); break;
        case 6:break;
        default:printf("输入错误\n"); break;
        }
    } while (i != 6);
    return  0;
}