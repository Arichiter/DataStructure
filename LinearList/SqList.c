#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 30
#define IncreaseSize 10

typedef int ElemType;

typedef struct SqList
{
    ElemType *data;
    int MaxSize, length;
} SqList;

// 初始化线性表
void InitList(SqList *L);

// 销毁线性表
void DestroyList(SqList *L);

// 打印线性表
void PrintList(SqList L);

void IncreaseList(SqList *L);

// 增
bool ListInsert(SqList *L, ElemType e);

// 删
bool ListDelete(SqList *L, ElemType e);

// 查
bool LocateElem(SqList L, ElemType e);

int main(void)
{
    SqList L;
    InitList(&L);

    for (int i = 0; i < InitSize; i++)
    {
        L.data[i] = i;
        L.length += 1;
    }

    PrintList(L);

    ListInsert(&L, 10);
    ListInsert(&L, 89);

    PrintList(L);

    ListDelete(&L, 89);
    ListDelete(&L, 15);
    PrintList(L);

    return 0;
}

void InitList(SqList *L)
{
    L->data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%4d", L.data[i]);
    }

    printf("\n%d, %d\n", L.length, L.MaxSize);
}

void IncreaseList(SqList *L)
{
    ElemType *p = L->data;
    L->data = (ElemType *)malloc(sizeof(ElemType) * (L->MaxSize + IncreaseSize));
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + IncreaseSize;
    free(p);
}

bool ListInsert(SqList *L, ElemType e)
{

    if (L->length >= L->MaxSize)
        IncreaseList(L);

    L->data[L->length++] = e;

    return true;
}

bool ListDelete(SqList *L, ElemType e)
{
    bool flag = false;
    int loc;
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            flag = true;
            loc = i;
        }
    }

    if (loc == L->length)
        return false;

    for ( ; loc < L->length; loc++)
    {
        L->data[loc] = L->data[loc + 1];
    }
    L->length--;
    
    return true;
    
}