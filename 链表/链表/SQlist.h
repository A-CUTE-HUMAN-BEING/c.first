#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//��֪���������浽�״�ʲô ������typedef����һ������
typedef int DataType;
//����ṹ��
typedef struct SqListNode
{
	//�ڵ���ֵ
	DataType data;
	struct SqListNode* next;
}SLnode;
//����һ���ڵ�
SLnode* CreateNode(DataType x);
//��ӡ����
void PrintSQ(SLnode * head);
//ͷ��
void SQpushFront(SLnode** head, DataType x);
//ͷɾ
void SQpopFront(SLnode** head);
//β��
void SQpushBack(SLnode** head, DataType x);
//βɾ
void SQpopBack(SLnode** head);

//find
SLnode* SQfind(SLnode* head, DataType x);
//��posλ�ú����
void SQinsertPosAfter(SLnode* pos, DataType x);
//ɾ��posλ�ú�Ľڵ�
void SQerasePosAfter(SLnode* pos);