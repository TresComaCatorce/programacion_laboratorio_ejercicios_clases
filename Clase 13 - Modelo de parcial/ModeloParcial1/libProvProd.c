#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "libProvProd.h"

#include "estructuras.h"

#define SLEEP_TIME 1100

/** \brief Carga algunos productos. Funcion para test.
 *
 * \param proveedores (*proveedor) Array a cargar.
 * \param largoArray (int) Largo del array.
 *
 */
void initProductosToTest( producto *productos, int largoArray )
{
    int i;

    char descripciones[6][51] = { "Intel I7", "AMD PHENOM", "INTEL I5", "MOTOROLA", "PIC768", "BM074"};
    float importes[6] = { 77.45, 68.90, 65.12, 14.80, 7.99, 17.20 };
    int cantidades[6] = { 15, 12, 8, 24, 30, 6 };
    int proveedores[6] = { 2, 1, 2, 3, 4, 5 };

    for( i=0 ; i<6 ; i++ )
    {
        productos[i].prod_habilitado = 1;
        productos[i].prod_id = (i+1);
        strcpy( productos[i].prod_descripcion, descripciones[i] );
        productos[i].prod_cantidad = cantidades[i];
        productos[i].prod_importe = importes[i];
        productos[i].prod_prov_id = proveedores[i];
    }
}


/** \brief Inicializa el array de proveedores.
 *
 * \param proveedores (*proveedor) Array a inicializar.
 * \param largoArray (int) Largo del array.
 *
 */

void initProveedores( proveedor *proveedores, int largoArray )
{
    int i;
    char nombres[][51] = { "AMD", "Intel", "Motorola" , "Silicon", "IBM" };

    for( i=0 ; i<largoArray ; i++ )
    {
        proveedores[i].prov_id = (i+1);
        strcpy( proveedores[i].prov_nombre , nombres[i] );
    }
}


/** \brief Inicializa el array de productos.
 *
 * \param productos (*producto) Array a inicializar.
 * \param largoArray (int) Largo del array.
 *
 */

void initProductos( producto *productos, int largoArray )
{
    int i;

    for( i=0 ; i<largoArray ; i++ )
    {
        productos[i].prod_habilitado = 0;
    }
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void listar( proveedor *proveedores, int largoProveedores, producto *productos, int largoProductos )
{
    int i;
    int cantProductosHabilitados;
    int prov_id;

    cantProductosHabilitados = cantidadProductos( productos, largoProductos );

    system("cls");

    if( cantProductosHabilitados > 0 )
    {
        printf("Codigo\tDescripcion\tImporte\tCantidad\tProveedor\n");
        for( i=0 ; i<largoProductos ; i++ )
        {
            if( productos[i].prod_habilitado == 1 )
            {
                prov_id = ( productos[i].prod_prov_id );
                printf("%d\t%s\t%.2f\t%d\t%s\n", productos[i].prod_id, productos[i].prod_descripcion, productos[i].prod_importe, productos[i].prod_cantidad, proveedores[prov_id].prov_nombre);
            }
        }

        printf("\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("No hay productos cargados.\n\n");
        system("pause");
    }
}


/** \brief Cuenta la cantidad de productos que hay habilitados en el array.
 *
 * \param productos (*producto) Array de productos a contar.
 * \param largoProductos (int) Largo del array.
 * \return (int) Cantidad de productos habilitados.
 *
 */
int cantidadProductos( producto *productos, int largoProductos)
{
    int i;
    unsigned int contadorProductos = 0;

    for( i=0 ; i<largoProductos ; i++)
    {
        if( productos[i].prod_habilitado == 1)
        {
            contadorProductos++;
        }
    }

    return contadorProductos;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void modificar( proveedor *proveedores, int largoProveedores, producto *productos, int largoProductos )
{
    int i;
    int cantProductos;
    int opcionMenu;
    int cod_prod_modif;
    int index = -1;
    char descripcionNueva[51];

    cantProductos = cantidadProductos( productos, largoProductos );

    //Si hay productos cargados, sino no hago nada.
    if( cantProductos > 0 )
    {
        getInt(&cod_prod_modif, "Ingrese codigo del producto a modificar: ", 1, 0, 1, 0, "Error!");

        //Recorro el array de productos y busco el que tiene el codigo que ingreso el usuario y me guardo su subindice en la variable 'index'
        for( i=0 ; i<largoProductos ; i++)
        {
            if( productos[i].prod_habilitado == 1 && productos[i].prod_id == cod_prod_modif )
            {
                index = i;
                break;
            }
        }
        if( index != -1)
        {
            do //Armo el menu preguntando que quiere modificar
            {
                opcionMenu = buildMenu("Ingrese lo que desea modificar:\n"
                                       "1)Descripcion\n"
                                       "2)Importe\n"
                                       "3)Cantidad\n"
                                       "4)Salir\n", 1, 4, 3, "Ingrese una opcion valida.");

                switch( opcionMenu )
                {
                    case 1: //Pido una nueva descripcion y la copio en el array en la posicion 'index'
                        system("cls");
                        printf("Ingrese nueva descripcion: ");
                        gets(descripcionNueva);

                        strcpy( productos[index].prod_descripcion, descripcionNueva);

                        break;
                }

            }while( opcionMenu != 4 );
        }
    }
    else
    {
        system("cls");
        printf("No hay productos cargados.\n\n");
        system("pause");
    }
}






