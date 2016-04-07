#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD 50

int main()
{
    /*Declaracion de variables*/
    char nombre[CANTIDAD+1];
    char apellido[CANTIDAD+1];
    char apellidoYNombre[CANTIDAD+3]="";
    char buffer[CANTIDAD*20];
    int cantidadLetras=0;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(buffer);
    cantidadLetras = strlen(buffer);

    if(cantidadLetras<=CANTIDAD)
    {
        strcpy(nombre,buffer);
    }

    while(cantidadLetras>CANTIDAD){
        printf("Error! Vuelva a ingresar el nombre: ");
        fflush(stdin);
        gets(buffer);
        cantidadLetras = strlen(buffer);
        if(cantidadLetras<=CANTIDAD)
        {
            strcpy(nombre,buffer);
        }
    }

    cantidadLetras=0;

    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(buffer);
    cantidadLetras = strlen(buffer);

    if(cantidadLetras<=CANTIDAD)
    {
        strcpy(apellido,buffer);
    }

    while(cantidadLetras>CANTIDAD){
        printf("Error! Vuelva a ingresar el apellido: ");
        fflush(stdin);
        gets(buffer);
        cantidadLetras = strlen(buffer);
        if(cantidadLetras<CANTIDAD)
        {
            strcpy(apellido, buffer);
        }
    }

    strcat(apellidoYNombre, apellido);
    strcat(apellidoYNombre, ", ");
    strcat(apellidoYNombre, nombre);

    system("cls");
    printf("\n\n \t %s \n\n", apellidoYNombre);

    return 0;
}
