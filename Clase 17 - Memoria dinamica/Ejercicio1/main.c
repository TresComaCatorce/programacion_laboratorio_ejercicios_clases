#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[31];
    float salario;
}eEmpleado;

int main()
{
    int *a;

    a = (int*)malloc(sizeof(int));

    if( a == NULL )
    {
        printf("No hay memoria suficiente.\n\n");
        exit(0);
    }
    else
    {
        *a = 87;
    }

    free(a);

    return 0;
}
