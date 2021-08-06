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

void ReversePrint(LinkList L)
{
    if (L->next != NULL)
        ReversePrint(L->next);
    if (L != NULL)
        printf("%4d", L->data);
}