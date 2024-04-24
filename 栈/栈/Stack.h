#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;
	int capacity;
}ST; 

void STInit(ST* st);
void STPush(ST* st, STDataType x);
void STPop(ST* st);
void STDestroy(ST* st);
int STsize(ST* st);
bool isEmpty(ST* st);
STDataType STtop(ST* st);