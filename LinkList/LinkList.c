#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个链表,带头结点
bool InitLinkList(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));

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

// 打印链表+求表长
int PrintLinkList(LinkList L)
{
    LNode *p;
    int len = 0;
    if (L == NULL)
        return len;
        
    // L save the address of head node
    p = L->next;                        // point the address of first node
    while (p)
    {
        printf("%4d", p->data);
        len++;
        p = p->next;
    }
    printf("\nlen = %d\n", len);
    return len;
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
    (*L) = (LNode *) malloc (sizeof(LNode));            // create the head node
    if ((*L) == NULL)
        return false;

    (*L)->next = NULL;

    LNode *p;
    for (int i = 0; i < len; i++)
    {
        // 头插法,插在上一个元素的前面
        p = (LNode *)malloc(sizeof(LNode));
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

    (*L) = (LNode *) malloc (sizeof(LNode));            // create the head node
    (*L)->next = NULL;

    LNode *p, *q = (*L);                                // q is the tail point

    for (int i = 0; i < len; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = rand() % 20 + 1;
        // p->data = i + 1;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return true;
}

// 按序号查找结点值
LNode *GetElem(LinkList L, int loc)
{
    if (loc < 1)
        return NULL;

    if (loc == 0)
        return L;

    // 记录loc结点
    int i = 1;
    LNode *p = L->next;
    while (p && i < loc)
    {
        p = p->next;
        i++;
    }
    return p;
}

// 按值查找表结点
LNode *LocateElem(LinkList L, ElemType x)
{
    // 指向第一个结点
    LNode *p = L->next;

    // 遍历
    while (p && p->data != x)
        p = p->next;

    if (p == NULL)
        printf("No Exist the Node!\n");

    return p;
}

// 按位序插入节点
bool InsertNode(LinkList *L, ElemType x, int loc)
{

    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = NULL;

    // 遍历找到该位置的前一个结点
    // LNode *q = (*L)->next;
    // int i = 1;
    // while (q && i < loc - 1)
    // {
    //     q = q->next;
    //     i++;
    // }
    LNode *q = GetElem((*L), loc - 1);

    if (q == NULL)
        return false;

    // 后插入
    // p->next = q->next;
    // q->next = p;

    // 前插：相当于还是后插，只是把元素值从后面换到了前面（偷天换日）
    q = GetElem((*L), loc);
    // 插入
    p->next = q->next;
    q->next = p;
    // 交换数据
    ElemType temp = q->data;
    q->data = p->data;
    p->data = temp;

    return true;
}

// 按位序删除节点
bool DeleteNode(LinkList *L, int loc)
{
    //
    LNode *p = GetElem((*L), loc - 1);
    LNode *q;
    if (p == NULL)
        return false;

    // q = p->next;
    // p->next = p->next->next;
    // free(q);

    //
    p = GetElem((*L), loc);
    p->data = p->next->data;
    q = p->next;
    p->next = p->next->next;
    free(q);
}

// 获取表长