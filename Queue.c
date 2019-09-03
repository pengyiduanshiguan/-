#include <malloc.h>
#include <assert.h>
#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

QNode* BuyQueueNode(QUDataType data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QUDataType));
	if (pNewNode == NULL)
	{
		assert(0);
		return;
	}
	pNewNode->_data = data;
	pNewNode->_next = NULL;
	return pNewNode;
}

void QueuePush(Queue* q, QUDataType data)
{
	assert(q);
	QNode* pNewNode = BuyNewNode(data);
	if (Empty(q))
		q->_front = q->_rear = NULL;
	else
	{
		q->_rear->_next = pNewNode;
		q->_rear = pNewNode;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	if (Empty(q))
		return;
	QNode* pDelNode = q->_front;
	if (NULL == pDelNode->_next)
	{
		q->_front = q->_rear = NULL;
	}
	else
	{
		q->_front = pDelNode->_next;
	}
	free(pDelNode);
}

int QueueSize(Queue* q)
{
	int count = 0;
	QNode* pCur = q->_front;
	while (pCur!=NULL)
	{
		++count;
		pCur = pCur->_next;
	}
	return count;
}

int Empty(Queue* q)
{
	assert(q);
	return q->_front == q->_rear;
}

void Destory(Queue* q)
{
	assert(q);
	QNode* pDelNode = q->_front;
	while (pDelNode != NULL)
	{
		q->_front = pDelNode->_next;
		free(pDelNode);
		pDelNode = q->_front;
	}
	q->_front = q->_rear = NULL;
}