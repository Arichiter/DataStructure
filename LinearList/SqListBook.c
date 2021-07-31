#include "SqList.c"
#include <time.h>

// 问题1
bool DelMinNum(SqList *L, ElemType *e)
{
    if (L->length <= 0)
        return false;

    ElemType min = L->data[0];
    int loc = 0;

    for (int i = 1; i < L->length; i++)
    {
        if (L->data[i] < min)
        {
            min = L->data[i];
            loc = i;
        }
    }

    (*e) = min;
    L->data[loc] = L->data[--(L->length)];

    return true;
}