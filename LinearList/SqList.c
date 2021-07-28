#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct SqList
{
    ElemType data;
    struct SqList *next;
} Lnode, *SqList;

int main(void)
{
    SqList L;
    Lnode *p = (Lnode *)malloc(sizeof(Lnode));
    p->data = 10;
    p->next = NULL;
    L = p;
    printf("%d", L->data);
}