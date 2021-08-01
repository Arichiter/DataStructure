#include "SqList.c"

// 问题1：找最小值并删除，用最后一个元素顶替
bool DelMinNum(SqList *L, ElemType *e)
{
    if (L->length <= 0)
        return false;

    // ElemType min = L->data[0];
    // 书解
    (*e) = L->data[0];
    int loc = 0;

    for (int i = 1; i < L->length; i++)
    {
        if (L->data[i] < (*e))
        {
            (*e) = L->data[i];
            loc = i;
        }
    }

    L->data[loc] = L->data[--(L->length)];

    return true;
}

// 问题2：原地逆置元素
void ReverseList(SqList *L)
{
    ElemType temp;
    for (int i = 0; i < L->length / 2; i++)
    {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = temp;
    }
}

// 问题3：原地删除特定值
void DelSpecNum(SqList *L, ElemType x)
{
    int i = 0;
    int j = 0;
    for (; i < L->length; i++)
    {
        if (L->data[i] != x)
        {
            L->data[j] = L->data[i];
            j++;
        }
    }

    L->length = j;
}

// 问题4：有序顺序表中删除s~t之间的元素s<t
bool DelStoT(SqList *L, ElemType s, ElemType t)
{
    if (s > t || L->length <= 0)
        return false;

    // int j = 0;
    // for (int i = 0; i < L->length; i++)
    // {
    //     if (!(L->data[i] >= s && L->data[i] =< t))
    //         L->data[j++] = L->data[i];
    // }
    // L->length = j;

    // 书解
    int i, j;

    for (i = 0; i < L->length && L->data[i] < s; i++)
        ;
    if (i >= L->length)
        return false;

    for (j = i; j < L->length && L->data[j] <= t; j++)
        ;

    for (; j < L->length; i++, j++)
        L->data[i] = L->data[j];

    L->length = i;

    return true;
}

// 问题5：无序顺序表中删除s~t之间的元素s<t
bool DelStoT2(SqList *L, ElemType s, ElemType t)
{
    if (s > t || L->length <= 0)
        return false;

    int j = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (!(L->data[i] >= s && L->data[i] <= t))
            L->data[j++] = L->data[i];
    }
    L->length = j;
    return true;
}

// 问题6：从有序顺序表中删除重复值
bool DelComNum(SqList *L)
{
    if (L->length <= 0)
        return false;

    // int j = 0;
    // for (int i = 1; i < L->length; i++)
    // {
    //     if (L->data[i] == L->data[j])
    //         L->data[j] = L->data[i];
    //     else
    //         L->data[++j] = L->data[i];
    // }
    // L->length = j + 1;

    // 书解
    int i, j;
    for (i = 0, j = 1; j < L->length; j++)
    {
        if (L->data[i] != L->data[j])
            L->data[++i] = L->data[j];
    }
    L->length = i + 1;
    return true;
}

void MergeList(SqList L, SqList R, SqList *LR)
{
    while (L.length + R.length > LR->MaxSize)
        IncreaseList(LR, 10);

    // 书解
    int i = 0, j = 0, k = 0;
    while (i < L.length && j < R.length)
        if (L.data[i] <= R.data[j])
            LR->data[k++] = L.data[i++];
        else
            LR->data[k++] = L.data[j++];

    while (i < L.length)
        LR->data[k++] = L.data[i++];
    while (j < R.length)
        LR->data[k++] = L.data[j++];

    LR->length = k;

}