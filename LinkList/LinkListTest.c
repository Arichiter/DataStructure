#include "LinkListBook.c"

void Q1Test()
{
    printf("\n***********Q1***********\n");
    LinkList L;
    L = (LinkList) malloc (sizeof(LNode));
    L->data = 1;
    L->next = NULL;

    LNode *q = L;
    ElemType a[] = {1, 6, 2, 5, 1, 5, 9, 8, 5, 5};
    for (int i = 0; i < 10; i++)
    {
        LNode *p = (LNode *) malloc (sizeof(LNode));
        p->data = a[i];
        q->next = p;
        q = p;
    }
    q->next = NULL;
    // 1 6 2 5 1 5 9 8 5 5
    PrintLinkList(L);
    DelNum(&L, 5);
    PrintLinkList(L);

}

void Q2Test()
{
    printf("\n***********Q2***********\n");
    LinkList L;
    TailCreateLinkList(&L, 20);

    PrintLinkList(L);
    DelNum_2(&L, 3);
    PrintLinkList(L);

}

void Q3Test()
{
    printf("\n***********Q3***********\n");
    LinkList L;
    L->next = NULL;
    // HeadCreateLinkList(&L, 10);
    PrintLinkList(L);
    ReversePrint(L);
}

int main(void)
{   
    Q1Test();

    Q2Test();

    Q3Test();

    return 0;
}