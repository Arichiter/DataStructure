#include "LinkList.c"

int main(void) 
{
    LinkList L;
    InitLinkList(&L);

    // HeadCreateLinkList(&L, 10);
    TailCreateLinkList(&L, 10);
    PrintLinkList(L);




}