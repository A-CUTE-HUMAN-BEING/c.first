#include<stdio.h>
int flag = 1;
int main()
{
	int sushu(int a);
	int a;
	printf("����һ�����ж��Ƿ�Ϊ����:");
	scanf_s("%d", &a);
	sushu(a);
	if (flag == 1)
		printf("������");
	if (!flag)
		printf("��������");
}
int sushu(int a)
{
	int n;
	for (n = 2; n < a && flag == 1; n++)
		a% n == 0 ? flag = 0: flag = 1;
	return flag;
}