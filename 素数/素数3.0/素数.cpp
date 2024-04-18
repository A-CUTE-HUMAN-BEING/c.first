#include<stdio.h>
int flag = 1;
int main()
{
	int sushu(int a);
	int a;
	printf("输入一个数判断是否为素数:");
	scanf_s("%d", &a);
	sushu(a);
	if (flag == 1)
		printf("是素数");
	if (!flag)
		printf("不是素数");
}
int sushu(int a)
{
	int n;
	for (n = 2; n < a && flag == 1; n++)
		a% n == 0 ? flag = 0: flag = 1;
	return flag;
}