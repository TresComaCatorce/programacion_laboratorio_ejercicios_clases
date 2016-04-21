#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Prototipos de funciones

int preguntarDeseaContinuar();

int esEntero(float numero);
int esStringCero(char* cadena);
int buildMenu(char menu[], int opcionMin, int opcionMax, int cantidadPreguntas, char mensajeError[]);

short int getInt(int* retorno, char mensaje[], short int tieneMinimo, short int tieneMaximo, int minimo, int maximo, char msjError[]);
short int getFloat(float* retorno, char mensaje[], short int tieneMinimo, short int tieneMaximo, float minimo, float maximo, char msjError[]);
