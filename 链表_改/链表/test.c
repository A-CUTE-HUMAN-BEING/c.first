#include"SQlist.h"
void test()
{
	int i = 0;
	int num = 0;
	SLnode* sqlist = NULL;
	SLnode* pos = NULL;
	SLnode* pos1 = NULL;
	SLnode* pos2 = NULL;
	SQpushFront(&sqlist, 200);
	PrintSQ(sqlist);
	SQpopFront(&sqlist);
	PrintSQ(sqlist);
	SQpushBack(&sqlist, 100);
	PrintSQ(sqlist);
	SQpopBack(&sqlist);
	PrintSQ(sqlist);
	SQpushFront(&sqlist, 1);
	SQpushFront(&sqlist, 2);
	SQpushFront(&sqlist, 3);
	SQpushBack(&sqlist, 4);
	SQpushBack(&sqlist, 5);
	SQpushBack(&sqlist, 6);
	SQpushBack(&sqlist, 7);
	PrintSQ(sqlist);
	pos = SQfind(sqlist, 4);
	SQinsertPosAfter(pos, 10000);
	PrintSQ(sqlist);
	pos1 = SQfind(sqlist, 4);
	SQerasePosAfter(pos1);
	PrintSQ(sqlist);
	pos2 = SQfind(sqlist, 2);
	SQerasePos(&sqlist, pos2);
	PrintSQ(sqlist);
}
int main()
{
	test();
	return 0;
}