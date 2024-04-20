#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//不知道链表里面到底存什么 所以用typedef定义一个类型
typedef int DataType;
//链表结构体
typedef struct SqListNode
{
	//节点存的值
	DataType data;
	struct SqListNode* next;
}SLnode;
//创建一个节点
SLnode* CreateNode(DataType x);
//打印链表
void PrintSQ(SLnode * head);
//头插
void SQpushFront(SLnode** head, DataType x);
//头删
void SQpopFront(SLnode** head);
//尾插
void SQpushBack(SLnode** head, DataType x);
//尾删
void SQpopBack(SLnode** head);

//find
SLnode* SQfind(SLnode* head, DataType x);
//在pos位置后插入
void SQinsertPosAfter(SLnode* pos, DataType x);
//删除pos位置后的节点
void SQerasePosAfter(SLnode* pos);