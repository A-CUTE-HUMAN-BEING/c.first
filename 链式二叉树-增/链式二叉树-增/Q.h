#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct Tree* DataType;
//队列的结构体
typedef struct QueueNode
{
	DataType data;
	//数据域
	struct QueueNode* next;
	//指针域
}QNode;
typedef struct Queue
{
	QNode* head;
	//头指针
	QNode* tail;
	//尾指针
	int size;
	//队列的大小
}Que;

//初始化
void QueueInit(Que* q);
//销毁
void QueueDestroy(Que* q);
//入队
void QueuePush(Que* q, DataType x);
//出队
void QueuePop(Que* q);
//取队首元素
DataType QueueFront(Que* q);
//取队尾元素
DataType QueueBack(Que* q);
//判断队列是否为空
bool QueueEmpty(Que* q);
//求队列的大小
int QueueSize(Que* q);
