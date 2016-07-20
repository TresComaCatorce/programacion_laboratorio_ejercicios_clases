#include "includes.h"


/** \brief Funcion del menu que carga los datos del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto a cargar.
 *
 */
void cargarTodosLosDatosDelAuto( s_Auto* pAuto )
{
    int error = 0;
    char auxMarca[20];
    int auxModelo;
    int auxColor;
    char auxPatente[8];

    //Obtengo la marca
    system(CLEAR_SCREEN);
    error = getString( auxMarca, 20, "Ingrese la marca: ", "Marca invalida.");
    if( error == 0 )
    {
        //Obtengo el modelo
        system(CLEAR_SCREEN);
        error = getInt( &auxModelo, "Ingrese el modelo: ", 1, 1, 1970, 2015, "Modelo invalido", 3);
        if( error == 0 )
        {
            //Obtengo el color
            system(CLEAR_SCREEN);
            error = getInt( &auxColor, "Ingrese el color: (ROJO=1//VERDE=2//AZUL=3//GRIS=4//NEGRO=5//BLANCO=6)", 1, 1, 1, 6, "Color invalido.", 3);
            if( error == 0 )
            {
                //Obtengo la patente
                system(CLEAR_SCREEN);
                error = getString( auxPatente, 8, "Ingrese la patente: ", "Patente invalida" );
                if( error == 0 )
                {
                    error = auto_cargarAuto( pAuto, auxMarca, auxModelo, auxColor, auxPatente );
                    if( error == 1 )
                    {
                        system(CLEAR_SCREEN);
                        printf("Datos del auto cargados exitosamente...");
                        Sleep(SLEEP_TIME);
                    }
                    else
                    {
                        system(CLEAR_SCREEN);
                        printf("Ocurrio un error al cargar los datos del auto. Verifique los datos ingresados.");
                        Sleep(SLEEP_TIME);
                    }
                }
            }
        }
    }
}



/** \brief Funcion del menu que muestra los datos del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto a mostrar.
 *
 */
void mostrarDatosDelAuto( s_Auto* pAuto )
{
    system(CLEAR_SCREEN);
    printf("DATOS DEL AUTO\n");
    printf("Marca: %s\n", pAuto->marca);
    printf("Modelo: %d\n", pAuto->modelo);
    printf("Color: %d\n", pAuto->color);
    printf("Patente: %s\n\n", pAuto->patente);
    system("pause");
}



/** \brief Funcion del menu que modifica la marca del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto a modificar.
 *
 */
void modificarMarca( s_Auto* pAuto )
{
    char auxMarca[20];
    int error;

    if( pAuto != NULL )
    {
        error = getStringConIntentos( auxMarca, 20, "Ingrese la nueva marca: ", "Marca invalida.", 3 );

        if( error == 0 )
        {
            error = auto_setMarca( pAuto, auxMarca );

            if( error == 1 )
            {
                system(CLEAR_SCREEN);
                printf("Marca del auto modificada con exito...");
                Sleep(SLEEP_TIME);
            }
            else
            {
                system(CLEAR_SCREEN);
                printf("Ocurrio un error al modificar la marca del auto. Verifique el dato ingresado.");
                Sleep(SLEEP_TIME);
            }
        }
    }
}



/** \brief Funcion del menu que modifica el modelo del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto a modificar.
 *
 */
void modificarModelo( s_Auto* pAuto )
{
    int auxModelo;
    int error;

    if( pAuto != NULL )
    {
        error = getInt( &auxModelo, "Ingrese el modelo: ", 1, 1, 1970, 2015, "Modelo invalido", 3 );

        if( error == 0 )
        {
            error = auto_setModelo( pAuto, auxModelo );

            if( error == 1 )
            {
                system(CLEAR_SCREEN);
                printf("Modelo del auto modificado con exito...");
                Sleep(SLEEP_TIME);
            }
            else
            {
                system(CLEAR_SCREEN);
                printf("Ocurrio un error al modificar el modelo del auto. Verifique el dato ingresado.");
                Sleep(SLEEP_TIME);
            }
        }
    }
}




/** \brief Funcion del menu que modifica el color del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto a modificar.
 *
 */
void modificarColor( s_Auto* pAuto )
{
    int auxColor;
    int error;

    if( pAuto != NULL )
    {
        error = getInt( &auxColor, "Ingrese el color: ", 1, 1, 1, 6, "Color invalido", 3 );

        if( error == 0 )
        {
            error = auto_setColor( pAuto, auxColor );

            if( error == 1 )
            {
                system(CLEAR_SCREEN);
                printf("Color del auto modificado con exito...");
                Sleep(SLEEP_TIME);
            }
            else
            {
                system(CLEAR_SCREEN);
                printf("Ocurrio un error al modificar el color del auto. Verifique el dato ingresado.");
                Sleep(SLEEP_TIME);
            }
        }
    }
}




/** \brief Funcion del menu que modifica la patente del auto.
 *
 * \param pAuto (s_Auto*) Puntero del auto a modificar.
 *
 */
void modificarPantente( s_Auto* pAuto )
{
    char auxPatente[8];
    int error;

    if( pAuto != NULL )
    {
        error = getStringConIntentos( auxPatente, 8, "Ingrese la patente: ", "Patente invalida.", 3 );

        if( error == 0 )
        {
            error = auto_setPatente( pAuto, auxPatente );

            if( error == 1 )
            {
                system(CLEAR_SCREEN);
                printf("Patente del auto modificada con exito...");
                Sleep(SLEEP_TIME);
            }
            else
            {
                system(CLEAR_SCREEN);
                printf("Ocurrio un error al modificar la patente del auto. Verifique el dato ingresado.");
                Sleep(SLEEP_TIME);
            }
        }
    }
}
