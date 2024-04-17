#include"SqList.h"
void test()
{
	SL sq;
	SLInit(&sq);
	//SLDestroy(&sq);
	SLPushBack(&sq, 20);
	SLPushFront(&sq, 10);
	//SLPopFront(&sq);
	SLInsert(&sq, 1, 15);
	SLErase(&sq, 1);
	SLModify(&sq, 1, 3);
	SLPrint(&sq); 
	//·µ»ØÏÂ±ê
	printf("%d", SL_find(&sq, 1));
	printf("%d",SLFind(&sq, 3));
}
int main()
{
	test();
	return 0;
}