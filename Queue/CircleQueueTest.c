#include "CircleQueue.c"
#include "../Stack/LinearStack.c"

void Q1Test()
{
    printf("\n************Q1************\n");
    CQueue Q;
    InitQueue(&Q);

    ElemType x;
    if (DeQueue(&Q, &x))
        printf("The front element is %4d\n", x);
    else
        printf("The queue is empty!\n");

    for (int i = 0; i < 5; i++)
        EnQueue(&Q, rand() % 20 + 1);

    PrintQueue(Q);
}

void Q2Test()
{
    printf("\n************Q2************\n");
    CQueue Q;
    InitQueue(&Q);

    SqStack S;
    InitStack(&S);

    for (int i = 0; i < 5; i++)
        EnQueue(&Q, rand() % 20 + 1);
    PrintQueue(Q);

    ElemType x;
    while (DeQueue(&Q, &x))
        Push(&S, x);
    PrintSqStack(S);

    while (Pop(&S, &x))
        EnQueue(&Q, x);

    PrintQueue(Q);
}

int main(void)
{
    Q1Test();

    Q2Test();

    return 0;
}