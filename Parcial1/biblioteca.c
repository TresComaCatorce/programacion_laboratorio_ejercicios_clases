#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "biblioteca.h"

#define SLEEP_TIME 1300

/** \brief Muestra un mensaje, pide un ingreso al usuario y valida que lo ingresado no sobrepase su tamaño. (Permite el ingreso de un caractér vacio).
 *
 * \param miCadena (*char) Cadena donde se almacena el ingreso del usuario, solo en caso exitoso.
 * \param largo (int) Largo de 'miCadena'.
 * \return [0]=Ingreso exitoso / [-1]=Error al ingresar el string.
 *
 */
int getString(char *miCadena, int largo, char *mensaje, char *mensajeError)
{
    int retorno = -1;
    size_t largoIngreso;
    char buffer[600];

    if( miCadena != NULL && largo > 0 )
    {
        printf("\n%s", mensaje);

        fflush(stdin);

        gets(buffer);

        largoIngreso = strlen(buffer);

        if( largoIngreso < largo )
        {
            strcpy( miCadena , buffer );
            retorno = 0;
        }
        else
        {
            system("cls");
            printf("%s", mensajeError);
            Sleep(SLEEP_TIME);
            system("cls");
        }
    }

    return retorno;
}


/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea entero y que no sobrepase el minimo ni el máximo.
 *
 * \param miEntero (int*) Dirección donde se almacena el entero, solo en caso de ingreso exitoso.
 * \param mensaje (char[]) Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo (int) Si NO tiene mínimo debe pasarse [0], si tiene mínimo debe pasarse [1].
 * \param tieneMaximo (int) Si NO tiene máximo debe pasarse [0], si tiene máximo debe pasarse [1].
 * \param minimo (int) Límite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo (int) Límite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param msjError (char[]) Mensaje mostrado al usuario en caso de ingreso incorrecto.
 *
 * \return (short int) [0]=Ingreso exitoso / [-1]=Ingreso no validado.
 *
 */
int getInt(int *miEntero, char *mensaje, char *mensajeError, int tieneMinimo, int tieneMaximo, int minimo, int maximo)
{
    int retorno = -1;
    char buffer[600];
    int verificaMaxYMin;
    int esNumero;
    int aux;

    if( miEntero != NULL )
    {
        getString(buffer, 600, mensaje, mensajeError); //Se lee el ingreso del usuario.

        if(!esStringCero(buffer, 600)) //Si el usuario NO ingresó "0" se usa atoi (ya que atoi retorna [0] como código de error y no se puede diferenciar error del ingreso de "0").
        {
            aux = atoi(buffer);
            if( aux == 0 )
            {
                esNumero = 0;
            }
            else
            {
                esNumero = 1;
            }
        }
        else //Si el usuario ingreso "0".
        {
            aux = 0;
            esNumero = 1;
        }

        if( esNumero )
        {
            //Se verifica Maximos y Minimos.
            verificaMaxYMin = verificaMaxYMinEntero(&aux, tieneMinimo, tieneMaximo, minimo, maximo);

            if( verificaMaxYMin )
            {
                *miEntero = aux;
                retorno = 0;
            }
        }

        if( retorno == -1 )
        {
            system("cls");
            printf("%s", mensajeError);
            Sleep(SLEEP_TIME);
            system("cls");
        }

    }

    return retorno;
}


/** \brief Verifica si la cadena es tiene cargado unicamente un "0".
 *
 * \param cadena (*char) Cadena a analizar.
 * \param largo (int) Largo de la cadena a analizar.
 * \return [0]=No es string de la forma "0" / [1]=Es string de la forma "0" / [-1]=Error, verifique los parámetros.
 *
 */
int esStringCero(char *cadena, int largo)
{
    int retorno = 0;
    if( cadena != NULL && largo > 1 )
    {
        if( cadena[0] == '0' && cadena[1] == '\0' )
        {
            retorno = 1;
        }
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


/** \brief (Función de uso interno de "getInt") Verifica que un número se encuentre entre el minimo y el máximo dado.
 *
 * \param numero (int*) Numero a evaluar.
 * \param tieneMinimo (int) [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo (int) [0]=No tiene máximo [1]=Tiene máximo.
 * \param minimo (int) Minimo a evaluar.
 * \param maximo (int) Máximo a evaluar.
 *
 * \return (short int) [0]=No cumple con los límites / [1]=Cumple con los límites.
 *
 */
int verificaMaxYMinEntero(int *numero, int tieneMinimo, int tieneMaximo, int minimo, int maximo)
{
    int retorno = -1;
    //Si NO tiene minimo NI máximo.
    if( !tieneMinimo && !tieneMaximo )
    {
        retorno = 1;
    }

    //Si tiene minimo y tiene maximo.
    else if( tieneMinimo && tieneMaximo )
    {
        if( *numero >= minimo && *numero <= maximo )
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    //Si tiene minimo y NO tiene maximo.
    else if( tieneMinimo && !tieneMaximo )
    {
        if( *numero >= minimo )
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    //Si NO tiene minimo y tiene maximo.
    else if( !tieneMinimo && tieneMaximo )
    {
        if(*numero <= maximo)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}
