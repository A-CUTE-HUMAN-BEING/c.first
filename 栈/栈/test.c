#include"Stack.h"
void test()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	while (!isEmpty(&st))
	{
		printf("%d\n",STtop(&st));
		STPop(&st);
	}
	STDestroy(&st);
}
int main()
{
	test();
	return 0;
}