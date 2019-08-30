#pragma once

#if 0
//¾²Ì¬Ë³Ðò±í
typedef int DataType;
#define MAX_SIZE 100

struct SeqList
{
	DataType _array[MAX_SIZE];
	int size;
};

#endif

//¶¯Ì¬Ë³Ðò±í
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity;
	int _size;
}Seq, * PSeq;

void SepInit(PSeq ps, int capacity);

void CheckCapacity(PSeq ps);
void SepEmpty(PSeq ps);

void SepPushBack(PSeq ps, DataType data);
void SepPopBack(PSeq ps);

void SepPushFront(PSeq ps, DataType data);
void SepPopFront(PSeq ps);

void SepInsert(PSeq ps, int pos, DataType data);
void SepErase(PSeq ps, int pos);

int Find(PSeq ps, DataType data);
int SepSize(PSeq ps);
int PSepCapacity(PSeq ps);
int SepClear(PSeq ps);

void Destory(PSeq ps);
