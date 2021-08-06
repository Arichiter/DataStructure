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
void ReverseList(SqList *L, int left, int right)
{
    ElemType temp;
    int mid = (left + right) / 2;
    for (int i = 0; i < mid - left; i++)
    {
        temp = L->data[left + i];
        L->data[left + i] = L->data[right - i];
        L->data[right - i] = temp;
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
        if (L.data[i] < R.data[j])
            LR->data[k++] = L.data[i++];
        else
            LR->data[k++] = R.data[j++];
    
    while (i < L.length)
        LR->data[k++] = L.data[i++];
    
    while (j < R.length)
        LR->data[k++] = R.data[j++];
    
    LR->length = k;
}

void Exchange(SqList *L, int m, int n)
{
    // // 倒置第一个List
    // ElemType temp;
    // for (int i = 0; i < m / 2; i++)
    // {
    //     temp = L->data[i];
    //     L->data[i] = L->data[m - i - 1];
    //     L->data[m - i - 1] = temp;
    // }
    // // 倒置第2个List
    // for (int i = m; i < n / 2 + m; i++)
    // {
    //     temp = L->data[i];
    //     L->data[i] = L->data[L->length - i + m - 1];
    //     L->data[L->length - i + m - 1] = temp;
    // }
    // // 全部倒置
    // for (int i = 0; i < L->length / 2; i++)
    // {
    //     temp = L->data[i];
    //     L->data[i] = L->data[L->length - i - 1];
    //     L->data[L->length - i - 1] = temp;
    // }

    // 书解
    ReverseList(L, 0, m - 1);
    ReverseList(L, m, L->length - 1);
    ReverseList(L, 0, L->length - 1);

}

// 问题9：有序表中最快时间内找到x与后继元素交换（二分查找）,找不到就按按大小插入
void SearchExchangInsert(SqList *L, int x)
{
    int left, right, mid;
    left = 0;
    right = L->length - 1;
    mid = (left + right) / 2;

    int temp;
    // while (left <= right)
    // {
    //     if (x == L->data[mid])
    //     {
    //         temp = L->data[mid];
    //         L->data[mid] = L->data[mid + 1];
    //         L->data[mid + 1] = temp;
    //         return;
    //     }
    //     else if (x > L->data[mid])
    //         left = mid + 1;
    //     else
    //         right = mid - 1;
        
    //     mid = (left + right) / 2;  
    // }

    // 书解
    while (left <= right)
    {
        if (x == L->data[mid]) break;
        else if(x < L->data[mid]) right = mid - 1;
        else left = mid + 1;
        mid = (left + right) / 2;
    }

    if (x == L->data[mid] && mid != L->length - 1)  // 若是最后一个元素无需交换
    {
        temp = L->data[mid];
        L->data[mid] = L->data[mid + 1];
        L->data[mid + 1] = temp;
    }
    if (left > right)
    {
        int i;
        for (i = L->length - 1; i > right; i--) (*L).data[i + 1] = (*L).data[i];
        (*L).data[i + 1] = x;
        L->length++;
    }
    
}

