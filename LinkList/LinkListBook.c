#include "LinkList.c"

// 问题1：递归实现在单链表L中删除值为x的结点
void DelNum(LinkList *L, ElemType x)
{
    LNode *p; // point the x node
    if ((*L) == NULL)
        return; // Recursive export
    else if ((*L)->data == x)
    {
        p = (*L); // Del (*L) and (*L) point the next node
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
    LNode *p = (*L)->next; // p point the first node
    LNode *pre = (*L);     // pre point p previous node

    // scan the linklist
    LNode *q;
    while (p)
    {
        if (p->data == x)
        {
            q = p;         // point the present node
            p = p->next;   // point the next node
            pre->next = p; // delete the node
            free(q);       // free the node
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
    LNode *p = (*L)->next; // point the first node
    LNode *q = (*L)->next; // traverse the list
    LNode min;

    while (q) // find the min node
    {
        if (q->data < p->data) // record the min node
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
    LNode *p = (*L)->next; // p是工作指针
    LNode *q;              // q是p的后继指针
    (*L)->next = NULL;
    while (p) // 头插法
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

// 问题6：有一个带头结点的链表L，设计一个算法使其元素递增有序
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

// 问题7：删除表中所有介于给定的两个值之间的元素
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

// 问题8：给定两个单链表，编写算法找出两个链表的公共结点
LNode *Search_Common(LinkList L, LinkList M)
{
    LNode *p = L->next, *q = M->next;
    int L_len, M_len;

    for (L_len = 0; p != NULL; p = p->next, L_len++)
        ;
    for (M_len = 0; q != NULL; q = q->next, M_len++)
        ;

    p = L->next;
    q = M->next;
    if (M_len > L_len)
        for (int i = 0; i < abs(L_len - M_len); i++)
            q = q->next;
    else
        for (int i = 0; i < abs(L_len - M_len); i++)
            p = p->next;

    while (q)
    {
        if (q == p)
            return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}

// 问题9：存在一个无序链表，按递增序列删除列表
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

// 按元素的奇偶数分开
bool Disolve_List_By_JiOu(LinkList L, LinkList *M, LinkList *N)
{
    // 将链表内的奇数和偶数分开成两个链表
    LNode *r = (*M), *s = (*N);

    LNode *q = L->next;
    while (q)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
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

// 问题10：按序号奇偶分解链表
bool Disolve_List_1(LinkList L, LinkList *M, LinkList *N)
{
    // 书解
    int i = 0;
    LNode *ra = L, *rb = (*M);

    LNode *p;

    p = L->next;
    while (p != NULL)
    {
        i++;
        if (i % 2 == 0)
        {
            rb->next = p;
            rb = p;
        }
        else
        {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    (*N) = L;
}

// 问题11：
bool Disolve_List_2(LinkList *A, LinkList *B)
{
    // 与上题一样，同样是按序号奇偶分开，B链表采用头插法，A链表采用尾插法
    // 原地操作
    (*B) = (LinkList)malloc(sizeof(LNode));
    (*B)->next = NULL;
    LNode *p = (*A)->next, *q; // p为工作指针
    LNode *ra = *A;            // ra始终指向A的尾结点

    while (p != NULL)
    {
        ra->next = p;
        ra = p; // 将*p链到A的表尾
        p = p->next;
        if (p != NULL)
            q = p->next; // 头插后，*p将断链，因此用q记忆*p的后继
        // 头插法
        p->next = (*B)->next; // 将*p插入到B的前端
        (*B)->next = p;
        p = q;
    }
    ra->next = NULL; // A尾结点的next域置空
}

// 问题12：
bool Delete_Common_Num(LinkList *L)
{
    LNode *p = (*L)->next, *q = p->next;
    LNode *s;
    while (q)
    {
        if (p->data == q->data)
        {
            s = q;
            q = q->next;
            free(s);
        }
        else
        {
            p->next = q;
            p = p->next;
            q = q->next;
        }
    }
}