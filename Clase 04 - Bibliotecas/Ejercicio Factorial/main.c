#include <stdio.h>
#include <stdlib.h>
#include "misfunciones.h"

int main()
{
    //Declaracion de variables
    int numero, factorial;

    //Se lee un numero
    printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%d", &numero);

    while(numero<1) { //Se valida unicamente que sea mayor a 1
        printf("Error! Reingrese un numero: ");
        fflush(stdin);
        scanf("%d", &numero);
    }

    //Se llama a la funcion que calcula el factorial de manera recursiva
    factorial=calcularSFactorial(numero);

    //Se imprime el resultado
    printf("Factorial: %d \n \n", factorial);

    return 0;
}
