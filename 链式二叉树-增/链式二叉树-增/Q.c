#include"Q.h"
//���г�ʼ��
void QueueInit(Que* q)
{
	assert(q);
	q->head = q->tail = NULL;
	//��ʼ��ͷָ���βָ��
	q->size = 0;
	//��ʼ�����д�СΪ0
}
//���ٶ���
void QueueDestroy(Que* q)
{
	assert(q);
	QNode* cur = q->head;
	//��ͷָ�뿪ʼ�ͷ�
	while (cur)
	{
		//������һ���ڵ�ĵ�ַ
		QNode* next = cur->next;
		//�ͷŵ�ǰ�ڵ�
		free(cur);
		//���µ�ǰ�ڵ�
		cur = next;
	}
	q->head = q->tail = NULL;
	q -> size = 0;
}
//���
void QueuePush(Que* q, DataType x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//�����½ڵ�ռ�
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//�������Ϊ��
	if (q->tail == NULL)
	{
	q->head=q->tail = newnode;
	}
	//������в�Ϊ��
	else
	{
	q->tail->next = newnode;
	q->tail = newnode;
	}
	q->size++;
}
//����
void QueuePop(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	//�������ֻ��һ��Ԫ��
	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	//��������ж��Ԫ��
	else
	{
		QNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
	q->size--;
}
//ȡ����Ԫ��
DataType QueueFront(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->data;
}
//ȡ��βԪ��
DataType QueueBack(Que* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->data;
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Que* q)
{
	assert(q);
	return q->size == 0;
}
//�����Ԫ�ظ���
int QueueSize(Que* q)
{
	assert(q);
	return q->size;
}