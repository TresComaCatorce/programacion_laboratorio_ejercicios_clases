#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 15

int main()
{
    int legajos[CANTIDAD]; //Array que guarda el Nº de legajo
    float salarios[CANTIDAD]; //Array que guarda los salarios
    int i=0;
    float aux;

        /*Se cargan los legajos en el array de forma secuencial*/
        /*Y se cargan los salarios en el array de salarios******/
    for( i=0 ; i<CANTIDAD ; i++ )
    {
        printf("Ingrese el numero de legajo: ");
        fflush(stdin);
        scanf("%d", &legajos[i]);
        printf("Ingrese el salario: ");
        fflush(stdin);
        scanf("%f", &aux); //Para evitar errores con scanf de Floats
        salarios[i]=aux;
        system("cls");
    }

    printf("Legajo \tSalario\n");

    /*Imprimo los legajos y salarios*/
    for( i=0 ; i<CANTIDAD ; i++ )
    {
        printf("%d \t%.2f", legajos[i], salarios[i]);
        printf("\n");
    }



    return 0;
}
