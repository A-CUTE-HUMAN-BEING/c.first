#include<stdio.h>
int main()
{
	void c(int x);
	int i;
	printf("���һ��������");
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
	if ((s=x/10)!=0)//�� :258/10=25 25/10=2 2/10=0 Ȼ��ʼ����ifѭ�� ������2%10=2 �ٷ����ϲ� 25%10=5
		c(s);//������0��Ҫִ�����������if
	putchar(x%10+'0'); //6+�� ��=��6��
		putchar(' ');
}