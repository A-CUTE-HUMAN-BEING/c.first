#include<stdio.h>
int main()
{
	int day = 9, a=1, n;
	for (; day > 0; day--)
	{
		n = (a + 2) * 2;
		a = n;
	}
	printf("一共摘了%d个桃子", n+1);
	return 0;
}