#include "SqListBook.c"

void CreateTestList(SqList *L);

void Q1Test(SqList L);

int main(void)
{
    SqList L;

    CreateTestList(&L);

    Q1Test(L);

    return 0;
}

void CreateTestList(SqList *L)
{
    InitList(L);

    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        L->data[i] = rand() % 20 + 1;
        L->length++;
    }
    PrintList((*L));
}

void Q1Test(SqList L)
{
    ElemType e;
    DelMinNum(&L, &e);
    PrintList(L);
    printf("The min num is %d\n", e);
}