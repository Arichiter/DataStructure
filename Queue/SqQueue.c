#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct SqQueue
{
    ElemType data[MaxSize]; // 存放队列元素
    int front, rear;        // 队头指针和队尾指针
} SqQueue;

// 初始化队列，构造一个空队列Q
bool InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

// 判空队列
bool QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

// 入队
bool EnQueue(SqQueue *Q, ElemType x)
{
    if ((Q->rear + 1) % MaxSize == Q->front) // 队满则报错
        return false;

    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize; // 队尾指针加1取模
    return true;
}

// 出队
bool DeQueue(SqQueue *Q, ElemType *x)
{
    if (Q->rear == Q->front) // 队空则报错
        return false;
    (*x) = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize; // 队头指针加1取模
    return true;
}

// 读队头元素
bool GetHead(SqQueue Q, ElemType *x)
{
    if (Q.rear == Q.front)
        return false;

    (*x) = Q.data[Q.front];
    return true;
}

bool PrintQueue(SqQueue Q)
{
    int index = Q.front;
    while (Q.rear != index)
    {
        printf("%4d", Q.data[index]);
        index = (index + 1) % MaxSize;
    }
    printf("\n");
}