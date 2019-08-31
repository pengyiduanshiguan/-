#include <assert.h>
#include <stdio.h>
#include "SList.h"

void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}

PNode BuySListNode(SDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(PNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (s->_pHead = NULL)
	{
		//若链表为空，则新增结点为头节点
		s->_pHead = pNewNode;
	}
	else
	{
		PNode pCur = s->_pHead;
		while (pCur->_pNext)
		{
			pCur->_pNext = pCur;
		}
		pCur->_pNext = pNewNode;
	}

}
void SListPopBack(SList* s)
{
	assert(s);
	if (SListEmpty(s))
		return;
	else if (s->_pHead->_pNext == NULL)
	{
		//只有一个结点
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else
	{
		PNode pPre = NULL;
		PNode pCur = s->_pHead;
		while (pCur->_pNext)
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		free(pCur);
		pPre->_pNext = NULL;
	}
}

void SListPushFront(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;

}
void SListPopFront(SList* s)
{
	assert(0);
	if (s->_pHead = NULL)
		return;

	// 找到待删除的节点
	PNode pDelNode;
	pDelNode = s->_pHead;
	s->_pHead = pDelNode->_pNext;
	free(pDelNode);
}

void SListInsert(SList* s, PNode pos, SDataType data)
{
	assert(s);
	if (pos == NULL)
		return;
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
void SListErase(SList* s, PNode pos, SDataType data)
{
	assert(s);
	if (pos == NULL || s->_pHead == NULL)
		return;
	else if (pos == s->_pHead)
		s->_pHead = s->_pHead->_pNext;
	else
	{
		PNode pPre = s->_pHead;
		while (pPre->_pNext != pos)
		{
			pPre = pPre->_pNext;
			pPre->_pNext = pos->_pNext;
		}
	}
	free(pos);
}

int SListSize(SList* s)
{
	assert(s);
	int count = 0;
	PNode pCur = s->_pHead;
	while (pCur)
	{
		++count;
		pCur = pCur->_pNext;
	}
	return count;
}
int SListEmpty(SList* s)
{
	assert(s);
	return s->_pHead == NULL;
}

void SListRemove(SList* s, SDataType data)
{
	assert(s);

}

void SListPrint(SList* s)
{

}