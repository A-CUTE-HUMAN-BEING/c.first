#include"List.h"
void test()
{
	LTnode* Lt = initLT();
	LTPushBack(Lt, 1);
	LTPushFront(Lt, 2);
	LTPushFront(Lt, 3);
	LTPushFront(Lt, 4);
	LTPopBack(Lt);
	LTPopFront(Lt);
	//LTPrint(Lt);
	LTnode* pos=LTfind(Lt,3);
	LTinsert(pos, 666);
	LTerase(pos);
	LTPrint(Lt);
	int i = 0;
	i = LTsize(Lt);
	printf("\n%d", i);
	LTDestory(Lt);
	Lt = NULL;
}
int main()
{
	test();
	return 0;
}