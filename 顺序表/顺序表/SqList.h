#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SqList
{
	SLDataType* a;
	int size;
	//当前元素个数
	int capacity;
	//动态空间大小
}SL;
//初始化
void SLInit(SL *sq);
//销毁
void SLDestroy(SL *sq);
//打印
void SLPrint(SL* sq);
//扩容
void SLExpend(SL* sq);
//尾插
void SLPushBack(SL* sq, int x);
//尾删
void SLPopBack(SL* sq);
//头插
void SLPushFront(SL* sq, int x);
//头删
void SLPopFront(SL* sq);
//插入
void SLInsert(SL* sq, int pos, int x);
//消除
void SLErase(SL* sq, int pos);
//查找
int SLFind(SL* sq, SLDataType x);
//修改
void SLModify(SL* sq, int pos, SLDataType x);
//按照下标查找内容
SLDataType SL_find(SL* sq, int pos);