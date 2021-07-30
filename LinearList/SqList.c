#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100
#define InitSize 30
#define IncreaseSize 10

typedef int ElemType;

typedef struct SqList
{
    ElemType *data;
    int length;
} SqList;

// 初始化线性表
void InitList(SqList *L);

// 销毁线性表
void DestroyList(SqList *L);

// 打印线性表
void PrintList(SqList L);

// 增
bool ListInsert(SqList *L, ElemType e);

// 删
bool ListDelete(SqList *L, ElemType *e);

// 查
bool LocateElem(SqList L, ElemType e);

int main(void)
{
    SqList L;
    InitList(&L);
    
    for (int i = 0; i < InitSize; i++)
    {
        L.data[i] = i;
    }

    PrintList(L);

    return 0;
}

void InitList(SqList *L)
{
    L->data = (ElemType *) malloc (sizeof(ElemType)*InitSize);
    L->length = InitSize;
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++)
    {
        printf("%4d", L.data[i]);
    }
    printf("\n");
    
}