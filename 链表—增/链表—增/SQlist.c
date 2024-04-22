#include"SQlist.h"

SLnode* CreateNode(DataType x)
{
	SLnode* NewNode = (SLnode*)malloc(sizeof(SLnode));
	//�ж��Ƿ����ɹ�
	if (NewNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//�����ݴ���ڵ�
	NewNode->data = x;
	NewNode->next = NULL;

	return NewNode;
}

void PrintSQ(SLnode* head)
{//curʵ�� head�β�
	//ΪʲôҪ��cur����ֱ����head
	//��Ϊhead��һ��ָ�룬���ֱ����head�Ļ�����ı�head��ֵ������headָ�������ʧ
	//������cur����������
	SLnode* cur = head;
	//cur->next != NULL ˵��cur�������һ���ڵ� ��ѭ��
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}
//Ϊʲô**
//��Ϊhead��һ��ָ�룬ָ������ĵ�һ���ڵ㣬����Ҫ��ָ��ָ���ָ��
void SQpushFront(SLnode** head, DataType x)
{
	//����һ���½ڵ�
	SLnode* NewNode = CreateNode(x);
	//�½ڵ��nextָ��head
	//Ϊʲô
	//��Ϊhead��һ��ָ�룬ָ������ĵ�һ���ڵ㣬��������ͷ��
	NewNode->next = *head;
	//headָ���½ڵ�
	*head = NewNode;
}

void SQpopFront(SLnode** head)
{
	assert(*head);
	//����ͷ�ڵ�
	SLnode* del = *head;
	//headָ��ڶ����ڵ�
	*head = del->next;
	//�ͷ�ͷ�ڵ�
	free(del);
}

void SQpushBack(SLnode** head, DataType x)
{
	SLnode* cur = CreateNode(x);
	//�������Ϊ��
	if (*head == NULL)
	{
		*head = cur;
	}
	else
	{
		//�ҵ����һ���ڵ�
		SLnode* tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//���һ���ڵ��nextָ���½ڵ�
		tail->next = cur;
	}
}

void SQpopBack(SLnode** head)
{
	assert(*head);
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		SLnode* tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
	}
}

SLnode* SQfind(SLnode* head, DataType x)
{
	SLnode* pos = head;
	while (pos)
	{
		if (pos->data == x)
		{
			return pos;
		}
		pos = pos->next;
	}
	return NULL;
}


void SQinsertPosAfter(SLnode* pos, DataType x)
{
	assert(pos);
	SLnode* cur = CreateNode(x);
	cur->next = pos->next;
	pos->next = cur;
}

void SQerasePosAfter(SLnode* pos)
{
	assert(pos);
	assert(pos->next);
	SLnode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
void SQerasePos(SLnode** head, SLnode* pos)
{
	assert(pos);
	if (pos == *head)
	{
		SQpopFront(head);
		return;
	}
	else
	{
		SLnode* cur = *head;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}