#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20

typedef int ElemType;

typedef struct CQueue{
    ElemType data[MaxSize];
    int front, rear;
    int tag;
}CQueue;

bool InitQueue(CQueue *Q)
{
    if (Q == NULL)
        return false;
    Q->rear = Q->front = 0;
    Q->tag = 0; // EnQueue result Queue full(tag = 1), DeQueue result Queue Empty(tag = 0)
}

bool EnQueue(CQueue *Q, ElemType x)
{
    if (Q->front == Q->rear && Q->tag == 1) // Queue full!
        return false;
    
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    Q->tag = 1;
    return true;
}

bool DeQueue(CQueue *Q, ElemType *x)
{
    if (Q->front == Q->rear && Q->tag == 0) // Queue empty!
        return false;

    (*x) = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    Q->tag = 0;
}

bool PrintQueue(CQueue Q)
{
    int len;
    if (Q.front == Q.rear)
        if (Q.tag == 0)
            return false;
        else
            len = MaxSize;
    else
        len = (Q.rear - Q.front + MaxSize) % MaxSize;
    
    for (int i = 0; i < len; i++)
    {
        printf("%4d", Q.data[Q.front]);
        Q.front = (Q.front + 1) % MaxSize;
    }
        
    printf("\n");
    return true;
}