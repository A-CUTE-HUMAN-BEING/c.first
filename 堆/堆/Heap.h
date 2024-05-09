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

//С��
void Swap(HpDataType* a, HpDataType* b);
//���µ���
void AdjustDown(Hp* hp,  int parent);
//���ϵ���
void AdjustUp(Hp* hp, int n);
//�����
void HeapPrintf(Hp* hp);
//�ѵĳ�ʼ��
void HeapInit(Hp* hp);
//�ѵ�����
void HeapDestroy(Hp* hp);
//�ѵĲ���
void HeapPush(Hp* hp, HpDataType x);
//ɾ���Ѷ�Ԫ��
void HeapPop(Hp* hp);
//���ضѶ�Ԫ��
HpDataType HeapTop(Hp* hp);
//���ضѵĴ�С
bool HeapisEmpty(Hp* hp);
