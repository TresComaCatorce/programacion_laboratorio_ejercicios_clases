#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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


/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea entero y que no sobrepase los límites dados.
 *
 * \param retorno (int*) Dirección donde se almacena el entero, solo en caso de ingreso exitoso.
  *
 * \param mensaje (char*) Mensaje mostrado al usuario cuando se pide el ingreso.
  *
 * \param minimo (int) Límite inferior.
  *
 * \param maximo (int) Límite superior.
 *
 * \return char* Mensaje que se muestra al usuario en caso de error.
 *
 */
int getInt(int* retorno, char* mensaje, int minimo, int maximo, char* msjError)
{
    char buffer[601];
    int aux;

    printf("%s", mensaje); //Pido el ingreso del numero

    fflush(stdin);

    gets(buffer); //Leo el ingreso del usuario

    if(!esStringCero(buffer))
    {
        aux = atoi(buffer);
        if(aux == 0)
        {
            printf("%s", msjError);
            return -1;
        }
        else
        {
            if(aux>minimo || aux<maximo)
            {
                *retorno = aux;
                return 1;
            }
            else
            {
                printf("%s", msjError);
                return -1;
            }
        }
    }
    else
    {
        *retorno = 0;
        return 1;
    }


}
