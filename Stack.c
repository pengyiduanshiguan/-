#include <assert.h>
#include <malloc.h>
#include "Stack.h"

void StackInit(Stack* s)
{
	assert(s);
	s->_a = (STDataType*)malloc(sizeof(STDataType)*3);
	if (s->_a == NULL)
	{
		assert(0);
		return;
	}
	s->_capacity = 3;
	s->_size = 0;
}

void CheckCapacity(Stack* s)
{
	assert(s);
	if (s->_capacity == s->_size)
	{
		int newCapacity = s->_capacity * 2;
		STDataType* pTmp = (STDataType*)malloc(sizeof(STDataType) * newCapacity);
		if (pTmp == NULL)
		{
			assert(0);
			return;
		}
		for (int i=s->_size-1;i>=0; --i)
		{
			pTmp[i] = s->_a[i];
		}
		free(s->_a);
		s->_a = pTmp;
		s->_capacity = newCapacity;
	}
}

void StackPush(Stack* s, STDataType data)
{
	assert(s);
	checkCapacity(s);
	s->_a[++s->_size] = data;
}
void StackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
		return;
	--s->_size;
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_size;
}
STDataType StackTop(Stack* s)
{
	assert(0);
	return s->_a[--s->_size];
}

int StackEmpty(Stack* s)
{
	assert(s);
	return s->_size == 0;
}

void StackDestory(Stack* s)
{
	assert(s);
	free(s->_a);
}