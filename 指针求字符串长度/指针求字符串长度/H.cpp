#include<stdio.h>
int main()
{
	int zifu(char a[]);
	int i;
	char a[100];
	printf("输入一串字符：\n");
	gets_s(a);
	i = zifu(a);
	printf("%d", i);
	return 0;

}
int zifu(char a[])
{
	int n;
	n = 0;
	int i = 0;
	while( a[i] != '\0')//求字符串长度
	{
		n++;
		i++;
	}
	return n;
}