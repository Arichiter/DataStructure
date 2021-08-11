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

```c
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
```



>问题3：
>
>设L为带头结点的单链表，编写算法实现从尾到头方向输出每个结点的值。

**基本设计思想：**

​		设f(L)的功能是寻找以L为首指针的单链表中指针域为NULL的结点，显然有f(L->next)是寻找以L->next为首指针的单链表中指针域为NULL的结点，由此可推出一下递归模型，

​		递归主体：f(L) ≡ f(L->next)；									  若L->next ！= NULL

​		终止条件：f(L) ≡ 打印当前结点的数据；					若L != NULL

```c
void ReversePrint(LinkList L)
{
    if (L->next != NULL)
        ReversePrint(L->next);
    if (L != NULL)
        printf("%4d", L->data);
}
```

**[注]** 因为头结点也有数据域且指针域指向的是第一个结点的地址，如果把头结点也传入该函数的话，头结点里的数据也会被打印，所以传参的时候传入第一个结点的地址，即ReversePrint(L->next);



# 8.07

> 问题4：
>
> 试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点时唯一的）

**基本设计思想：**

​		创建一个指针p用来指向最小结点，然后遍历整个链表L，比较找出最小结点的地址存入p。然后将该节点的数据域和指针域交换(删除)，将最小结点地址作为返回值返回。

```c
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
```

**书解：**

```c
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
```



> 问题5：
>
> 试编写算法将带头结点的单链表就地逆置

**基本设计思想：**

​		解法一：利用头插法逆置

​		解法二：明天再说

```c
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
```

# 8.10

> 问题6：
>
> 有一个带头结点的链表L，设计一个算法使其元素递增有序

**基本设计思想：**

​		设置指针p为工作指针，遍历链表

```c
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
```




> 问题7：
>
> 删除表中所有介于给定的两个值之间的元素

**基本设计思想：**

​		逐个结点进行检查，执行删除

```c
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
```



> 问题8：
>
> 给定两个单链表，编写算法找出两个链表的公共结点

**基本设计思想：**

​		原理：两个链表公共的结点的所有后继结点都是一样的。

```c
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
```

