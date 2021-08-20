#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;

typedef struct CQueue{
    ElemType data[MaxSize];
    int front, rear;
    int flag;
}CQueue;
