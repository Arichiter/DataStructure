#include "StackBook.c"

void Q3Test()
{
    printf("\n***********Q3***********\n");
    char *s1 = "IOIIOIOO";
    char *s2 = "IOOIOIIO";
    char *s3 = "IIIOIOIO";
    char *s4 = "IIIOOIOO";

    printf("%4d", Is_ERROR_Seqence(s1));
    printf("%4d", Is_ERROR_Seqence(s2));
    printf("%4d", Is_ERROR_Seqence(s3));
    printf("%4d", Is_ERROR_Seqence(s4));
}

void Q4Test()
{
    printf("\n***********Q4***********\n");
    LinkList L = (LinkList) malloc (sizeof(LNode));
    L->next = NULL;
    ElemType a[] = {1, 2, 2, 1};
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
    }
    q->next = NULL;

    printf("%d\n", Is_Symmetric(&L));
    
}

int main(void)
{
    Q3Test();

    Q4Test();

    return 0;
}