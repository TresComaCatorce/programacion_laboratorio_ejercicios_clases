#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#include "biblioteca.h"
#include "lib.h"

#define CLEAR_SCREEN "cls" //cambiar por "reset" para linux
#define SLEEP_TIME 1100

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



/** \brief Da de baja un usuario ingresando su nick name.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array.
 *
 */
void bajaUsuario( usuario *usuarios, int largoUsuarios )
{
    int i;
    char auxNick[15]; //auxiliar para almacenar el ingreso del usuario.
    int flag = 0;
    int cantUsuariosHabilitados;

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        system(CLEAR_SCREEN);

        //Obtengo la cantidad de usuarios habilitados.
        cantUsuariosHabilitados = contarUsuariosHabilitados( usuarios, largoUsuarios );

        if( cantUsuariosHabilitados != 0 )//Si hay usuarios cargados
        {
            //Obtengo el nickname del usuario a eliminar.
            getString( auxNick, 15, "Ingrese nick name del usuario a eliminar: ", "ERROR! Ingreso inv""\xA0""lido.");


            //Recorro el array y busco un nickname coincidente y habilitado.
            for( i=0 ; i<largoUsuarios ; i++ )
            {
                 if( usuarios[i].habilitado == 1 && ( strcmp(usuarios[i].nickName, auxNick) == 0 ) )
                 {
                     usuarios[i].habilitado = 0;
                     flag = 1;
                     break;
                 }
            }

            system(CLEAR_SCREEN);

            //Imprimo un mensaje dependiendo si se pudo eliminar o no el usuario.
            if( flag == 1 )
            {
                printf("Usuario eliminado correctamente.\n\n");
                system("pause");
            }
            else
            {
                printf("No existe un usuario con ese nick name.\n\n");
                system("pause");
            }
        }
        else
        {
            printf("No hay usuarios cargados en el sistema.\n\n");
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


/** \brief Da de alta un usuario validando que haya lugar y que ya no exista un usuario cargado con ese nick name.
 *
 * \param usuarios (*usuario) Array de usuarios donde se debe dar de alta el nuevo usuario.
 * \param largoUsuarios (int) Largo del array.
 *
 */
void altaUsuario( usuario *usuarios, int largoUsuarios )
{
    int indiceLibre;
    int error;

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        indiceLibre = buscarLugarLibreUsuarios( usuarios, largoUsuarios );
        if( indiceLibre >= 0 )
        {
            error = solicitarIngresoNuevoUsuario( usuarios, largoUsuarios, indiceLibre );

            if( error == 0 )
            {
                system(CLEAR_SCREEN);
                printf("Ingreso exitoso.\n\n");
                system("pause");
            }
            else
            {
                system(CLEAR_SCREEN);
                printf("Error al ingresar el nuevo usuario.\n\n");
                system("pause");
            }

        }
        else
        {
            system(CLEAR_SCREEN);
            printf("No hay lugar para ingresar un nuevo usuario.\n\n");
            system("pause");
        }
    }
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
    int error;
    int nickNameDisponible;

    usuario auxUsuario;
    auxUsuario.habilitado = 0;


    if( usuarios != NULL && largoUsuarios > 0 && index >= 0 && index < largoUsuarios )
    {
        //solicito el nick name
        system(CLEAR_SCREEN);
        error = getString( auxUsuario.nickName, 15, "Ingrese nick name del nuevo usuario: ", "Error el nick name debe tener como m""\xA0""ximo 14 caracteres." );

        if( error == 0 )
        {
            //Verifico la disponibilidad del nick name.
            nickNameDisponible = verificarDisponibilidadNickName( usuarios, largoUsuarios, auxUsuario.nickName );

            if( nickNameDisponible ) //Si esta disponible y no es un string vacio...
            {
                //Solicito la clave.
                system(CLEAR_SCREEN);
                error = getString( auxUsuario.clave, 15, "Ingrese clave: ", "Error, clave debe tener como m""\xA0""ximo 14 caracteres." );

                if( error == 0 )
                {
                    //Solicito el nombre real
                    system(CLEAR_SCREEN);
                    error = getString( auxUsuario.nombreReal, 51, "Ingrese el nombre real del usuario: ", "Error, ingrese un nombre valido." );
                    if( error == 0 )
                    {
                        //Solicito el correo electronico
                        system(CLEAR_SCREEN);
                        error = getString( auxUsuario.correoElectronico, 51, "Ingrese correo electronico: ", "Error ingrese un correo electronico valido." );

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


/** \brief Permite la modificacion de un usuario.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array.
 *
 */
void modificarUsuario( usuario *usuarios, int largoUsuarios )
{
    int respuesta;
    int index;
    int error;
    char auxNickName[15];

    if( usuarios != NULL && largoUsuarios > 0 )
    {
        system(CLEAR_SCREEN);

        error = getString( auxNickName, 15, "Ingrese el nickname del usuario a modificar: ", "Error, el nick name no debe superar los 14 caracteres.");

        if( error == 0  )
        {
            index = buscaUsuarioPorNickName( usuarios, largoUsuarios, auxNickName );
        }
        else
        {
            index = -1;
        }

        if( index >= 0 )
        {
            respuesta = buildMenu("1)Nombre\n"
                                  "2)Correo electr.\n"
                                  "3)Clave\n"
                                  "4)Volver al menu principal\n",
                                  1, 4, 3, "Error! Opcion invalida.");

            switch( respuesta )
            {
                case 1:
                    system(CLEAR_SCREEN);
                    error = getString( usuarios[index].nombreReal, 51, "Ingrese el nuevo nombre: ", "Error, nombre invalido." );
                    break;
                case 2:
                    system(CLEAR_SCREEN);
                    error = getString( usuarios[index].correoElectronico, 15, "Ingrese el nuevo correo electronico: ", "Error, correo electronico invalido." );
                    break;
                case 3:
                    system(CLEAR_SCREEN);
                    error = getString( usuarios[index].clave, 15, "Ingrese la nueva clave: ", "Error, clave invalida." );
                    break;
            }

            if( error == 0 )
            {
                system(CLEAR_SCREEN);
                printf("Modificacion exitosa.\n\n");
                system("pause");
            }
            else
            {
                system(CLEAR_SCREEN);
                printf("Error en la modificacion.\n\n");
                system("pause");
            }

        }
        else
        {
            system(CLEAR_SCREEN);
            printf("No existe un usuario con ese nick name.\n\n");
            system("pause");
        }


    }
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


/** \brief Permite ingresar un nuevo comentario.
 *
 * \param
 * \param
 * \return
 *
 */
void nuevoComentario( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios )
{
    int error;
    int indexUsuario;
    char auxNickName[15];
    char auxClave[15];
    char auxTextoComentario[281];

    if( usuarios != NULL && comentarios != NULL && largoUsuarios > 0 && largoComentarios >0 )
    {
        system(CLEAR_SCREEN);
        error = getString( auxNickName, 15, "Ingrese el usuario:", "El usuario no puede superar los 14 caracteres." );
        if( error == 0 )
        {
            indexUsuario = buscaUsuarioPorNickName( usuarios, largoUsuarios, auxNickName );

            if( indexUsuario >= 0 )
            {
                system(CLEAR_SCREEN);
                error = getString( auxClave, 15, "Ingrese la clave:", "El usuario no puede superar los 14 caracteres." );

                if( strcmp( usuarios[indexUsuario].clave, auxClave ) == 0 )
                {
                    system(CLEAR_SCREEN);
                    error = getString( auxTextoComentario, 281, "Ingrese el texto del comentario: ", "Error el mensaje puede ser, como maximo de 280 caracteres" );

                    if( error == 0 )
                    {
                        crearComentario( comentarios, largoComentarios, auxNickName, auxTextoComentario );
                    }
                }
                else
                {
                    system(CLEAR_SCREEN);
                    printf("Clave incorrecta.\n\n");
                    system("pause");
                }

            }
            else
            {
                system(CLEAR_SCREEN);
                printf("Usuario invalido.\n\n");
                system("pause");
            }
        }
    }
}


/** \brief Inserta un nuevo comentario perteneciente a un usuario particular.
 *
 * \param
 * \param
 * \return [0]=Comentario creado exitosamente / [-1]=Error al crear el comentario.
 *
 */
int crearComentario( comentario *comentarios, int largoComentarios, char *elNickName, char *elMensaje )
{
    int retorno = -1;
    int i;

    for( i=0 ; i<largoComentarios ; i++ )
    {
        if( comentarios[i].creado == 0 )
        {
            comentarios[i].creado = 1;
            comentarios[i].contadorMeGusta = 0;
            strcmp( comentarios[i].ownerNickName, elNickName );
            strcmp( comentarios[i].texto, elMensaje );
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/** \brief Inicializa el array de comentarios.
 *
 * \param comentarios (*comentario) Array de comentarios.
 * \param largoComentarios (int) LargoComentarios.
 *
 */
void initComentarios( comentario *comentarios, int largoComentarios )
{
    int i=0;

    for( i=0 ; i<largoComentarios ; i++ )
    {
        comentarios[i].idComentario = (i+1);
        comentarios[i].creado = 0;
    }
}

void imprimirListaUsuarios( usuario *usuarios, int largoUsuarios )
{
    system(CLEAR_SCREEN);
    int i;
    printf("Nick\t\tClave\t\tNombre\t\tCorreo\n");
    for( i=0;i<largoUsuarios;i++)
    {
        if(usuarios[i].habilitado==1)
        {
            printf("%s\t%s\t%s\t%s\n", usuarios[i].nickName, usuarios[i].clave, usuarios[i].nombreReal, usuarios[i].correoElectronico);
        }
    }
    printf("\n");
    system("pause");
}
