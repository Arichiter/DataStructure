#include "LinkList.c"

int main(void) 
{
    LNode p;
    p.data = 10;
    p.next = NULL;
    printf("p = %x, &p.data = %x, &p.next = %x, &p = %x\n", p, &(p.data), &(p.next), &p);

    LinkList q = (LinkList) malloc (sizeof(LNode));
    q->data = 20;
    q->next = &p;
    printf("q = %x, &q = %x, q->next = %x\n", q, &q, q->next);

    int *h;
    printf("p size = %d, q size = %d\n, h size = %d", sizeof(p), sizeof(q), sizeof(h));

    LinkList *L;
    L = q;
    
    return 0;

}