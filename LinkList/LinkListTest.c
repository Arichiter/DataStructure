#include "LinkList.c"

int main(void)
{
    LinkList L;
    InitLinkList(&L);

    // HeadCreateLinkList(&L, 10);
    TailCreateLinkList(&L, 10);
    PrintLinkList(L);

    LNode *p = GetElem(L, 7);
    printf("%d\n", p->data);

    p = LocateElem(L, 1);
    printf("%d\n", p->data);

    InsertNode(&L, 80, 8);
    PrintLinkList(L);

    DeleteNode(&L, 8);
    PrintLinkList(L);

    return 0;
}