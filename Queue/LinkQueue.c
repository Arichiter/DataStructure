#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

// 初始化
void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

// 判队空
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear) return false;
    else return true;
}

// 入队
void EnQueue(LinkQueue *Q, ElemType x)
{
    LinkNode *s = (LinkNode *) malloc (sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

// 出队
void DeQueue(LinkQueue *Q, ElemType *x)
{
    if (Q->front == Q->rear) return false;
    LinkNode *p = Q->front->next;
    (*x) = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->front = Q->front;
    free(p);
    return true;
}

