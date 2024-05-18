#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct Tree* DataType;
//���еĽṹ��
typedef struct QueueNode
{
	DataType data;
	//������
	struct QueueNode* next;
	//ָ����
}QNode;
typedef struct Queue
{
	QNode* head;
	//ͷָ��
	QNode* tail;
	//βָ��
	int size;
	//���еĴ�С
}Que;

//��ʼ��
void QueueInit(Que* q);
//����
void QueueDestroy(Que* q);
//���
void QueuePush(Que* q, DataType x);
//����
void QueuePop(Que* q);
//ȡ����Ԫ��
DataType QueueFront(Que* q);
//ȡ��βԪ��
DataType QueueBack(Que* q);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Que* q);
//����еĴ�С
int QueueSize(Que* q);
