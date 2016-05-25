#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define SLEEP_TIME 1200
#define CLEAR_SCREEN "cls"

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include "estructuras.h"
#include "../Bibliotecas/Utiles/Utiles.h"

void initMovies( sMovie *peliculas, int length );

void imprimirListaPeliculas( sMovie *peliculas, int length );

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(sMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(sMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(sMovie lista[], char nombre[]);



#endif // FUNCIONES_H_INCLUDED
