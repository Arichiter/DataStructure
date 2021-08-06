#include "LinkListBook.c"

void Q1Test()
{
    LinkList L;
    L = (LinkList) malloc (sizeof(LNode));
    L->data = 1;
    L->next = NULL;

    int x;
    LNode *q = L;
    for (int i = 0; i < 10; i++)
    {
        LNode *p = (LNode *) malloc (sizeof(LNode));
        scanf("%d", &x);
        p->data = x;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    // 1 6 2 5 1 5 9 8 5 5
    PrintLinkList(L);
    DelNum(&L, 5);
    PrintLinkList(L);

}

int main(void)
{   
    Q1Test();

    return 0;
}