#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个链表,带头结点
bool InitLinkList(LinkList *L)
{
    (*L) = (LinkList) malloc (sizeof(LNode));

    if ((*L) == NULL)
        return false;

    (*L)->next = NULL;
    return true;

}

// 判空
bool EmptyLinkLink(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

bool PrintLinkList(LinkList L)
{
    LNode *p;
    if (L == NULL)
        return false;
    
    p = L->next;
    while (p)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    
    return true;
}


// 摧毁一个链表
bool DestryLinkList(LinkList L)
{
    LNode *p;
    if (L == NULL)
        return false;

    while (L)
    {
        p = L->next;
        free(L);
        L = p;
    }
    return true;
}

// 头插法建立链表
bool HeadCreateLinkList(LinkList *L, int len)
{
    if ((*L) == NULL)
        return false;

    LNode *p;
    for (int i = 0; i < len; i++)
    {
        // 头插法,插在上一个元素的前面
        p = (LNode *) malloc (sizeof(LNode));
        p->data = rand() % 20 + 1;
        // p->data = i + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return true;
}

// 尾插法建立链表
bool TailCreateLinkList(LinkList *L, int len)
{
    if ((*L) == NULL)
        return false;

    LNode *p, *q;
    q = (*L);

    for (int i = 0; i < len; i++)
    {
        p = (LNode *) malloc (sizeof(LNode));
        // p->data = rand() % 20 + 1;
        p->data = i + 1;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return true;
}

// 按序号查找结点值

// 按值查找表结点

// 插入节点

// 删除节点

// 获取表长