#include"Queue.h"
void test()
{
	Que qp ;
	QueueInit(&qp);
	QueuePush(&qp, 1);
	printf("%d",QueueFront(&qp));
	QueuePush(&qp, 2);
	printf("%d", QueueFront(&qp));
	printf("%d", QueueBack(&qp));
	QueuePush(&qp, 3);
	printf("%d", QueueFront(&qp));
	printf("%d", QueueBack(&qp));
	QueuePop(&qp);
	printf("%d", QueueFront(&qp));
	QueueDestroy(&qp);

}
int main()
{
	test();
	return 0;
}