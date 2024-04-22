#include"List.h"

LTnode* BuyLTnode(DataType x)
{
	LTnode* node = (LTnode*)malloc(sizeof(LTnode));
	if (node == NULL)
	{
		perror("List wrong");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

LTnode* initLT()
{
	//初始化头节点
	LTnode * head= BuyLTnode(-1);
	head->next=head;
	head ->prev = head;

	return head;
}

void LTPrint(LTnode* head)
{
	assert(head);
	LTnode* cur = head->next;
	printf("phead <-> ");
	while (cur != head)
	{
		printf("%d <-> ", cur->data);
		cur = cur->next;
	}
}

void LTPushBack(LTnode* head, DataType x)
{
	assert(head);
	LTnode* newnode = BuyLTnode(x);
	LTnode* tail = head->prev;
	newnode->prev= tail;
	tail->next = newnode;

	newnode->next = head;
	head->prev = newnode;
}
void LTPopBack(LTnode* head)
{
	assert(head);
	assert(head->next != head);
	LTnode* tail = head->prev;
	LTnode* prev = tail->prev;
	free(tail);
	prev->next = head;
	head->prev = prev;
}
void LTPushFront(LTnode* head, DataType x)
{
	assert(head);
	LTnode* first = head->next;
	LTnode* newnode= BuyLTnode(x);
	newnode->next = first;
	first->prev = newnode;
	head->next = newnode;
	newnode->prev = head;
}
void LTPopFront(LTnode* head)
{
	assert(head);
	assert(head->next != head);
	LTnode* first=head->next;
	head ->next= head->next->next;
	head->next->prev = head;
	free(first);
}
LTnode*  LTfind(LTnode* head,DataType x)
{
	assert(head);
	LTnode* cur = head->next;
	while (cur!=head)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

int LTsize(LTnode* head)
{
	assert(head);
	int i = 0;
	LTnode* cur = head->next;
	while (cur != head)
	{
		i++;
		cur = cur->next;
	}
	return i;
}

void LTinsert(LTnode* pos, DataType data)
{
	assert(pos);
	LTnode* newnode= BuyLTnode(data);
	LTnode* pos_p = pos->prev;
	newnode->prev = pos_p;
	newnode->next= pos;
	pos->prev = newnode;
	pos_p->next = newnode;

}

void LTerase(LTnode* pos)
{
	assert(pos);
	LTnode* posnext = pos->next;
	LTnode* posprev = pos->prev;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);

}

void LTDestory(LTnode* head)
{
	assert(head);
	LTnode* cur = head->next;
	while (cur != head)
	{
		LTnode* next= cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	printf("\ndestory success\n");
}