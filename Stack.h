#pragma once

typedef int STDataType;

//因为栈是先进后出，所以使用顺序表的形式来实现更高效

#if 0
//静态栈的结构
#define N 10
typedef struct Stack
{
	STDataType* _a[N];
	int _top;
}Stack;

#endif
//动态栈的结构
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