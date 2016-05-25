#include <stdio.h>
#include <stdlib.h>

#include "estructuras.h"
#include "libTp3.h"

#include "../Bibliotecas/Utiles/Utiles.h"


int main()
{
    int opcion;
    int size = 10;
    sMovie *peliculas=(sMovie*)malloc( sizeof(sMovie) * size );

    do
    {
        opcion = buildMenu("1)Agregar pel""\xA1""cula"
                          "2)Borrar pel""\xA1""cula"
                          "3)Modificar pel""\xA1""cula"
                          "4)Generar p""A0""gina web"
                          "5)Salir", 1, 5, 3, "Error! Opci""\xA2""n inv""\xA0""lida.");


        switch(opcion)
        {
            case 1:
                //agregarPelicula();
                break;
            case 2:
                //borrarPelicula();
                break;
            case 3:
                //modificarPelicula();
               break;
            case 4:
                //generarPagina();
                break;
            case 5:
                break;
        }

    }while( opcion != 5 );

    return 0;
}
