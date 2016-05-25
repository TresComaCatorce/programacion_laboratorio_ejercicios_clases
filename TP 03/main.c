#include "libTp3.h"


int main()
{
    int opcion;
    int size = 10;
    sMovie *peliculas=(sMovie*)malloc( sizeof(sMovie) * size );

    FILE *pArch = fopen("movies.dat", "r+b");

    initMovies(peliculas, size);

    do
    {
        opcion = buildMenu("1)Agregar pel""\xA1""cula\n"
                          "2)Borrar pel""\xA1""cula\n"
                          "3)Modificar pel""\xA1""cula\n"
                          "4)Generar p""\xA0""gina web\n"
                          "5)Salir\n"
                          "6)(TO TEST)Imprimir lista peliculas", 1, 6, 3, "Error! Opci""\xA2""n inv""\xA0""lida.");


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
            case 6:
                imprimirListaPeliculas( peliculas, size );
                break;
        }

    }while( opcion != 5 );

    return 0;
}
