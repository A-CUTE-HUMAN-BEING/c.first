#include<stdio.h>
int main()
{
	void swap(int* p1, int* p2);
	int a,b,c, *p,*o,*q;
	printf("输出三个整数：");
	scanf_s("%d%d%d", &a, &b, &c);
	o = &a;
	p = &b;
	q = &c;
		swap(o, p);
		swap(o, q);
		swap(p, q);
	printf("顺序为：%d\t%d\t%d\n", a,b,c);
	return 0;
}
void swap(int* p1, int* p2)
{
	if (*p1 > *p2)
	{int r;
	r = *p1;
	*p1 = *p2;
	*p2 = r; }
}