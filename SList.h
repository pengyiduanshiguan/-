#pragma once

typedef int SDataType;

//����Ľڵ�
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node,*PNode;

typedef struct SList
{
	PNode _pHead;
}SList,*PList;

void SListInit(SList* s);

PNode BuySListNode(SDataType data);

void SListPushBack(SList* s, SDataType data);
void SListPopBack(SList* s);

void SListPushFront(SList* s, SDataType data);
void SListPopFront(SList* s);

void SListInsert(SList* s, PNode pos, SDataType data);
void SListErase(SList* s, PNode pos, SDataType data);

int SListSize(SList* s);
int SListEmpty(SList* s);

//�Ƴ���һ��ֵΪdata��Ԫ��
void SListRemove(SList* s, SDataType data);

void SListPrint(SList* s);