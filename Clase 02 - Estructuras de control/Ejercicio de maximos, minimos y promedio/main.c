#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaracion de variables
    float buffNumero, maximo, minimo, acumuladorNumeros=0, promedioNumeros=0;
    int contadorNumeros=0, condicional=1, flag1raVez=1;
    char respuesta='s';

    /*DO WHILE PARA PEDIR INGRESO DE NUMEROS Y ASIGNACIONES*/
    do{
        //Se pide el ingreso del numero
        printf("Ingrese un n%cmero: \n", 163);
        fflush(stdin);
        scanf("%f", &buffNumero);
        //printf("\n");

        //Si es el primer ingreso, se asignan los maximos y minimos
        if(flag1raVez==1){
            maximo=buffNumero;
            minimo=buffNumero;
            flag1raVez=0;
        }

        //Si es maximo, se lo asigna
        if(buffNumero>maximo){
            maximo=buffNumero;
        }

        //Si es minimo, se lo asigna
        if(buffNumero<minimo){
            minimo=buffNumero;
        }

        //Se incrementa el contador y el acumulador
        contadorNumeros++;
        acumuladorNumeros+=buffNumero;

        //Se pregunta si se desea continuar ingresando numeros
        printf("Desea ingresar otro n%cmero? (s/n)\n", 163);
        fflush(stdin);
        scanf("%c", &respuesta);
        printf("\n");

        //Analizo la respuesta
        if(respuesta=='n'){
            condicional=0;
        }
    }while(condicional);
    /*FIN DEL DO WHILE PARA LOS INGRESOS DEL USUARIO*/

    //Calculo el promedio
    promedioNumeros=acumuladorNumeros/(float)contadorNumeros;

    //Imprimo los resultados
    printf("El m%cximo es: %.2f \n", 160, maximo);
    printf("El m%cnimo es: %.2f \n", 161, minimo);
    printf("El promedio es: %.2f \n", promedioNumeros);
    printf("Se ingresaron %i n%cmeros.", contadorNumeros, 163);

    return 0;
}
