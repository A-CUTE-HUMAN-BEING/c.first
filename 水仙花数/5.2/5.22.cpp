#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("水仙花数字是\n");
	for (a = 100;a <=999; a++)
	{
		b = a / 100;
		c = (a - b * 100) / 10;
		d = a - b * 100 - c * 10;
		if (a == b * b * b + c * c * c + d * d * d)
			printf("%d\n", a);
	}
	return 0;
}