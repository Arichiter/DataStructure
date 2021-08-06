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