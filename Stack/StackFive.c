#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20

#define ElemType int

typedef struct
{
    ElemType stack[MaxSize]; // 栈空间
    int top[2];              // top为两个栈顶指针
} stk;


int push(stk *s, int i, ElemType x)
{
    // 入栈操作。i为栈号，i=0表示左边的s1栈，i=1表示右边的s2栈，x是入栈元素
    // 入栈成功返回1，否则返回0
    if (i < 0 || i > 1)
    {
        printf("栈号输入不对！\n");
        exit(0);
    }

    if (s->top[1] - s->top[0] == 1)
    {
        printf("栈已满\n");
        return 0;
    }

    switch (i)
    {
    case 0:
        s->stack[++s->top[0]] = x;
        return 1;
        break;

    case 1:
        s->stack[--s->top[1]] = x;
        return 1;
        break;
    }
}

ElemType pop(stk *s, int i)
{
    // 退栈算法。i代表栈号，i=0时为s1栈，i=1时为s2栈
    // 退栈成功返回退栈元素，否则返回-1
    if (i < 0 || i > 1)
    {
        printf("栈号输入错误\n");
        exit(0);
    }

    switch (i)
    {
    case 0:
        if (s->top[0] == -1)
        {
            printf("栈空\n");
            return -1;
        }
        else
            return s->stack[s->top[0]--];
        break;

    case 1:
        if (s->top[1] == MaxSize)
        {
            printf("栈空\n");
            return -1;
        }
        else
            return s->stack[s->top[1]++];

    default:
        break;
    }
}

int main(void)
{
    stk s;
    s.top[0] = -1;
    s.top[1] = 20;
    for (int i = 0; i < 22; i++)
    {
        push(&s, i % 2, i);
    }

    for (int i = 0; i < 20; i++)
        printf("%4d", s.stack[i]);

    return 0;
}