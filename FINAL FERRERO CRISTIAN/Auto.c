#include "includes.h"

/** \brief "settea" la marca del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto.
 * \param marca (char*) Marca a "settear".
 * \return (int) [0]=Error al cargar // [1]=Cargado con exito.
 *
 */
int auto_setMarca( s_Auto* pAuto, char* marca )
{
    int retorno = 0;

    if( pAuto != NULL && marca != NULL && esMarcaValida(marca) )
    {
        strcpy( pAuto->marca, marca );
        retorno = 1;
    }

    return retorno;
}


/** \brief "settea" el modelo del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto.
 * \param modelo (int) Modelo a "settear".
 * \return (int) [0]=Error al cargar // [1]=Cargado con exito.
 *
 */
int auto_setModelo( s_Auto* pAuto, int modelo )
{
    int retorno = 0;

    if( pAuto != NULL && modelo != NULL && esModeloValido(modelo) )
    {
        pAuto->modelo = modelo;
        retorno = 1;
    }

    return retorno;
}


/** \brief "settea" el color del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto.
 * \param color (int) Color a "settear".
 * \return (int) [0]=Error al cargar // [1]=Cargado con exito.
 *
 */
int auto_setColor( s_Auto* pAuto, int color )
{
    int retorno = 0;

    if( pAuto != NULL && esColorValido(color) )
    {
        pAuto->color = color;
        retorno = 1;
    }

    return retorno;
}




/** \brief "settea" la patente del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto.
 * \param patente (char*) Patente a "settear".
 * \return (int) [0]=Error al cargar // [1]=Cargado con exito.
 *
 */
int auto_setPatente( s_Auto* pAuto, char* patente )
{
    int retorno = 0;

    if( pAuto != NULL && patente != NULL && esPatenteValida(patente) )
    {
        strcpy( pAuto->patente, patente );
        retorno = 1;
    }

    return retorno;
}


/** \brief Carga todos los datos del auto realizando las validaciones correspondientes.
 *
 * \param pAuto (s_Auto*) Puntero del auto.
 * \param marca (char*) Marca a "settear".
 * \param modelo (int) Modelo a "settear".
 * \param color (int) Color a "settear".
 * \param patente (char*) Patente a "settear".
 * \return (int) [0]=Error al cargar // [1]=Cargado con exito.
 *
 */
int auto_cargarAuto( s_Auto* pAuto, char* marca, int modelo, int color, char* patente )
{
    int retorno = 0;

    if( pAuto!=NULL )
    {
        if( auto_setMarca(pAuto,marca) && auto_setModelo(pAuto,modelo) && auto_setColor(pAuto,color) && auto_setPatente(pAuto,patente) )
        {
            retorno = 1;
        }
    }

    return retorno;
}



/** \brief Valida que el color pasado como parámetro sea un color válido.
 *
 * \param color (int) Color a validar.
 * \return [0]=No es un color válido // [1]=Es un color válido.
 *
 */
int esColorValido( int color )
{
    int retorno = 0;

    if( color==ROJO || color==VERDE || color==AZUL || color==GRIS || color==NEGRO || color==BLANCO )
    {
        retorno = 1;
    }

    return retorno;
}



/** \brief Valida que el modelo pasado como parámetro sea un modelo válido.
 *
 * \param modelo (int) Modelo a validar.
 * \return [0]=No es un modelo válido // [1]=Es un modelo válido.
 *
 */
int esModeloValido( int modelo )
{
    int retorno = 0;

    if( modelo>=1970 && modelo<=2015 )
    {
        retorno = 1;
    }

    return retorno;
}



/** \brief Valida que la marca pasada como parámetro sea una marca válida, osea que tenga más de 3 caractéres.
 *
 * \param marca (char*) Marca a validar.
 * \return (int) [0]=No es una marca válida // [1]=Es una marca válida.
 *
 */
int esMarcaValida( char* marca )
{
    int retorno = 0;

    if( marca != NULL && strlen(marca)>3 )
    {
        retorno = 1;
    }

    return retorno;
}



/** \brief Valida que la patente sea una patente válida.
 *
 * \param patente (char*) Patente a validar.
 * \return (int) [0]=No es una patente válida // [1]=Es una patente válida.
 *
 */
int esPatenteValida( char* patente )
{
    int retorno = 0;

    if( patente != NULL && strlen(patente)==7 )
    {
        if( isLetter(patente[0]) && isLetter(patente[1]) && isLetter(patente[2]) && isSpace(patente[3]) && isNumber(patente[4]) && isNumber(patente[5]) && isNumber(patente[6]) )
        {
            retorno = 1;
        }
    }

    return retorno;
}



//Si el caracter es un número devuelve 1, sino 0.
int isNumber( char letra )
{
    int retorno = 0;

    if( letra=='1' || letra=='2' || letra=='3' || letra=='4' || letra=='5' || letra=='6' || letra=='7' || letra=='8' || letra=='9' || letra=='0' )
    {
        retorno = 1;
    }

    return retorno;
}

//Si el caracter es una letra devuelve 1, sino 0.
int isLetter( char letra )
{
    int retorno = 0;

    if( letra=='a' || letra=='A' || letra=='b' || letra=='B' || letra=='c' || letra=='C' || letra=='d' || letra=='D' || letra=='e' || letra=='E' || letra=='f' || letra=='F' || letra=='g' || letra=='G' || letra=='h' || letra=='H' || letra=='i' || letra=='I' || letra=='j' || letra=='J' || letra=='k' || letra=='K' || letra=='l' || letra=='L' || letra=='m' || letra=='M' || letra=='n' || letra=='N' || letra=='o' || letra=='O' || letra=='p' || letra=='P' || letra=='q' || letra=='Q' || letra=='r' || letra=='R' || letra=='s' || letra=='S' || letra=='t' || letra=='T' || letra=='u' || letra=='U' || letra=='v' || letra=='V' || letra=='w' || letra=='W' || letra=='x' || letra=='X' || letra=='y' || letra=='Y' || letra=='z' || letra=='Z' )
    {
        retorno = 1;
    }

    return retorno;
}

//Si el caracter es un espacio devuelve 1, sino 0;
int isSpace( char letra )
{
    int retorno = 0;

    if( letra == ' ' )
    {
        retorno = 1;
    }

    return retorno;
}
