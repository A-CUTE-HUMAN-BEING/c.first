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
        printf("ûλ����\n");
        return;
    }
    printf("���뷿���ţ�");
    scanf_s("%d", &anumber);
    for (i = 0; i < *count; i++)
        if (GuestList[i].number == anumber)
        {
            printf("�Ѿ�����ͬ�ı��:\n");
            return;
        }
    GuestList[i].number = anumber;
    printf("����������:");
    scanf_s("%s", GuestList[i].name, 11);
    printf("����������:");
    scanf_s("%d", &GuestList[i].s);
    printf("�������ò�ʱ��:");
    scanf_s("%s", GuestList[i].time, 11);
    (*count)++;
}
void Search(int count)
{
    int i, anumber, flag = 1;
    printf("������Ҫ��ѯ�ı��:\n");
    scanf_s("%d", &anumber);
    for (i = 0; i < count; i++)
        if (GuestList[i].number == anumber)
        {
            printf("����:%s", GuestList[i].name);
            printf("����:%d", GuestList[i].s);
            printf("�ò�ʱ��:%s\n", GuestList[i].time);
            flag = 0;
            break;
        }
    if (flag == 1)
        printf("û��ѯ��\n");
}
void Update(int count)
{
    int i, anumber, flag = 1;
    printf("������Ҫ�޸����ݵı��\n:");
    scanf_s("%d", &anumber);
    for (i = 0; i < count; i++)
        if (GuestList[i].number == anumber)
        {
            printf("������������:");
            scanf_s("%d", &GuestList[i].s);
            printf("���������ò�ʱ��:");
            scanf_s("%s", GuestList[i].time, 11);
            flag = 0;
            break;
        }
    if (flag == 1)
        printf("û�в�ѯ�������޸ĵ�����\n");
}
void Delete(int* count)
{
    int i, j, anumber, flag = 0;
    printf("������Ҫɾ�����ݵı��:\n");
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
            printf("û�в�ѯ������\n");
    }
}
void Show(int count)
{
    int i;
    printf("\n");
    for (i = 0; i < count; i++)
    {
        printf("��ţ�%d", GuestList[i].number);
        printf(" ������%s", GuestList[i].name);
        printf(" ������%d", GuestList[i].s);
        printf(" �ò�ʱ�䣺%s\n", GuestList[i].time);
    }
}
int main()
{
    int i, count = 0;
    do {
        printf("1--����\n");
        printf("2--����\n");
        printf("3--�޸�\n");
        printf("4--��ʾ\n");
        printf("5--ɾ��\n");
        printf("6--�˳�\n");
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
        default:printf("�������\n"); break;
        }
    } while (i != 6);
    return  0;
}