#include"SqList.h"

void SLInit(SL* sq)
{
	sq->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (sq->a == NULL)
	{
		perror(malloc);
		exit(-1);
	}
	sq->size = 0;
	sq->capacity = 4;
	//先分配一些空间
}

void SLDestroy(SL* sq)
{
	free(sq->a);
	sq -> size = 0;
	sq->capacity = 0;
}

void SLPrint(SL* sq)
{
	int i = 0;
	for (i = 0; i < sq->size; i++)
	{
		printf("%d ", sq->a[i]);
	}
}

void SLExpend(SL* sq)
{
	if (sq->size == sq->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(sq->a, sq->capacity * 2 * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror(realloc);
			exit(-1);
		}
		sq->a = tmp;
		sq->capacity *= 2;
	}
}

void SLPushBack(SL* sq, SLDataType x)
{
	SLExpend(&sq);
	sq->a[sq->size] = x;
	sq->size++;
}
void SLPopBack(SL* sq)
{
	//if (sq->size = 0)
	//{
	//	return;
	//	//温柔的断言
	//}
	assert(sq->size > 0);
	sq->size--;
}
void SLPushFront(SL* sq, SLDataType x)
{
	SLExpend(&sq);
	int i = 0;
	for(i= sq->size;i>0;i--)
	{
		sq->a[i] = sq->a[i-1];
	}
	sq->a[0] = x;
	sq->size++;
}

void SLPopFront(SL* sq)
{
	int i = 0;
	for(i =0; i <sq->size; i++)
	{
		sq->a[i] = sq->a[i+1];
	}
	sq->size--;
}

void SLInsert(SL* sq, int pos, SLDataType x)
{
	assert(pos >= 0 && pos <= sq->size);
	SLExpend(&sq);
	int i = 0;
	for (i = sq->size; i > pos; i--)
	{
		sq->a[i] = sq->a[i-1];
	}
	sq->a[pos] = x ;
	sq->size++;
}

void SLErase(SL* sq, int pos)
{
	assert(pos >= 0 && pos <= sq->size);
	int i = 0;
	for (i =pos; i <sq->size; i++)
	{
		sq->a[i] = sq->a[i+1];
	}
	sq->size--;
}
void SLModify(SL* sq, int pos, SLDataType x)
{
	assert(pos >= 0 && pos <= sq->size);
	sq->a[pos] = x;
}
int SLFind(SL* sq, SLDataType x)
{
	int i = sq->size-1;
	while (i)
	{
		if(sq->a[i] == x)
		{
			return i;
		}
		i--;
	}
	return NULL;

}
SLDataType SL_find(SL* sq, int pos)
{
	assert(pos >= 0 && pos <= sq->size);
	return sq->a[pos];
}