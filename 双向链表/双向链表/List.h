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

//数据
LTnode* BuyLTnode(DataType x);
//初始化链表
LTnode* initLT();
//打印
void LTPrint(LTnode* head);
//尾插
void LTPushBack(LTnode* head, DataType x);
//尾删
void LTPopBack(LTnode * head);
//头插
void LTPushFront(LTnode* head, DataType x);
//头删
void LTPopFront(LTnode* head);
//找到pos位置的节点
LTnode* LTfind(LTnode* head, DataType x);
//链表数量
int LTsize(LTnode* head);
//pos前插入
void LTinsert(LTnode* pos, DataType data);
//pos位置删除
void LTerase(LTnode* pos);
//删除列表
void LTDestory(LTnode* head);