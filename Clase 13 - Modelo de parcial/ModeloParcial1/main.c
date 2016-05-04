#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "libProvProd.h"
#include "../../Bibliotecas/Utiles/Utiles.h"

#include "estructuras.h"

#define CANT_PROVEEDORES 5
#define CANT_PRODUCTOS 10

int main()
{
    producto productos[CANT_PRODUCTOS];
    proveedor proveedores[CANT_PROVEEDORES];
    int respuesta;

    initProductos( productos , CANT_PRODUCTOS );
    initProveedores( proveedores , CANT_PROVEEDORES );

    /*****/
    initProductosToTest( productos, CANT_PRODUCTOS );
    /*****/

    do
    {
        system("cls");
        respuesta = buildMenu(  "1)Alta\n"
                                "2)Modificar\n"
                                "3)Baja\n"
                                "4)Informar\n"
                                "5)Listar\n"
                                "6)Salir\n"
                                , 1, 6, 3, "Error! Ingrese una opcion valida.");

        switch( respuesta )
        {
            case 1:
                //doAlta( proveedores, CANT_PROVEEDORES, productos , CANT_PRODUCTOS );
                break;

            case 2:
                //doModificar( proveedores, CANT_PROVEEDORES, productos , CANT_PRODUCTOS );
                break;

            case 3:
                //doBaja( proveedores, CANT_PROVEEDORES, productos , CANT_PRODUCTOS );
                break;

            case 4:
                //informar( proveedores, CANT_PROVEEDORES, productos , CANT_PRODUCTOS );
                break;

            case 5:
                listar( proveedores, CANT_PROVEEDORES, productos , CANT_PRODUCTOS );
                break;

            case 6:
                //salir();
                break;
        }

    }while( respuesta != 6 );

    return 0;
}
