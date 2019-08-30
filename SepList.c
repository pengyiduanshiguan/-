#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "SeqList.h"

void SepInit(PSeq ps, int capacity)
{
	ps->_array = (DataType*)malloc(sizeof(DataType) * capacity);
	if (ps->_array == NULL)
	{
		assert(0);
		return;
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}

void CheckCapacity(PSeq ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		//size==capacity顺序表中已经没有元素
		int newCapacity = ps->_capacity * 2;
		//申请新空间
		int* pTmp = (DataType*)malloc(sizeof(DataType) * newCapacity);
		if (pTmp == NULL)
		{
			assert(0);
			return;
		}
		//拷贝元素
		for (int i = 0; i < ps->_size; ++i)
		{
			pTmp[i] = ps->_array[i];
		}
		//释放旧空间
		free(ps->_array);
		//更新元素
		ps->_array = pTmp;
		ps->_capacity = newCapacity;
	}
}
void SepEmpty(PSeq ps)
{
	return ps->_size == 0;
}

void SepPushBack(PSeq ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	++ps->_size;
}
void SepPopBack(PSeq ps)
{
	assert(0);
	if (SeqEmpty(ps))
		return;
	--ps->_size;
}


void SepPushFront(PSeq ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i >= 0; --i)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	++ps->_size;
}
void SepPopFront(PSeq ps)
{
	assert(ps);
	if (SeqEmpty(ps))
		return;
	for (int i = 0; i < ps->_size; ++i)
		ps->_array[i] = ps->_array[i + 1];
	--ps->_size;
}

void SepInsert(PSeq ps, int pos, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i >= pos; --i)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	++ps->_size;
}
void SepErase(PSeq ps, int pos)
{
	assert(ps);
	for (int i = pos; i < ps->_size; ++i)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	--ps->_size;
}

int Find(PSeq ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
			return i;
	}
	return -1;
}
int SepSize(PSeq ps)
{
	assert(ps);
	return ps->_size;
}
int PSepCapacity(PSeq ps)
{
	assert(ps);
	return ps->_capacity;
}
int SepClear(PSeq ps)
{
	assert(ps);
	return ps->_size = 0;
}

void Destory(PSeq ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}
