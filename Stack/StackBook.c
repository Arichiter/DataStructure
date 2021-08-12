#include "LinearStack.c"

bool Is_ERROR_Seqence(char *c)
{
    int i = 0, j = 0;
    while (c[i] != '\0')
    {
        if (c[i] == 'I') j++;
        else j--;

        if (j < 0) return false;

        i++;
    }
    return true;
}