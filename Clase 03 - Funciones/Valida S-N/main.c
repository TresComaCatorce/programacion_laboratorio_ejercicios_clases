#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

/*---Prototipo de la funcion que pregunta ¿continuar? y valida la rta---*/
int validaS_N(void);

int main()
{
    //Declaro las variables
    float numero, acumulador=0;

    //Pido el numero mientras validaS_N() devuelva 'TRUE'
    do{
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%f", &numero);
        acumulador=acumulador+numero;
    }while( validaS_N() );

    //Muestro la suma de los numeros
    printf("La suma de los numeros es: %f", acumulador);

    return 0;
}

//Funcion que pide la respuesta y la valida.
int validaS_N(void){
    char respuesta;
    //Pregunto si desea continuar
    do{
        printf("Continua? S/N ");
        fflush(stdin);
        scanf("%c", &respuesta);
        printf("\n");
        respuesta=tolower(respuesta);
        //Valido que la respuesta sea 's' o 'n'
        switch(respuesta){
            case 's':
                    return TRUE;
                    break;
            case 'n':
                    return FALSE;
                    break;
            default :
                    printf("Error! Debe ingresar 'S' o 'N' \n");
                    break;
        }
    }while(respuesta!='s' && respuesta!='n');
}
