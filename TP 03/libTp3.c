#include "libTp3.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void initMovies( sMovie *peliculas, int length )
{
    if( peliculas != NULL && length > 0 )
    {
        int i;
        char titulos[3][20] = {"Matrix", "A serbian film", "A clockwork orange"};
        char generos[3][20] = {"Accion", "Horror", "Drama"};
        int duraciones[3] = {120, 111, 215};
        char descripciones[3][50] = {"Matrix description.", "A serbian film description.", "A clockwork orange description."};
        int puntajes[3] = {8, 10, 9};
        char linkImagenes[3][150] = {"https://upload.wikimedia.org/wikipedia/en/c/c1/The_Matrix_Poster.jpg", "http://images.moviepostershop.com/a-serbian-film-movie-poster-2010-1020669469.jpg", "https://c1.staticflickr.com/7/6013/6015447285_dbbe78d881_b.jpg"};

        for( i=0; i<3 ; i++ )
        {
            strcpy( peliculas[i].titulo, titulos[i] );
            strcpy( peliculas[i].genero, generos[i] );
            strcpy( peliculas[i].descripcion, descripciones[i] );
            strcpy( peliculas[i].linkImagen, linkImagenes[i] );
            peliculas[i].duracion = duraciones[i];
            peliculas[i].puntaje = puntajes[i];
            peliculas[i].estado = 1;
        }

    }
}

void imprimirListaPeliculas( sMovie *peliculas, int length )
{
    if( peliculas != NULL && length > 0  )
    {
        int i;
        system(CLEAR_SCREEN);
        printf("Titulo\t\tPuntaje\tGenero\tDuracion\tDescripcion\n");
        for( i=0 ; i<length ; i++ )
        {
            if( peliculas[i].estado == 1 )
            {
                printf("%s\t\t%d\t%s\t%d\t%s\n", peliculas[i].titulo, peliculas[i].puntaje, peliculas[i].genero, peliculas[i].duracion, peliculas[i].descripcion );

            }
        }

        printf("\n");
        system("pause");
    }
}


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(sMovie movie)
{

}

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(sMovie movie)
{

}

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(sMovie lista[], char nombre[])
{

}
