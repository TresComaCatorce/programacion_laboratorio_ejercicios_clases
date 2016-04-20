#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "biblioteca.h"

#define CANTIDAD 20

/** \brief Imprime el menú del sistema.
 *
 * \param menu (char[]) Opciones del menú, separadas por '\n', no debe pasarse el mensaje que pide el ingreso.
 * \param opcionMin (int) Opción mínima del menú.
 * \param opcionMax (int) Opción máxima del menú.
 * \param cantidadPreguntas (int) Cantidad de veces que se le va a preguntar a la persona en caso de fallo.
 * \param mensajeError (char[]) Mensaje mostrado en caso de ingresar una opción inválida.
 * \return (int) Opción seleccionada por la persona, si no ingreso una opción válida en todos los intentos devuelve [-1].
 *
 */
int buildMenu(char menu[], int opcionMin, int opcionMax, int cantidadPreguntas, char mensajeError[])
{
    int respuesta;
    int contadorIntentos=0;

    do
    {
        system("cls");
        printf("%s", menu);
        printf("\n\nIngrese la opci""\xE0""n deseada: ");
        fflush(stdin);
        scanf("%d", &respuesta);

        if( respuesta < opcionMin || respuesta > opcionMax)
        {
            printf("%s", mensajeError);
            Sleep(2000);
        }
        else
        {
            return respuesta;
        }
        contadorIntentos++;
    }while(contadorIntentos<cantidadPreguntas);

    return -1;
}





/** \brief Agrega, por referencia, un empleado al array recibido, verifica que el estado sea cero para cargar la persona.
 *
 * \param empleados (empleado[]) Array donde guardo todos los empleados.
 * \param largo (int) Largo del array de empleados.
 * \return (int) Si agregó el array correctamente[1] ,si no hay lugar para cargarlo [-1].
 *
 */

int agregarEmpleado(empleado empleados[], int largo)
{
    int i=0, escribio=0;
    for(i=0;i<CANTIDAD;i++)
    {
        if(empleados[i].estado==0)
        {
            system("cls");
            printf("Ingrese el legajo: ");
            scanf("%d", &empleados[i].legajo);
            /*gets(personas[i].nombre);
            printf("\nIngrese el apellido: ");
            fflush(stdin);
            scanf("%d", &personas[i].edad);
            printf("\nIngrese el DNI: ");
            fflush(stdin);
            gets(personas[i].dni);
            personas[i].estado=1;*/
            printf("%d", empleados[i].legajo);

            escribio=1;
            break;
        }
    }
    if(escribio==1)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

/*
void imprimirListaOrdenadaAlfabeticamente(persona persona)
{
    //Recibe: el vector
    //Devuelve: NADA
}
*/
