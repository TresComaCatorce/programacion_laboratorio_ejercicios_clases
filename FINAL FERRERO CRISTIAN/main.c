#include "includes.h"

int main()
{
    s_Auto miAuto;
    int opcion;

    do
    {
        opcion = buildMenu("1)Cargar todos los datos del auto\n"
                          "2)Modificar marca\n"
                          "3)Modificar modelo\n"
                          "4)Modificar color\n"
                          "5)Modificar patente\n"
                          "6)Mostrar datos del auto\n"
                          "7)Salir", 1, 7, 3, "Error! Opci""\xA2""n inv""\xA0""lida.");


        switch(opcion)
        {
            case 1:
                cargarTodosLosDatosDelAuto(&miAuto);
                break;

            case 2:
                modificarMarca(&miAuto);
                break;

            case 3:
                modificarModelo(&miAuto);
                break;

            case 4:
                modificarColor(&miAuto);
                break;

            case 5:
                modificarPantente(&miAuto);
                break;

            case 6:
                mostrarDatosDelAuto(&miAuto);
                break;
        }

    }while( opcion != 7 );

    return 0;
}
