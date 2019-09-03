#pragma once

//���в����Ƚ��ȳ��ķ�ʽ�����Բ�������ķ�ʽ���й���

typedef int QUDataType;

typedef struct QueueNode
{
	struct QNode* _next;
	QUDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;    //��ͷ
	QNode* _rear;     //��β
}Queue;

void QueueInit(Queue* q);

QNode* BuyQueueNode(QUDataType data);

void QueuePush(Queue* q, QUDataType data);
void QueuePop(Queue* q);

int Empty(Queue* q);
int QueueSize(Queue* q);

void Destory(Queue* q);

