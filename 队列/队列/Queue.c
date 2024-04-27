#include"Queue.h"
void QueueInit(Que* q)
{
	assert(q);
	q->head = q->tail = NULL;
	q->size = 0;
}

void QueueDestroy(Que* q)
{
	assert(q);
	QNode* cur = q->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
	q -> size = 0;
}
void QueuePush(Que* q, DataType x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (q->tail == NULL)
	{
	q->head=q->tail = newnode;
	}
	else
	{
	q->tail->next = newnode;
	q->tail = newnode;
	}
	q->size++;
}

void QueuePop(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
	q->size--;
}
DataType QueueFront(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->data;
}

DataType QueueBack(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->data;
}

bool QueueEmpty(Que* q)
{
	assert(q);
	return q->size == 0;
	//return q->head == NULL;
}
int QueueSize(Que* q)
{
	assert(q);
	return q->size;
}