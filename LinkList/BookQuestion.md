# 8.05
> 问题1：
> 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点

**基本设计思想：**

​		设f(L,x)的功能是删除以L为首节点指针的单链表中所有值等于x的结点，显然有f(L->next, x)的功能是删除L->next为首节点指针的单链表中所有值等于x的结点，由此可以推出递归模型如下。

​		终止条件：f(L, x) ≡ 不做任何事情;							若L为空表

​		递归主体：f(L, x) ≡ 删除*L结点; f(L->next, x);		若L->data == x

​						   f(L, x) = f(L->next, x);							  其它情况

```c
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
```



# 8.06

> 问题2：
>
> 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一。

**基本设计思想：**

​		用p指针指向当前结点，遍历整个链表，pre指向*p结点的前驱。若p所指结点的值为x，则删除，并让p移向下一个结点，否则让pre、p指针同步后移一个结点。
