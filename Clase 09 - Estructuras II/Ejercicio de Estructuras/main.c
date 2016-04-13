#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

#define CANTIDAD 20

int main()
{
    persona personas[CANTIDAD], auxPersona;
    int i=0, respuesta=0;

    /****--Inicializo el estado de las 'personas' en cero--****/
    for(i=0;i<CANTIDAD;i++)
    {
        personas[i].estado=0;
    }
    do
    {
        /****--Imprimo el menu--****/
        system("cls");
        respuesta=buildMenu(void);

        switch(respuesta)
        {
            case 1:
                pedir
                agregarPersona(personas);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                break;
            default:
                system("cls");
                printf("ERROR! Ingrese una opci""\xA2""n valida.\n\n");

                break;
        }
    }while(respuesta!=5);


    return 0;
}
