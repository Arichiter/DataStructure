# 8.09
> 内容：
>
> - [x] 顺序栈的定义与基本操作实现
> - [x] 链栈的定于与基本操作实现
>
> 对顺序栈做了一些测试

---

# 8.12
> 问题3：
> 判断入栈、出栈序列是否合理

**基本设计思想：**

​		

```c
bool Is_ERROR_Seqence(char *c)
{
    int i = 0, j = 0;
    while (c[i] != '\0')
    {
        if (c[i] == 'I') j++;
        else j--;

        if (j < 0) return false;

        i++;
    }
    return true;
}
```



>  问题4：
>
> 判断链表是否中心对称

**基本设计思想：**

​		

```c
bool Is_Symmetric(LinkList *L)
{
    LNode *p = (*L)->next;
    int len = PrintLinkList(*L);
    SqStack S;
    InitStack(&S);

    int i = 0;
    while (i++ < len / 2)
    {
        Push(&S, p->data);
        p = p->next;
    }

    if (len % 2 != 0)
        p = p->next;

    ElemType x;
    while (p)
    {
        Pop(&S, &x);
        if (x != p->data)
            return false;
        p = p->next;
    }

    if (!StackEmpty(S))
        return false;

    return true;
}
```

