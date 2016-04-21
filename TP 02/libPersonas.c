#include "../Bibliotecas/Utiles/Utiles.h"
#include <windows.h>

//
short int runPersonas(void)
{
    while(65)
    {
        short int error;
        int myNumber;

        error = getInt(&myNumber, "Ingrese Nro: ", 1, 1, 5, 10, "ERROR");


        printf("Numero: %d\n", myNumber);
        printf("Error: %d\n", error);
        system("pause");
    }
}
