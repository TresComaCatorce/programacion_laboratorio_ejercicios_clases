#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    //char cadena[5];
    int miEntero;
    int error;

    //error = getString(cadena, 5, "Ingrese algo: ", "ERROR!");
    error = getInt(&miEntero, "Ingrese num: ", "ERROR!", 0, 0, 0, 0);

    printf("Entero: %d\nError: %d\n", miEntero, error);
    return 0;
}
