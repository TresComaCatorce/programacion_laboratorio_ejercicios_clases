#include <stdio.h>
#include <stdlib.h>
#include "../Bibliotecas/Utiles/Utiles.h"
#include "libPersonas.h"

void main()
{
    int returnedValue;
    returnedValue = runPersonas();

    if(returnedValue == 0)
    {
        "SYSTEM OFF"
    }
    else
    {
        "SYSTEM OFF EXCEED"
    }
}
