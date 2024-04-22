#include"SQlist.h"

SLnode* CreateNode(DataType x)
{
	SLnode* NewNode = (SLnode*)malloc(sizeof(SLnode));
	//判断是否分配成功
	if (NewNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//将数据存入节点
	NewNode->data = x;
	NewNode->next = NULL;

	return NewNode;
}

void PrintSQ(SLnode* head)
{//cur实参 head形参
	//为什么要用cur而不直接用head
	//因为head是一个指针，如果直接用head的话，会改变head的值，导致head指向的链表丢失
	//所以用cur来遍历链表
	SLnode* cur = head;
	//cur->next != NULL 说明cur不是最后一个节点 就循环
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}
//为什么**
//因为head是一个指针，指向链表的第一个节点，所以要用指向指针的指针
void SQpushFront(SLnode** head, DataType x)
{
	//创建一个新节点
	SLnode* NewNode = CreateNode(x);
	//新节点的next指向head
	//为什么
	//因为head是一个指针，指向链表的第一个节点，才能做到头插
	NewNode->next = *head;
	//head指向新节点
	*head = NewNode;
}

void SQpopFront(SLnode** head)
{
	assert(*head);
	//保存头节点
	SLnode* del = *head;
	//head指向第二个节点
	*head = del->next;
	//释放头节点
	free(del);
}

void SQpushBack(SLnode** head, DataType x)
{
	SLnode* cur = CreateNode(x);
	//如果链表为空
	if (*head == NULL)
	{
		*head = cur;
	}
	else
	{
		//找到最后一个节点
		SLnode* tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//最后一个节点的next指向新节点
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