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