#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

#define CANTIDAD 10

int main()
{
    empleado empleados[CANTIDAD], auxEmpleado;
    int i=0, respuesta=0;

    /****--Inicializo el estado de los 'empleados' en cero--****/
    for(i=0;i<CANTIDAD;i++)
    {
        empleados[i].estado=0;
    }

    do
    {
        /****--Imprimo el menu--****/
        system("cls");
        respuesta = buildMenu("1) Agregar persona \n2) Borrar persona \n3) Imprimir lista ordenada alfabeticamente por nombre \n4) Imprimir gr""\xA0""fico de edades \n5) Salir", 1, 5, 3, "ERROR! Opci""\xE0""n inv""\xA0""lida.");

        if( respuesta != -1)
            switch( respuesta )
            {
                case 1:
                    agregarEmpleado( empleados , CANTIDAD );
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
    }while(0);


    return 0;
}
