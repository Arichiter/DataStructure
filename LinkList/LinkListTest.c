#include "LinkListBook.c"

void Q1Test()
{
    printf("\n***********Q1***********\n");
    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));
    L->data = 1;
    L->next = NULL;

    LNode *q = L;
    ElemType a[] = {1, 6, 2, 5, 1, 5, 9, 8, 5, 5};
    for (int i = 0; i < 10; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
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
    ReversePrint(L->next); // 不要把头结点传进去了，从第一个结点开始
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

void Q6Test()
{
    printf("\n***********Q6***********\n");
    LinkList L;
    HeadCreateLinkList(&L, 10);
    PrintLinkList(L);
    SortList(&L);
    PrintLinkList(L);
}

void Q7Test()
{
    printf("\n***********Q7***********\n");
    LinkList L;
    HeadCreateLinkList(&L, 10);
    PrintLinkList(L);
    Del_S_T(&L, 5, 18);
    PrintLinkList(L);
}

void Q8Test()
{
    printf("\n***********Q8***********\n");
    LinkList L, M;
    HeadCreateLinkList(&L, 10);
    HeadCreateLinkList(&M, 5);

    LNode *p = M->next, *q = L->next;
    for (p = p->next; p->next != NULL; p = p->next)
        ;
    for (int i = 0; i < 5; i++)
        q = q->next;

    PrintLinkList(L);
    PrintLinkList(M);
    p->next = q;
    p = Search_Common(L, M);
    for (; p != NULL; p = p->next)
        printf("%4d", p->data);
    printf("\n");
}

void Q9Test()
{
    printf("\n***********Q9***********\n");
    LinkList L;
    HeadCreateLinkList(&L, 10);
    PrintLinkList(L);
    Del_List_By_Min(&L);
}

void Q10Test()
{
    printf("\n***********Q10***********\n");
    LinkList L;
    HeadCreateLinkList(&L, 10);
    PrintLinkList(L);

    LinkList M, N;
    M = (LinkList)malloc(sizeof(LNode));
    N = (LinkList)malloc(sizeof(LNode));
    M->next = NULL;
    N->next = NULL;
    Disolve_List_1(L, &M, &N);
    PrintLinkList(M);
    PrintLinkList(N);
}

void Q11Test()
{
    printf("\n***********Q11***********\n");
    LinkList A, B;
    HeadCreateLinkList(&A, 10);
    PrintLinkList(A);

    Disolve_List_2(&A, &B);
    PrintLinkList(A);
    PrintLinkList(B);
}

void Q12Test()
{
    printf("\n***********Q12***********\n");
    LinkList L = (LinkList) malloc (sizeof(LNode));
    L->next = NULL;
    ElemType a[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    int len = sizeof(a) / sizeof(ElemType);

    LNode *q = L;
    for (int i = 0; i < len; i++)
    {
        LNode *p = (LNode *) malloc (sizeof(LNode));
        p->data = a[i];
        // 尾插法
        p->next = q->next;
        q->next = p;
        q = p;
        // 头插法
        // p->next = L->next;
        // L->next = p;
    }
    q->next = NULL;
    PrintLinkList(L);

    Delete_Common_Num(&L);
    PrintLinkList(L);

}

void Q13Test()
{
    printf("\n***********Q13***********\n");
    LinkList L, S;
    HeadCreateLinkList(&L, 10);
    HeadCreateLinkList(&S, 10);
    SortList(&L);
    SortList(&S);
    PrintLinkList(L);
    PrintLinkList(S);

    MergeSqquentialList(&L, &S);
    PrintLinkList(L);

}

void Q15Test()
{
    printf("\n***********Q13***********\n");
    LinkList L, S;
    HeadCreateLinkList(&L, 10);
    HeadCreateLinkList(&S, 10);
    SortList(&L);
    SortList(&S);
    PrintLinkList(L);
    PrintLinkList(S);

    LinkList LC = Union(&L, &S);
    PrintLinkList(LC);
}

int main(void)
{
    Q1Test();

    Q2Test();

    Q3Test();

    Q4Test();

    Q5Test();

    Q6Test();

    Q7Test();

    Q8Test();

    Q9Test();

    Q10Test();

    Q11Test();

    Q12Test();

    Q13Test();

    Q15Test();

    return 0;
}