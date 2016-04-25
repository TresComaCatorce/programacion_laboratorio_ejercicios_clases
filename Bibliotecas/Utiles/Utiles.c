#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "Utiles.h"

/** \brief Pregunta al usuario si desea continuar.
 *
 * \return int Si el usuario eligió NO continuar 0(cero), si el usuario eligió continuar 1(uno).
 *
 */
int preguntarDeseaContinuar()
{
    char respuesta; //Respuesta que ingresa el usuario
    int contador = 0;


    do{
        if(contador==0)
        {
            printf("Desea continuar? (s/n)");
        }
        else
        {
            printf("ERROR! Desea continuar? (s/n) ");
        }
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta=tolower(respuesta);
        contador++;
    }while( respuesta!='s' && respuesta!='n');

    switch(respuesta)
    {
        case 's':
            return 1;
            break;
        case 'n':
            return 0;
            break;
    }
    return 0;
}


/** \brief Valida si una variable float es tiene o no decimal.
 *
 * \param numero (float) Número a analizar.
 *
 * \return (int) Si el número no tiene decimales [1], si el número tiene decimales [0].
 *
 */
int esEntero(float numero)
{
    float auxiliar;
    auxiliar = numero - (int)numero;
    if(auxiliar == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/** \brief Analiza una cádena de caracteres y nos dice si dicha cádena es exactamente igual a "0".
 *
 * \param cadena (char[]) Cádena a analizar.
 *
 * \return (int) Si no es una cadena de la forma "0" retorna [0], si la cadena es igual a "0" retorna [1].
 *
 */
int esStringCero(char* cadena)
{
    if(cadena[0]=='0' && cadena[1]=='\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/** \brief Imprime un menú, pide el ingreso de opción la cantidad de veces indicada.
 *
 * \param menu (char[]) Opciones del menú, separadas por '\n', no debe pasarse el mensaje que pide el ingreso de la opción.
 * \param opcionMin (int) Opción mínima del menú.
 * \param opcionMax (int) Opción máxima del menú.
 * \param cantidadPreguntas (int) Cantidad de veces que se le va a preguntar a la persona en caso de fallo.
 * \param mensajeError (char[]) Mensaje mostrado en caso de ingresar una opción inválida.
 * \return (int) Opción seleccionada por la persona, si ingreso una opción inválida en todos los intentos devuelve [-1].
 *
 */
int buildMenu(char menu[], int opcionMin, int opcionMax, int cantidadPreguntas, char mensajeError[])
{
    int respuesta;
    short int error;
    int contadorIntentos=0;

    do
    {
        system("cls");
        printf("%s", menu);
        printf("\n\nIngrese la opci""\xE0""n deseada: ");
        fflush(stdin);
        error = getInt(&respuesta, "", 1, 1, opcionMin, opcionMax, mensajeError);

        if( error != -1)
        {
            return respuesta;
            break;
        }

        contadorIntentos++;
    }while( contadorIntentos < cantidadPreguntas );

    return -1;
}


/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea entero y que no sobrepase los límites dados.
 *
 * \param miEntero (int*) Dirección donde se almacena el entero, solo en caso de ingreso exitoso.
 * \param mensaje (char[]) Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo (short int) Si NO tiene mínimo debe pasarse [0], si tiene mínimo debe pasarse [1].
 * \param tieneMaximo ( short int) Si NO tiene máximo debe pasarse [0], si tiene máximo debe pasarse [1].
 * \param minimo (int) Límite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo (int) Límite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param msjError (char[]) Mensaje mostrado al usuario en caso de ingreso incorrecto.
 *
 * \return (int) [0]=Ingreso exitoso / [-1]=Ingreso no validado.
 *
 */
short int getInt(int* miEntero, char mensaje[], short int tieneMinimo, short int tieneMaximo, int minimo, int maximo, char msjError[])
{
    char buffer[601]; //Buffer para lectura de la entrada por teclado del usuario.
    int aux; //Auxiliar utilizado para analizar maximos y minimos sin asignar.
    short int verificaMaxYMin;

    printf("%s", mensaje);
    fflush(stdin);
    gets(buffer); //Se lee el ingreso del usuario.

    if(!esStringCero(buffer)) //Si el usuario NO ingresó "0" se usa atoi (ya que atoi retorna [0] como código de error y no se puede diferenciar error del ingreso de "0").
    {
        aux = atoi(buffer);
        if(aux == 0) //Si 'aux' es igual a [0] significa que hay error (porque ya se validó que sea !=0).
        {
            system("cls");
            printf("%s\n", msjError);
            Sleep(1500);
            return -1;
        }
        else //Si no es error se chequean maximos y minimos, etc.
        {
            verificaMaxYMin = verificarMaxYMinEntero(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
            if(verificaMaxYMin)
            {
                *miEntero = aux;
                return 0;
            }
            else
            {
                system("cls");
                printf("%s\n", msjError);
                Sleep(1500);
                return -1;
            }
        }
    }
    else //Si el usuario ingreso "0".
    {
        //Se verifica Maximos y Minimos.
        aux = 0;
        verificaMaxYMin = verificarMaxYMinEntero(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
            if(verificaMaxYMin)
            {
                *miEntero = aux;
                return 0;
            }
            else
            {
                system("cls");
                printf("%s\n", msjError);
                Sleep(1500);
                return -1;
            }
    }
    return -1;
}


/** \brief (Función de uso interno de "getInt") Verifica que un número se encuentre entre el minimo y el máximo dado.
 *
 * \param numero (int*) Numero a evaluar.
 * \param tieneMinimo (short int*) [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo (short int*) [0]=No tiene máximo [1]=Tiene máximo.
 * \param minimo (int) Minimo a evaluar.
 * \param maximo (int) Máximo a evaluar.
 *
 * \return [0]=No cumple con los límites / [1]=Cumple con los límites.
 *
 */
short int verificarMaxYMinEntero(int* numero, short int* tieneMinimo, short int* tieneMaximo, int* minimo, int* maximo)
{
    //Si NO tiene minimo NI máximo.
    if(!*tieneMinimo && !*tieneMaximo)
    {
        return 1;
    }

    //Si tiene minimo y tiene maximo.
    else if(*tieneMinimo && *tieneMaximo)
    {
        if(*numero >= *minimo && *numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si tiene minimo y NO tiene maximo.
    else if(*tieneMinimo && !*tieneMaximo)
    {
        if(*numero >= *minimo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si NO tiene minimo y tiene maximo.
    else if(!*tieneMinimo && *tieneMaximo)
    {
        if(*numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}




/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea float y que no sobrepase los límites dados.
 *
 * \param miFloat (float*) Dirección donde se almacena el float, solo en caso de ingreso exitoso.
 * \param mensaje (char[]) Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo (short int) Si NO tiene mínimo debe pasarse [0], si tiene mínimo debe pasarse [1].
 * \param tieneMaximo ( short int) Si NO tiene máximo debe pasarse [0], si tiene máximo debe pasarse [1].
 * \param minimo (float) Límite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo (float) Límite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param msjError (char[]) Mensaje mostrado al usuario en caso de ingreso incorrecto.
 *
 * \return (int) [0]=Ingreso exitoso / [-1]=Ingreso no validado.
 *
 */

short int getFloat(float* miFloat, char mensaje[], short int tieneMinimo, short int tieneMaximo, float minimo, float maximo, char msjError[])
{
    char buffer[601]; //Buffer para lectura de la entrada por teclado del usuario.
    float aux; //Auxiliar utilizado para analizar maximos y minimos sin asignar.
    short int verificaMaxYMin;

    printf("%s", mensaje);
    fflush(stdin);
    gets(buffer); //Se lee el ingreso del usuario.

    if(!esStringCero(buffer)) //Si el usuario NO ingresó "0" se usa atoi (ya que atoi retorna [0] como código de error y no se puede diferenciar error del ingreso de "0").
    {
        aux = atof(buffer);
        if(aux == 0) //Si 'aux' es igual a [0] significa que hay error (porque ya se validó que sea !=0).
        {
            system("cls");
            printf("%s\n", msjError);
            Sleep(1500);
            return -1;
        }
        else //Si no es error se chequean maximos y minimos, etc.
        {
            verificaMaxYMin = verificarMaxYMinFloat(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
            if(verificaMaxYMin)
            {
                *miFloat = aux;
                return 0;
            }
            else
            {
                system("cls");
                printf("%s\n", msjError);
                Sleep(1500);
                return -1;
            }
        }
    }
    else //Si el usuario ingreso "0".
    {
        //Se verifica Maximos y Minimos.
        aux = 0;
        verificaMaxYMin = verificarMaxYMinFloat(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
            if(verificaMaxYMin)
            {
                *miFloat = aux;
                return 0;
            }
            else
            {
                system("cls");
                printf("%s\n", msjError);
                Sleep(1500);
                return -1;
            }
    }
    return -1;
}


/** \brief (Función de uso interno de "getFloat") Verifica que un número se encuentre entre el minimo y el máximo dado.
 *
 * \param numero (float*) Numero a evaluar.
 * \param tieneMinimo (short int*) [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo (short int*) [0]=No tiene máximo [1]=Tiene máximo.
 * \param minimo (float) Minimo a evaluar.
 * \param maximo (float) Máximo a evaluar.
 *
 * \return [0]=No cumple con los límites / [1]=Cumple con los límites.
 *
 */
short int verificarMaxYMinFloat(float* numero, short int* tieneMinimo, short int* tieneMaximo, float* minimo, float* maximo)
{
    //Si NO tiene minimo NI máximo.
    if(!*tieneMinimo && !*tieneMaximo)
    {
        return 1;
    }

    //Si tiene minimo y tiene maximo.
    else if(*tieneMinimo && *tieneMaximo)
    {
        if(*numero >= *minimo && *numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si tiene minimo y NO tiene maximo.
    else if(*tieneMinimo && !*tieneMaximo)
    {
        if(*numero >= *minimo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si NO tiene minimo y tiene maximo.
    else if(!*tieneMinimo && *tieneMaximo)
    {
        if(*numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
