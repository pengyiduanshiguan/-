#pragma once

typedef int STDataType;

//��Ϊջ���Ƚ����������ʹ��˳������ʽ��ʵ�ָ���Ч

#if 0
//��̬ջ�Ľṹ
#define N 10
typedef struct Stack
{
	STDataType* _a[N];
	int _top;
}Stack;

#endif
//��̬ջ�Ľṹ
typedef struct Stack
{
	STDataType* _a;
	int _capacity;
	int _size;
}Stack;

void StackInit(Stack* s);

void CheckCapacity(Stack* s);

void StackPush(Stack* s, STDataType data);
void StackPop(Stack* s);

int StackSize(Stack* s);
STDataType StackTop(Stack* s);

int StackEmpty(Stack* s);

void StackDestory(Stack* s);