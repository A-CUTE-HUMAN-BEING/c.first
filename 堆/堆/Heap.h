#pragma once
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HpDataType;
typedef struct Heap
{
	HpDataType* a;
	int size;
	int capacity;
}Hp;

//小堆
void Swap(HpDataType* a, HpDataType* b);
//向下调整
void AdjustDown(Hp* hp,  int parent);
//向上调整
void AdjustUp(Hp* hp, int n);
//堆输出
void HeapPrintf(Hp* hp);
//堆的初始化
void HeapInit(Hp* hp);
//堆的销毁
void HeapDestroy(Hp* hp);
//堆的插入
void HeapPush(Hp* hp, HpDataType x);
//删除堆顶元素
void HeapPop(Hp* hp);
//返回堆顶元素
HpDataType HeapTop(Hp* hp);
//返回堆的大小
bool HeapisEmpty(Hp* hp);
