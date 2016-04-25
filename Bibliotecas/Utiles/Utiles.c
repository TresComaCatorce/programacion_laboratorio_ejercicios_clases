#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "Utiles.h"

/** \brief Pregunta al usuario si desea continuar.
 *
 * \return int Si el usuario eligi� NO continuar 0(cero), si el usuario eligi� continuar 1(uno).
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
 * \param numero (float) N�mero a analizar.
 *
 * \return (int) Si el n�mero no tiene decimales [1], si el n�mero tiene decimales [0].
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


/** \brief Analiza una c�dena de caracteres y nos dice si dicha c�dena es exactamente igual a "0".
 *
 * \param cadena (char[]) C�dena a analizar.
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


/** \brief Imprime un men�, pide el ingreso de opci�n la cantidad de veces indicada.
 *
 * \param menu (char[]) Opciones del men�, separadas por '\n', no debe pasarse el mensaje que pide el ingreso de la opci�n.
 * \param opcionMin (int) Opci�n m�nima del men�.
 * \param opcionMax (int) Opci�n m�xima del men�.
 * \param cantidadPreguntas (int) Cantidad de veces que se le va a preguntar a la persona en caso de fallo.
 * \param mensajeError (char[]) Mensaje mostrado en caso de ingresar una opci�n inv�lida.
 * \return (int) Opci�n seleccionada por la persona, si ingreso una opci�n inv�lida en todos los intentos devuelve [-1].
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


/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea entero y que no sobrepase los l�mites dados.
 *
 * \param miEntero (int*) Direcci�n donde se almacena el entero, solo en caso de ingreso exitoso.
 * \param mensaje (char[]) Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo (short int) Si NO tiene m�nimo debe pasarse [0], si tiene m�nimo debe pasarse [1].
 * \param tieneMaximo ( short int) Si NO tiene m�ximo debe pasarse [0], si tiene m�ximo debe pasarse [1].
 * \param minimo (int) L�mite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo (int) L�mite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
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

    if(!esStringCero(buffer)) //Si el usuario NO ingres� "0" se usa atoi (ya que atoi retorna [0] como c�digo de error y no se puede diferenciar error del ingreso de "0").
    {
        aux = atoi(buffer);
        if(aux == 0) //Si 'aux' es igual a [0] significa que hay error (porque ya se valid� que sea !=0).
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


/** \brief (Funci�n de uso interno de "getInt") Verifica que un n�mero se encuentre entre el minimo y el m�ximo dado.
 *
 * \param numero (int*) Numero a evaluar.
 * \param tieneMinimo (short int*) [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo (short int*) [0]=No tiene m�ximo [1]=Tiene m�ximo.
 * \param minimo (int) Minimo a evaluar.
 * \param maximo (int) M�ximo a evaluar.
 *
 * \return [0]=No cumple con los l�mites / [1]=Cumple con los l�mites.
 *
 */
short int verificarMaxYMinEntero(int* numero, short int* tieneMinimo, short int* tieneMaximo, int* minimo, int* maximo)
{
    //Si NO tiene minimo NI m�ximo.
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




/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea float y que no sobrepase los l�mites dados.
 *
 * \param miFloat (float*) Direcci�n donde se almacena el float, solo en caso de ingreso exitoso.
 * \param mensaje (char[]) Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo (short int) Si NO tiene m�nimo debe pasarse [0], si tiene m�nimo debe pasarse [1].
 * \param tieneMaximo ( short int) Si NO tiene m�ximo debe pasarse [0], si tiene m�ximo debe pasarse [1].
 * \param minimo (float) L�mite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo (float) L�mite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
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

    if(!esStringCero(buffer)) //Si el usuario NO ingres� "0" se usa atoi (ya que atoi retorna [0] como c�digo de error y no se puede diferenciar error del ingreso de "0").
    {
        aux = atof(buffer);
        if(aux == 0) //Si 'aux' es igual a [0] significa que hay error (porque ya se valid� que sea !=0).
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


/** \brief (Funci�n de uso interno de "getFloat") Verifica que un n�mero se encuentre entre el minimo y el m�ximo dado.
 *
 * \param numero (float*) Numero a evaluar.
 * \param tieneMinimo (short int*) [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo (short int*) [0]=No tiene m�ximo [1]=Tiene m�ximo.
 * \param minimo (float) Minimo a evaluar.
 * \param maximo (float) M�ximo a evaluar.
 *
 * \return [0]=No cumple con los l�mites / [1]=Cumple con los l�mites.
 *
 */
short int verificarMaxYMinFloat(float* numero, short int* tieneMinimo, short int* tieneMaximo, float* minimo, float* maximo)
{
    //Si NO tiene minimo NI m�ximo.
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
