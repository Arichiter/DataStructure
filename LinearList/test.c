#include "SqListBook.c"

void CreateTestList(SqList *L)
{
    InitList(L);

    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        L->data[i] = rand() % 20 + 1;
        L->length++;
    }
}

void Q1Test(SqList L)
{
    printf("\n*********Q1*********\n");
    ElemType e;
    DelMinNum(&L, &e);
    PrintList(L);
    printf("The min num is %d\n", e);
}

void Q2Test(SqList L)
{
    printf("\n*********Q2*********\n");
    printf("before reverse\n");
    PrintList(L);
    ReverseList(&L);
    printf("after reverse\n");
    PrintList(L);
}

void Q3Test()
{
    printf("\n*********Q3*********\n");
    ElemType a[] = {1, 3, 2, 3, 5};
    SqList L;
    L.data = a;
    L.length = 5;
    L.MaxSize = 10;

    int x = 3;
    PrintList(L);
    DelSpecNum(&L, 3);
    PrintList(L);
}

void Q4Test()
{
    printf("\n*********Q4*********\n");
    SqList L;
    InitList(&L);

    for (int i = 0; i < 10; i++)
    {
        L.data[i] = i;
        L.length++;
    }

    PrintList(L);
    DelStoT(&L, 3, 7);
    PrintList(L);
}

void Q5Test()
{
    printf("\n*********Q5*********\n");
    SqList L;
    CreateTestList(&L);
    PrintList(L);
    DelStoT2(&L, 7, 16);
    PrintList(L);
}

void Q6Test()
{
    printf("\n*********Q6*********\n");
    SqList L;
    ElemType a[] = {1, 2, 3, 4, 5, 5, 6, 7, 7, 8, 10, 10, 11, 12};
    L.data = a;
    L.length = sizeof(a) / sizeof(ElemType);
    PrintList(L);
    DelComNum(&L);
    PrintList(L);
}

void Q7Test() 
{
    printf("\n*********Q7*********\n");
    SqList L, R, LR;
    InitList(&LR);
    ElemType a[] = {1, 2, 3, 4, 5};
    ElemType b[] = {3, 4, 5, 6, 7, 8};
    L.data = a;
    R.data = b;
    L.length = sizeof(a) / sizeof(ElemType);
    R.length = sizeof(b) / sizeof(ElemType);

    PrintList(L);
    PrintList(R);
    MergeList(L, R, &LR);
    PrintList(LR);
}

int main(void)
{
    SqList L;
    CreateTestList(&L);

    // 问题1
    Q1Test(L);

    // 问题2
    Q2Test(L);

    // 问题3
    Q3Test();

    // 问题4
    Q4Test();

    // 问题5
    Q5Test();

    // 问题6
    Q6Test();

    // 问题7
    Q7Test();

    return 0;
}
