#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#include "estructuras.h"
#include "biblioteca.h"
#include "lib.h"
#include "libUsuarios.h"
#include "libComentarios.h"

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
                printf("\nIngreso exitoso.\n\n");
                Sleep(SLEEP_TIME);
            }
            else
            {
                system(CLEAR_SCREEN);
                printf("\nError al ingresar el nuevo usuario.\n\n");
                Sleep(SLEEP_TIME);
            }

        }
        else
        {
            system(CLEAR_SCREEN);
            printf("\nNo hay lugar libre para ingresar un nuevo usuario.\n\n");
            Sleep(SLEEP_TIME);
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
    int errorLectura;
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
            errorLectura = getString( auxNick, 15, "Ingrese nick name del usuario a eliminar: ", "\nEl nick name debe tener entre 4 y 14 caracteres.", 4);

            if( errorLectura == 0 )
            {
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

                //Imprimo un mensaje dependiendo si se pudo eliminar o no el usuario.
                system(CLEAR_SCREEN);
                if( flag == 1 )
                {
                    printf("\nUsuario eliminado correctamente.\n\n");
                    Sleep(SLEEP_TIME);
                }
                else
                {
                    printf("\nNo existe un usuario con ese nick name.\n\n");
                    Sleep(SLEEP_TIME);
                }
            }
        }
        else //Si no hay usuarios cargados.
        {
            printf("\nNo hay usuarios cargados en el sistema.\n\n");
            Sleep(SLEEP_TIME);
        }
    }
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
    int cantUsuariosHabilitados;
    char auxNickName[15];



    if( usuarios != NULL && largoUsuarios > 0 )
    {
        system(CLEAR_SCREEN);
        cantUsuariosHabilitados = contarUsuariosHabilitados( usuarios, largoUsuarios );

        if( cantUsuariosHabilitados != 0 )//Si hay usuarios cargados
        {
            error = getString( auxNickName, 15, "Ingrese el nickname del usuario a modificar: ", "\nEl nick name debe tener entre 4 y 14 caracteres.", 4 );

            //Busco el usuario ingresado dentro del array. Si existe obtengo su indice, sino -1.
            if( error == 0  )
            {
                index = buscaUsuarioPorNickName( usuarios, largoUsuarios, auxNickName );
            }
            else
            {
                index = -2; //Si el usuario ingresado no cuadra con los limites...
            }

            if( index >= 0 ) //Si existe el usuario con el nick name indicado...
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
                        error = getString( usuarios[index].nombreReal, 51, "Ingrese el nuevo nombre: ", "\n nombre debe tener entre 5 y 50 caracteres.", 5 );
                        break;
                    case 2:
                        system(CLEAR_SCREEN);
                        error = getString( usuarios[index].correoElectronico, 15, "Ingrese el nuevo correo electronico: ", "\nEl correo electr""\xE0""nico debe tener entre 10 y 50 caracteres.", 10 );
                        break;
                    case 3:
                        system(CLEAR_SCREEN);
                        error = getString( usuarios[index].clave, 15, "Ingrese la nueva clave: ", "\nLa clave debe tener entre 4 y 14 caracteres.", 4 );
                        break;
                    case 4:
                        //El usuario eligió volver al menu ppal.
                        break;
                    default:
                        system(CLEAR_SCREEN);
                        printf("\nError! Opci""\xE0""n inv""\xA0""lida.\n\n");
                        Sleep(SLEEP_TIME);
                        break;
                }

                if( error == 0 )
                {
                    system(CLEAR_SCREEN);
                    printf("\nModificacion exitosa.\n\n");
                    Sleep(SLEEP_TIME);
                }
            }
            else if( index == -1 )//Si no existe un usuario con el nick name indicado.
            {
                system(CLEAR_SCREEN);
                printf("\nNo existe un usuario con ese nick name.\n\n");
                Sleep(SLEEP_TIME);
            }
        }
        else //Si no hay usuarios cargados en el sistema.
        {
            printf("\nNo hay usuarios cargados en el sistema.\n\n");
            Sleep(SLEEP_TIME);
        }
    }
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
    /*int error;
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
    }*/
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void nuevoMeGusta( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios )
{

}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void informar( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios )
{

}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void listar( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios )
{

}




