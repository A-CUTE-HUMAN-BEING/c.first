#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;
typedef struct ListNode
{
	DataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTnode;

//����
LTnode* BuyLTnode(DataType x);
//��ʼ������
LTnode* initLT();
//��ӡ
void LTPrint(LTnode* head);
//β��
void LTPushBack(LTnode* head, DataType x);
//βɾ
void LTPopBack(LTnode * head);
//ͷ��
void LTPushFront(LTnode* head, DataType x);
//ͷɾ
void LTPopFront(LTnode* head);
//�ҵ�posλ�õĽڵ�
LTnode* LTfind(LTnode* head, DataType x);
//��������
int LTsize(LTnode* head);
//posǰ����
void LTinsert(LTnode* pos, DataType data);
//posλ��ɾ��
void LTerase(LTnode* pos);
//ɾ���б�
void LTDestory(LTnode* head);