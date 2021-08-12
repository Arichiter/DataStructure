#include "StackBook.c"

void Q3Test()
{
    char *s1 = "IOIIOIOO";
    char *s2 = "IOOIOIIO";
    char *s3 = "IIIOIOIO";
    char *s4 = "IIIOOIOO";

    printf("%4d", Is_ERROR_Seqence(s1));
    printf("%4d", Is_ERROR_Seqence(s2));
    printf("%4d", Is_ERROR_Seqence(s3));
    printf("%4d", Is_ERROR_Seqence(s4));
}

int main(void)
{
    Q3Test();
}