#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int DataType;
typedef struct QueueNode
{
	DataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Que;

void QueueInit(Que* q);
void QueueDestroy(Que* q);
void QueuePush(Que* q,DataType x);
void QueuePop(Que* q);
DataType QueueFront(Que* q);
DataType QueueBack(Que* q);
bool QueueEmpty(Que* q);
int QueueSize(Que* q);