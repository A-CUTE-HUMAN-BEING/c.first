#include"Stack.h"
void STInit(ST* st)
{
	assert(st);
	st->a = NULL;
	//指向栈顶元素的下一个位置
	st->top = 0;
	st->capacity = 0;
}

void STPush(ST* st, STDataType x)
{
	if (st->top == st->capacity)
	{
		int newCapacity = st->capacity = 0 ? 4 : st->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(st->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		st->a = tmp;
		st->capacity = newCapacity;
	}
	st->a[st->top] = x;
	st->top++;
}
void STDestroy(ST* st)
{
	assert(st);
	free(st->a);
	st->a = NULL;
	st->capacity = st->top = 0;
}
void STPop(ST* st)
{
	assert(st);
	assert(st->top>0);
	--st->top;
}

int STsize(ST* st)
{
	assert(st);
	return st->top;
}

bool isEmpty(ST* st)
{
	assert(st);
	return st->top == 0;
}

STDataType STtop(ST* st)
{
	assert(st);
	assert(st->top > 0);
	return st->a[st->top-1];
}