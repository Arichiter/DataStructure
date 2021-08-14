#include "SqQueue.c"

void test()
{
    SqQueue Q;
    InitQueue(&Q);
    for (int i = 0; i < 20; i++)
        EnQueue(&Q, rand() % 20 + 1);

    PrintQueue(Q);

    int x;
    DeQueue(&Q, &x);
    printf("%d\n", x);
    PrintQueue(Q);
}

int main(void)
{
    test();
    return 0;
}