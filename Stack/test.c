#include "LinearStack.c"

void test1()
{
    SqStack S;
    InitStack(&S);

    for (int i = 0; i < 10; i++)
        Push(&S, rand() % 20 + 1);
    PrintSqStack(S);

    ElemType x;
    Pop(&S, &x);
    PrintSqStack(S);
    printf("The delete top stack element is %d\n", x);

    GetTop(S, &x);
    printf("The top stack element is %d\n", x);

}

int main(void)
{
    test1();
    return 0;
}