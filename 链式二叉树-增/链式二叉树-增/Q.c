#include"Q.h"
//队列初始化
void QueueInit(Que* q)
{
	assert(q);
	q->head = q->tail = NULL;
	//初始化头指针和尾指针
	q->size = 0;
	//初始化队列大小为0
}
//销毁队列
void QueueDestroy(Que* q)
{
	assert(q);
	QNode* cur = q->head;
	//从头指针开始释放
	while (cur)
	{
		//保存下一个节点的地址
		QNode* next = cur->next;
		//释放当前节点
		free(cur);
		//更新当前节点
		cur = next;
	}
	q->head = q->tail = NULL;
	q -> size = 0;
}
//入队
void QueuePush(Que* q, DataType x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//申请新节点空间
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//如果队列为空
	if (q->tail == NULL)
	{
	q->head=q->tail = newnode;
	}
	//如果队列不为空
	else
	{
	q->tail->next = newnode;
	q->tail = newnode;
	}
	q->size++;
}
//出队
void QueuePop(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	//如果队列只有一个元素
	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	//如果队列有多个元素
	else
	{
		QNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
	q->size--;
}
//取队首元素
DataType QueueFront(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->data;
}
//取队尾元素
DataType QueueBack(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->data;
}
//判断队列是否为空
bool QueueEmpty(Que* q)
{
	assert(q);
	return q->size == 0;
}
//求队列元素个数
int QueueSize(Que* q)
{
	assert(q);
	return q->size;
}