#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqStack
{
    ElemType data[MaxSize]; // 存放栈中元素
    int top;                // 栈顶指针，指向栈顶元素（也有指向栈顶元素的下一个的方式）
} SqStack;

// 初始化
bool InitStack(SqStack *S)
{
    if (S == NULL)
        return false;

    S->top = -1; // 空栈的栈顶指针为-1
    return true;
}

// 判空
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

// 入栈
bool Push(SqStack *S, ElemType x)
{
    if (S->top == MaxSize - 1) // 判断是否栈满
        return false;          // 栈满，报错

    S->data[++S->top] = x; // 指针先+1，再入栈
    return true;
}

// 出栈
bool Pop(SqStack *S, ElemType *x);
{
    if (S->top == -1)
        return false;               // Stack is empty, false
    
    *x = S->data[S->top--];
    return true;
}

// 读取栈顶元素
bool GetTop(SqStack S, ElemType *x)
{
    if (StackEmpty(S))
        return false;
    
    *x = S.data[S.top];
    return true;
}

// 销毁栈
bool DestoryStack(SqStack *S)
{
    if (S == NULL)
        return false;
        
    free(S);
    return true;
}