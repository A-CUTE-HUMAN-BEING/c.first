#include<stdio.h>
int main()
{
	void c(int x);
	int i;
	printf("输出一个整数：");
	scanf_s("%d", &i);
	if (i < 0)
	{
		putchar('-');
		putchar(' ');
		i = -i;
	}
	c(i);
	printf("\n");
	return 0;
}
void c(int x)
{
	int s;
	if ((s=x/10)!=0)//例 :258/10=25 25/10=2 2/10=0 然后开始跳过if循环 输入完2%10=2 再返回上层 25%10=5
		c(s);//不等于0就要执行这个函数再if
	putchar(x%10+'0'); //6+‘ ’=‘6’
		putchar(' ');
}