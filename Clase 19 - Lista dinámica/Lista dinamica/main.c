#include "includes.h"

int main()
{
    int error;

    int num;
    int *p;
    int **q;

    p = &num;

    *p = 5;

    *q = p;

    printf("%d", **q);

    return 0;
}
