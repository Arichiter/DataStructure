#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 30

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

void IncreaseList(SqList *L, int len);

// 增
bool ListInsert(SqList *L, int i, ElemType e);

// 删
bool ListDelete(SqList *L, ElemType e);
bool ListDelete2(SqList *L, int i, ElemType *e);

// 查
int LocateElem(SqList L, ElemType e);

void test1();

int main(void)
{
    test1();
    return 0;
}

void test1()
{
    SqList L;
    InitList(&L);

    for (int i = 0; i < 5; i++)
    {
        L.data[i] = i;
        L.length += 1;
    }

    PrintList(L);

    ListInsert(&L, 3, 10);
    PrintList(L);
    ListInsert(&L, L.length, 89);
    PrintList(L);
    

    int e;
    ListDelete(&L, 89);
    PrintList(L);
    ListDelete2(&L, 3, &e);
    printf("del e = %d\n", e);
    PrintList(L);

    int i = LocateElem(L, 20);
    printf("loc = %d", i);
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

void IncreaseList(SqList *L, int len)
{
    ElemType *p = L->data;
    L->data = (ElemType *)malloc(sizeof(ElemType) * (L->MaxSize + len));
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;
    free(p);
}

bool ListInsert(SqList *L, int i, ElemType e)
{
    // i表示位序，从1开始
    if (i < 1 || i > L->length + 1)
        return false;

    if (L->length >= L->MaxSize)
        IncreaseList(L, 5);

    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    
    L->data[i - 1] = e;
    L->length++;

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

    for (; loc < L->length; loc++)
    {
        L->data[loc] = L->data[loc + 1];
    }
    L->length--;

    return true;
}

// 按位置删除
bool ListDelete2(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
        return false;
    
    (*e) = L->data[i - 1];
    
    for (int j = i - 1; j < L->length; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    
    
}

int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
}