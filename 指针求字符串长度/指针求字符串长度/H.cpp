#include<stdio.h>
int main()
{
	int zifu(char a[]);
	int i;
	char a[100];
	printf("����һ���ַ���\n");
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
	while( a[i] != '\0')//���ַ�������
	{
		n++;
		i++;
	}
	return n;
}