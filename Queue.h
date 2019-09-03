#pragma once

//队列采用先进先出的方式，所以采用链表的方式进行构造

typedef int QUDataType;

typedef struct QueueNode
{
	struct QNode* _next;
	QUDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;    //对头
	QNode* _rear;     //队尾
}Queue;

void QueueInit(Queue* q);

QNode* BuyQueueNode(QUDataType data);

void QueuePush(Queue* q, QUDataType data);
void QueuePop(Queue* q);

int Empty(Queue* q);
int QueueSize(Queue* q);

void Destory(Queue* q);

