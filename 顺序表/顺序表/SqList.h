#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SqList
{
	SLDataType* a;
	int size;
	//��ǰԪ�ظ���
	int capacity;
	//��̬�ռ��С
}SL;
//��ʼ��
void SLInit(SL *sq);
//����
void SLDestroy(SL *sq);
//��ӡ
void SLPrint(SL* sq);
//����
void SLExpend(SL* sq);
//β��
void SLPushBack(SL* sq, int x);
//βɾ
void SLPopBack(SL* sq);
//ͷ��
void SLPushFront(SL* sq, int x);
//ͷɾ
void SLPopFront(SL* sq);
//����
void SLInsert(SL* sq, int pos, int x);
//����
void SLErase(SL* sq, int pos);
//����
int SLFind(SL* sq, SLDataType x);
//�޸�
void SLModify(SL* sq, int pos, SLDataType x);
//�����±��������
SLDataType SL_find(SL* sq, int pos);