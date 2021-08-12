#include "LinearStack.c"
#include "..\LinkList\LinkList.c"

bool Is_ERROR_Seqence(char *c)
{
    int i = 0, j = 0;
    while (c[i] != '\0')
    {
        if (c[i] == 'I')
            j++;
        else
            j--;

        if (j < 0)
            return false;

        i++;
    }
    return true;
}

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