#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "biblioteca.h"
#include "estructuras.h"
#include "libUsuarios.h"


/** \brief Inicializa el array de usuarios, con todos los usuarios deshabilitados.
 *
 * \param usuarios (*usuario) Array a inicializar.
 * \param largoUsuarios (int) Largo del array.
 * \return [0]=Inicializado correctamente / [-1]=Error al inicializar.
 *
 */
int initUsuarios( usuario *usuarios, int largoUsuarios )
{
    int retorno;
    int i;

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        for( i=0 ; i<largoUsuarios ; i++ )
        {
            usuarios[i].habilitado = 0;
        }
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}



/** \brief Carga datos falsos de usuarios para testing.
 *
 * \param usuarios (*usuario) Array a cargar.
 * \param largoUsuarios (int) Largo del array.
 *
 */
void cargarUsuariosFake( usuario *usuarios, int largoUsuarios )
{
    int i;

    char nickNames[6][15] = { "tilllinde04", "paulland78", "richard22", "oliver92", "christian64", "christoph12" };
    char claves[6][15] = { "hola04", "hola78", "hola22", "hola92", "hola64", "hola12" };
    char nombres[6][51] = { "Till Lindeman", "Paul Landers", "Richard Kruzpe", "Oliver Riedel", "Christian Lorenz", "Christoph Schneider"};
    char correos[6][51] = { "till04@rammstein.com", "paul78@rammstein.com", "richard@rammstein.com", "oliver92@rammstein.com", "christian@rammstein.com", "christop12@rammstein.com" };


    if( usuarios != NULL && largoUsuarios > 0 )
    {
        for( i=0 ; i<6 ; i++ )
        {
            usuarios[i].habilitado = 1;
            strcpy( usuarios[i].nickName, nickNames[i] );
            strcpy( usuarios[i].clave, claves[i] );
            strcpy( usuarios[i].nombreReal, nombres[i] );
            strcpy( usuarios[i].correoElectronico, correos[i] );
        }
    }
}


/** \brief Imprime en pantalla una lista de los usuarios habilitados y todos sus datos.
 *
 * \param usuarios (*usuario) Array a imprimir.
 * \param largoUsuarios (int) Largo del array.
 *
 */

void imprimirListaUsuarios( usuario *usuarios, int largoUsuarios )
{
    system(CLEAR_SCREEN);
    int i;
    int cantidadUsuarios;

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        cantidadUsuarios = contarUsuariosHabilitados( usuarios, largoUsuarios );

        if( cantidadUsuarios > 0 )
        {
            printf("Nick\t\tClave\t\tNombre\t\tCorreo\n");
            for( i=0 ; i<largoUsuarios ; i++)
            {
                if(usuarios[i].habilitado==1)
                {
                    printf("%s\t%s\t%s\t%s\n", usuarios[i].nickName, usuarios[i].clave, usuarios[i].nombreReal, usuarios[i].correoElectronico);
                }
            }
            printf("\n");
            system("pause");
        }

    }
}



/** \brief Cuenta los usuarios habilitados y retorna dicha cantidad.
 *
 * \param usuarios (*usuario) Array de usuarios a contar.
 * \param largoUsuarios (int) Largo del array.
 * \return (int) Cantidad de usuarios habilitados.
 *
 */
int contarUsuariosHabilitados( usuario *usuarios, int largoUsuarios )
{
    int retorno = -1;
    int i;
    int contadorUsuarios = 0;

    //Recorro el array y cuento los usuarios que esta habilitados.
    if( usuarios != NULL && largoUsuarios > 0 )
    {
        for( i=0 ; i<largoUsuarios ; i++ )
        {
            if( usuarios[i].habilitado == 1 )
            {
                contadorUsuarios++;
            }
        }

        retorno = contadorUsuarios;
    }

    return retorno;
}



/** \brief Busca una posición libre en el array de usuarios.
 *
 * \param usuarios (*usuario) Array de usuarios donde se busca la posición libre.
 * \param largoUsuarios (int) Largo del array.
 * \return (int) Subindice del array libre / [-1]=Si no hay lugar disponible
 *
 */
int buscarLugarLibreUsuarios( usuario *usuarios, int largoUsuarios )
{
    int retorno = -1;
    int i;

    if( usuarios != 0 && largoUsuarios > 0 )
    {
        for( i=0 ; i<largoUsuarios ; i++ )
        {
            if( usuarios[i].habilitado == 0 )
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}



/** \brief Verifica la disponibilidad de un nick name, es decir, la existencia de un usuario habilitado con un nick name específico.
 *
 * \param usuarios (*usuario) Array de usuarios donde se va a verificar la existencia del nick name.
 * \param largoUsuarios (int) Largo del array.
 * \param elNickName (*char) Nick name que se debe verificar si ya está cargado en el sistema.
 * \return [0]=Ya existe usuario habilitado y con ese nick name / [1]=No existe usuario con ese nick name.
 *
 */
int verificarDisponibilidadNickName( usuario *usuarios, int largoUsuarios, char *elNickName )
{
    int retorno = 1;
    int i;

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        for( i=0 ; i<largoUsuarios ; i++ )
        {
            if( usuarios[i].habilitado == 1 && ( strcmp(usuarios[i].nickName, elNickName) == 0 ) )
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}



/** \brief Busca un usuario por el nick name indicado.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array.
 * \return Subindice del array donde se encuentra dicho usuario / [-1]=Si no se encuentra el usuario.
 *
 */
int buscaUsuarioPorNickName( usuario *usuarios, int largoUsuarios, char *elNickName )
{
    int retorno = -1;
    int i;

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        for( i=0 ; i<largoUsuarios ; i++ )
        {
            if( strcmp( usuarios[i].nickName, elNickName ) == 0 )
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}



/** \brief Solicita el ingreso de los datos de un nuevo usuario.
 *
 * \param usuarios (*usuario) Array de usuarios donde se va a guardar el nuevo usuario.
 * \param largoUsuarios (int) Largo del array.
 * \param index (int) Indice del array donde se debe cargar el nuevo usuario.
 * \return [0]=Carga exitosa / [-1]=Error al cargar.
 *
 */
int solicitarIngresoNuevoUsuario( usuario *usuarios, int largoUsuarios, int index )
{
    int retorno = -1;
    int error, error2;
    int nickNameDisponible;
    int esSoloLetras;

    usuario auxUsuario;
    auxUsuario.habilitado = 0;


    if( usuarios != NULL && largoUsuarios > 0 && index >= 0 && index < largoUsuarios )
    {
        //solicito el nick name
        system(CLEAR_SCREEN);
        error = getString( auxUsuario.nickName, 15, "Ingrese nick name del nuevo usuario: ", "\nEl nick name debe tener entre 4 y 14 caracteres.", 4 );

        if( error == 0 )
        {
            //Verifico la disponibilidad del nick name.
            nickNameDisponible = verificarDisponibilidadNickName( usuarios, largoUsuarios, auxUsuario.nickName );

            if( nickNameDisponible ) //Si esta disponible y no es un string vacio...
            {
                //Solicito la clave.
                system(CLEAR_SCREEN);
                error = getString( auxUsuario.clave, 15, "Ingrese clave: ", "\nLa clave debe tener entre 4 y 14 caracteres.", 4 );

                if( error == 0 )
                {
                    //Solicito el nombre real
                    system(CLEAR_SCREEN);
                    error = getString( auxUsuario.nombreReal, 51, "Ingrese el nombre real del usuario: ", "\nEl nombre debe tener entre 5 y 50 caracteres.", 5 );
                    error2 = normalizarString( auxUsuario.nombreReal, 51, 3 ); //Normalizo nombre ingresado con primera letra en mayúsculas, las demas en minúsculas.


                    if( error == 0 )
                    {
                        //Solicito el correo electronico
                        system(CLEAR_SCREEN);
                        error = getString( auxUsuario.correoElectronico, 51, "Ingrese correo electronico: ", "\nEl correo electr""\xE0""nico debe tener entre 10 y 50 caracteres.", 10 );

                        if( error == 0 )
                        {
                            auxUsuario.habilitado = 1;
                            usuarios[index] = auxUsuario;
                            retorno = 0;
                        }

                    }
                }

            }
        }
    }

    return retorno;
}
