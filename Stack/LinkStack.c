#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LinkNode
{
    ElemType data;         // 数据域
    struct LinkNode *next; // 指针域
} * LinkStack, SNode;      // 栈类型定义

// 创建一个不带头结点的栈
bool CreateStack(LinkStack *S)
{
    (*S) = (LinkStack)malloc(sizeof(SNode));
    if ((*S) == NULL) // 内存分配失败，报错
        return false;
    return true;
}

// 判空
bool StackEmpty(LinkStack S)
{
    // 规定链栈没有头结点，只对表头进行操作，链尾尾栈底。
    if (S->next == NULL)
        return true;
    else
        return false;
}

// 销毁一个栈
bool DestoryStack(LinkStack *S)
{
    SNode *p = (*S), *q;
    if (StackEmpty(S))
        return true;

    while (p) // 遍历销毁每一个栈内元素
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(*S);

    return true;
}

// 入栈
bool Push(LinkStack *S, ElemType x)
{
    // 链栈没有头结点，(*S)指向第一个结点的地址，所有操作均在表头操作
    if ((*S) == NULL)
        return false;               // 栈不存在，报错

    SNode *p = (SNode *)malloc(sizeof(SNode)); // 需要插入的结点
    p->data = x;
    p->next = (*S);
    (*S) = p;
    return true;
}

// 出栈
bool Pop(LinkStack *S, ElemType *x)
{
    if (*S == NULL)
        return false;               // 栈不存在，报错

    SNode *p = (*S);
    (*S) = (*S)->next;              // 栈头指向下一个元素
    
    *x = p->data;
    free(p);                        // 删除栈顶元素
}
