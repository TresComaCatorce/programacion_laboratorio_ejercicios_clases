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

    //char nickNames[6][15] = { "tilllinde04", "paulland78", "tilllinde05", "oliver92", "christian64", "christoph12" };

    char nickNames[6][15] = { "aaaaa", "aaaab", "aaaac", "aaaad", "aaaae", "aaaaf" };

    char claves[6][15] = { "aaaa", "aaaa", "aaaa", "aaaa", "aaaa", "aaaa" };
    char nombres[6][51] = { "Till", "Till", "Paul", "Paul", "Oliver", "Oliver"};
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

    if( usuarios != NULL && largoUsuarios > 0 )
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


/** \brief Solicita el ingreso de los datos de un nuevo usuario.
 *
 * \param usuarios (*usuario) Array de usuarios donde se va a guardar el nuevo usuario.
 * \param largoUsuarios (int) Largo del array.
 * \param index (int) Indice del array donde se debe cargar el nuevo usuario.
 * \return (int) [0]=Carga exitosa / [-1]=Error al cargar.
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


                    if( error == 0 && error2 == 0)
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



/** \brief
 *
 * \param usuarios (*usuario) Array de usuarios donde se va a guardar el nuevo usuario.
 * \param largoUsuarios (int) Largo del array.
 * \param intentos (int) Cantidad de intentos.
 * \return (int) Subíndice del usuario del que se verificó usuario y contraseña. /[-1]=Argumentos inválidos / [-2]=Usuario incorrecto / [-3]=Clave incorrecta.
 *
 */
int solicitarYVerificarUsuarioClave( usuario *usuarios, int largoUsuarios, int intentos )
{
    int retorno = -1;
    int error;
    int contadorIntentos = 0;
    char auxNickName[15];
    char auxClave[15];
    int indexUsuario;

    if( usuarios != NULL && largoUsuarios > 0 && intentos >= 0 )
    {
        do
        {
            system(CLEAR_SCREEN); //Solicito ingreso de nickname.
            error = getString( auxNickName, 15, "Ingrese nick name: ", "\nEl nick name debe tener entre 4 y 14 caracteres.", 4 );
            if( error == 0 ) //Si el ingreso esta entre los parametros validos.
            {
                //Obtengo el indice del usuario ingresado
                indexUsuario = getUsuarioIndexByNickName( usuarios, largoUsuarios, auxNickName );

                //Si existe el usuario en el array.
                if( indexUsuario >= 0 )
                {
                    system(CLEAR_SCREEN);
                    error = getString( auxClave, 15, "Ingrese la clave: ", "\nLa clave debe tener entre 4 y 14 caracteres.", 4 );

                    if( strcmp( usuarios[indexUsuario].clave, auxClave ) == 0 )
                    {
                        retorno = indexUsuario;
                        break;
                    }
                    else
                    {
                        retorno = -3;
                        system(CLEAR_SCREEN);
                        printf("\nClave incorrecta.\n\n");
                        system("pause");
                    }

                }
                //Si no existe el usuario en el array
                else
                {
                    retorno = -2;
                    system(CLEAR_SCREEN);
                    printf("\nEl usuario no existe.\n\n");
                    system("pause");
                }
            }
            else
            {
                retorno = -2;
            }

            contadorIntentos++;

        }while( contadorIntentos < intentos );
    }

    return retorno;
}


/** \brief Actualiza la cantidad de comentarios de todos los usuarios.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array 'usuarios'.
 * \param comentarios (*comentario) Array de comentarios.
 * \param largoComentarios (int) Largo del array 'comentarios'.
 * \return (int) [0]=Actualización exitosa /[-1]=Argumentos inválidos.
 *
 */
int actualizarCantidadesDeComentarios( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios )
{
    int retorno = -1;
    int i;
    char auxNickName[15]; //Auxiliar utilizado para obtener el autor del comentario.
    int indexUsuarioAutor;
    int error;

    if( usuarios != NULL && largoUsuarios > 0 && comentarios != NULL && largoComentarios > 0 )
    {
        //Se pone en cero la cantidad de comentarios de cada usuario habilitado.
        error = setComentariosEnCero( usuarios, largoUsuarios );

        if( error == 0 )
        {
            for( i=0 ; i<largoComentarios ; i++ )
            {
                if( comentarios[i].creado == 1 )
                {
                    //Obtengo el autor del comentario.
                    strcpy( auxNickName , comentarios[i].ownerNickName );

                    //Obtengo el index del usuario que realizó el comentario.
                    indexUsuarioAutor = getUsuarioIndexByNickName( usuarios, largoUsuarios, auxNickName );

                    if( indexUsuarioAutor >= 0 )
                    {
                        //Aumento en 1 la cantidad de comentarios de ese usuario.
                        usuarios[indexUsuarioAutor].cantidadComentarios++;
                    }
                }
            }

            retorno = 0;
        }
    }

    return retorno;
}




/** \brief Setea el campo 'cantidadComentarios' en 0. Función utilizada para la actualización de la cantidad de comentarios.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array.
 * \return [0]=Exito al setear / [-1]=Argumentos inválidos / [-2]=No hay usuarios cargados en el sistema.
 *
 */
 int setComentariosEnCero( usuario *usuarios, int largoUsuarios )
 {
    int retorno = -1;
    int cantUsuariosHabilitados;
    int i;

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        //Obtengo la cantidad de usuarios habilitados.
        cantUsuariosHabilitados = contarUsuariosHabilitados( usuarios, largoUsuarios );

        //Se checkea que existan usuarios habilitados en el sistema.
        if( cantUsuariosHabilitados > 0 )
        {
            for( i=0 ; i<largoUsuarios ; i++ )
            {
                //Si esta habilitado seteo la cantidad de comentarios en 0.
                if( usuarios[i].habilitado == 1 )
                {
                    usuarios[i].cantidadComentarios = 0;
                }
            }
            retorno = 0;
        }
        else if( cantUsuariosHabilitados == 0 )
        {
            retorno = -2;
        }
    }

    return retorno;
 }
