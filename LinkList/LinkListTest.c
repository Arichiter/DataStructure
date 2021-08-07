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
    HeadCreateLinkList(&L, 10);
    PrintLinkList(L);
    ReversePrint(L->next);          // 不要把头结点传进去了，从第一个结点开始
}

void Q4Test()
{
    printf("\n***********Q4***********\n");
    LinkList L;
    HeadCreateLinkList(&L, 5);
    PrintLinkList(L);
    // LNode min = DelMinNode(&L);
    DelMinNodeAnwser(&L);
    PrintLinkList(L);
    // printf("the min node data is %d\n", min.data);
}

void Q5Test()
{
    printf("\n***********Q5***********\n");
    LinkList L;
    HeadCreateLinkList(&L, 10);
    PrintLinkList(L);
    // 解法一
    ReverseLinkList_1(&L);
    PrintLinkList(L);
    // 解法二
    ReverseLinkList_2(&L);
    PrintLinkList(L);
}

int main(void)
{   
    Q1Test();

    Q2Test();

    Q3Test();

    Q4Test();

    Q5Test();

    return 0;
}