#include "LinkList.c"

// 问题1：递归实现在单链表L中删除值为x的结点
void DelNum(LinkList *L, ElemType x)
{
    LNode *p;   // point the x node
    if ((*L) == NULL) return;     // Recursive export
    else if ((*L)->data == x)       
    {
        p = (*L);                      // Del (*L) and (*L) point the next node
        (*L) = p->next;
        free(p);
        DelNum(L, x);
    }
    else 
        DelNum(&((*L)->next), x);
}

// 问题2：在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一。
void DelNum_2(LinkList *L, ElemType x)
{
    LNode *p = (*L)->next;                    // p point the first node
    LNode *pre = (*L);                        // pre point p previous node
    
    // scan the linklist
    LNode *q;
    while (p)
    {
        if (p->data == x)
        {
            q = p;                          // point the present node
            p = p->next;                    // point the next node
            pre->next = p;                  // delete the node
            free(q);                        // free the node
        }
        else
        {
            // move the next node
            pre = p;                        
            p = p->next;
        }
    }

}

// 问题3：从尾到头输出链表
void ReversePrint(LinkList L)
{
    if (L->next != NULL)
        ReversePrint(L->next);
    if (L != NULL)
        printf("%4d", L->data);
}

// 问题4：删除链表中最小的结点
LNode DelMinNode(LinkList *L)
{
    LNode *p = (*L)->next;          // point the first node
    LNode *q = (*L)->next;          // traverse the list
    LNode min;
    
    while (q)                       // find the min node
    {
        if (q->data < p->data)      // record the min node
            p = q;
        q = q->next;
    }

    // sava the min node
    min.next = p->next;
    min.data = p->data;
    // delete the min node
    p->data = p->next->data;
    p->next = p->next->next;      
    // free the next node of min node, because the min node has became it
    free(min.next);
    return min;

}

// 问题4：书解
void DelMinNodeAnwser(LinkList *L)
{
    // 书解
    LNode *pre = (*L), *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while (p != NULL)
    {
        if (p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    
    minpre->next = minp->next;
    free(minp);
}

// 问题5：原地逆置单链表
void ReverseLinkList_1(LinkList *L)
{
    // 解法一：利用头插法逆置
    LNode *p = (*L)->next;                  // p是工作指针
    LNode *q;                               // q是p的后继指针
    (*L)->next = NULL;
    while (p)                               // 头插法
    {
        q = p->next;
        p->next = (*L)->next;
        (*L)->next = p;
        p = q;
    }
}

// 问题5：解法2
void ReverseLinkList_2(LinkList *L)
{
    LNode *pre, *p = (*L)->next, *q = p->next;
    p->next = NULL;
    while (q)
    {
        pre = p;
        p = q;
        q = q->next;
        p->next = pre;
    }
    (*L)->next = p;
}

bool SortList(LinkList *L)
{
    LNode *p = (*L)->next, *q = p->next;
    ElemType temp;

    if (*L == NULL)
        return false;

    while (p)
    {
        while (q)
        {
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
        if (p != NULL)
            q = p->next;
    }
    return true;
}

bool Del_S_T(LinkList *L, ElemType S, ElemType T)
{
    LNode *p = (*L)->next, *pre = (*L);
    while (p)
    {
        if (p->data >= S && p->data <= T)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
        
    }
}

LNode *Search_Common(LinkList L, LinkList M)
{
    LNode *p = L->next, *q = M->next;
    int L_len, M_len;

    for (L_len = 0; p != NULL; p = p->next, L_len++);
    for (M_len = 0; q != NULL; q = q->next, M_len++);

    p = L->next;
    q = M->next;
    if (M_len > L_len)
        for (int i = 0; i < abs(L_len - M_len); i++) q = q->next;
    else
        for (int i = 0; i < abs(L_len - M_len); i++) p = p->next;

    while (q)
    {
        if (q == p)
            return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}

bool Del_List_By_Min(LinkList *L)
{
    // 书解
    LNode *pre, *p;
    while ((*L)->next != NULL)
    {
        pre = (*L);
        p = pre->next;
        while (p->next != NULL)
        {
            if (p->next->data < pre->next->data)
                pre = p;
            p = p->next;
        }
        printf("The min is %4d\n", pre->next->data);
        LNode *u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(*L);
}

bool Disolve_List(LinkList L, LinkList *M, LinkList *N)
{
    LNode *r = (*M), *s = (*N);

    LNode *q = L->next;
    while (q)
    {
        LNode *p = (LNode *) malloc (sizeof(LNode));
        if (q->data % 2 == 0)
        {
            p->data = q->data;
            r->next = p;
            r = p;
        }
        else
        {
            p->data = q->data;
            s->next = p;
            s = p;
        }
        q = q->next;
    }
    r->next = NULL;
    s->next = NULL;
}