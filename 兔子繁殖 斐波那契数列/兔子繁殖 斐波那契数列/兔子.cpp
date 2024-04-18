#include<stdio.h>
int main()
{
	int a = 1, b = 1;
	int sum,n;
	for (n = 3; n <= 12; n++)
	{	
		sum = a + b;
	a = b;
	b = sum;
    }
printf("共繁殖了%d只兔子", sum);
return 0;
}