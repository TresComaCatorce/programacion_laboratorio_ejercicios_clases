#include <stdio.h>
#include <stdlib.h>

#define CANTIDADDIAS 30
#define FFLUSH fflush(stdin)
#define SALTOLINEA printf("\n")

int preguntarDeseaContinuar();

int main()
{
    /**** Declaracion de variables ****/
    float gastos[CANTIDADDIAS]; //Array que guarda los gastos
    float aux; //Variable auxiliar para
    int dia=0; //Dia del mes al que se va a cargar el gasto
    int i=0;

    /**** Inicializo el array en cero ****/
    for(i=0;i<CANTIDADDIAS;i++)
    {
        gastos[i]=0;
    }

    /*** Pido el ingreso del dia y el gasto ***/
    /*** Mientras el usuario lo desee *********/
    do
    {
        system("cls");
        printf("Ingrese el dia del gasto (1-30): ");
        FFLUSH;
        scanf("%d", &dia);
        printf("Ingrese el gasto: ");
        FFLUSH;
        scanf("%f", &aux);
        gastos[dia-1]=gastos[dia-1]+aux;
    }while(preguntarDeseaContinuar());

    /**** Limpio pantalla e imprimo un titulo ****/
    system("cls");
    printf("Dia \tGastos");
    SALTOLINEA;

    /*** Imprimo los datos de array ***/
    for(i=0;i<CANTIDADDIAS;i++)
    {
        if( gastos[i] != 0 )
        {
            printf("%d \t%.2f", (i+1), gastos[i]);
            SALTOLINEA;
        }
    }


    return 0;
}



int preguntarDeseaContinuar(void)
{
    char respuesta; //Respuesta que ingresa el usuario
    int contador = 0;


    do{
        if(contador==0)
        {
            printf("Desea continuar? (s/n)");
        }
        else
        {
            printf("ERROR! Desea continuar? (s/n) ");
        }
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta=tolower(respuesta);
        contador++;
    }while( respuesta!='s' && respuesta!='n');

    switch(respuesta)
    {
        case 's':
            return 1;
            break;
        case 'n':
            return 0;
            break;
    }
    return 0;
}
