#include <stdio.h>

int sumar(int operando1, int operando2);

int main(void){
    int num1, num2, resultado;

    printf("ingrese numero sumar: ");
    scanf("%d",&num1);

    printf("ingrese numero sumar: ");
    scanf("%d",&num2);

    resultado=sumar(num1, num2);

    printf("La suma es%d",resultado);

    return 0;
}

int sumar(int operando1, int operando2)
{
    int resultado;
    resultado = operando1 + operando2;
    return resultado;
}
