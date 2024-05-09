#include"Heap.h"

void HeapInit(Hp* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}


void HeapDestroy(Hp* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

void AdjustUp(Hp* hp, int n)
{
	int child = n;
	int parent = (child - 1) / 2;
	while (hp->a[parent] > hp->a[child]&& parent >=0)
	{
		Swap(&hp->a[parent], &hp->a[child]);
		child = parent;
		parent = (child - 1) / 2;
	}
}

void Swap(HpDataType* a, HpDataType* b)
{
	int tmp;
	tmp= *a;
	*a = *b;
	*b = tmp;
}

void HeapPush(Hp* hp, HpDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 3 : hp->capacity * 2;
		HpDataType* tmp = (HpDataType*)realloc(hp->a, newcapacity * sizeof(HpDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size++] = x;
	AdjustUp(hp, hp->size - 1);
}

void HeapPrintf(Hp* hp)
{
	assert(hp);
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

bool HeapisEmpty(Hp* hp)
{
	assert(hp);
	return hp->size == 0;
}

HpDataType HeapTop(Hp* hp)
{
	assert(hp);
	return  hp->a[0];
}

void AdjustDown(Hp* hp,int parent)
{
	int child = parent * 2 + 1;
	while (child < hp->size)
	{
		if (hp->a[child + 1] < hp->a[child]&& child + 1<hp->size)
		{
			child++;
		}
		if(hp->a[parent]>hp->a[child])
		{
			Swap(&hp->a[parent], &hp->a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Hp* hp)
{
	assert(hp);
	assert(hp->size>0);
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp,0);
}