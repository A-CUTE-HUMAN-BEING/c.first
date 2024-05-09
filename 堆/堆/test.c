#include"Heap.h"
void test()
{
	Hp hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPush(&hp, 3);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPrintf(&hp);
	HeapPop(&hp);
	HeapPrintf(&hp);
	HeapPop(&hp);
	HeapPrintf(&hp);
	HeapDestroy(&hp);
}


int main()
{
	test();
	return 0;
}