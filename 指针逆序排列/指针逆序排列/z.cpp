#include<stdio.h>
int* p1, * p2, i, n, * v;
int main()
{
	void nixu(int *v);
	int s[100];
	int* h;
	h = &s[0];
	printf("һ��Ҫ���뼸�����֣�\n");
	scanf_s("%d", &n);
	printf("����n������������ǵ�����\n");
	for (i = 0; i <= (n - 1); i++)
		scanf_s("%d", &s[i]);
	nixu(h);
	for (i = 0;i<=(n-1); i++)
		printf("%d", s[i]);
	return 0;
}
void nixu(int *v)
{
	int t;
	int s[100];
	for (i = 0;i<=(n-1)/2; i++)
	{
		
		p1 = v+i;
		p2 = (v + (n - 1) - i);
		{t = *p1;
		*p1 = *p2;
		*p2 = t; }
	}
}