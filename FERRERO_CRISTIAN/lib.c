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
                index = getUsuarioIndexByNickName( usuarios, largoUsuarios, auxNickName );
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



/** \brief Permite añadir un nuevo comentario, verificando usuario y contraseña.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array.
 * \param comentarios (*comentario) Array de comentarios.
 * \param largoComentarios (int) Largo del array.
 *
 */
void nuevoComentario( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios )
{
    int error;
    int cantUsuariosHabilitados;
    int indexComentario;
    int indexUsuario;
    char auxNickName[15];
    char auxTextoComentario[281];


    if( usuarios != NULL && comentarios != NULL && largoUsuarios > 0 && largoComentarios >0 )
    {
        system(CLEAR_SCREEN);
        cantUsuariosHabilitados = contarUsuariosHabilitados( usuarios, largoUsuarios );

        //Se verifica que existan usuarios habilitados
        if( cantUsuariosHabilitados > 0 )
        {
            indexComentario = buscarLugarLibreComentarios( comentarios, largoComentarios );
            indexUsuario = solicitarYVerificarUsuarioClave( usuarios, largoUsuarios, ATTEMPTS );

            //Si se verifico el usuario y clave. Y hay lugar libre para el comentario.
            if( indexUsuario >= 0 && indexComentario >= 0 )
            {
                error = getStringConIntentos( auxTextoComentario, 281, "Ingrese el texto del comentario: ", "\nEl comentario debe tener entre 1 y 280 caracteres", 3 );

                if( error == 0 )//Aquí se crea el comentario.
                {
                    strcpy( auxNickName, usuarios[indexUsuario].nickName );
                    crearComentario( comentarios, largoComentarios, indexComentario, auxNickName, auxTextoComentario );
                }
            }
            else if( indexComentario == -1 )
            {
                printf("\nNo hay lugar para más comentarios.\n\n");
                system("pause");
            }
        }
        else if( cantUsuariosHabilitados == 0)
        {
            printf("\nNo hay usuarios cargados en el sistema.\n\n");
            Sleep(SLEEP_TIME);
        }

    }
}



/** \brief Permite añadir un 'me gusta' a un comentario, verificando usuario y contraseña.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array.
 * \param comentarios (*comentario) Array de comentarios.
 * \param largoComentarios (int) Largo del array.
 *
 */
void nuevoMeGusta( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios )
{
    int error;
    int cantidadUsuarios;
    int cantidadComentarios;
    int indexUsuario;
    int idComentario;

    if( usuarios != NULL && largoUsuarios > 0 && comentarios != NULL && largoComentarios > 0 )
    {
        system(CLEAR_SCREEN);

        //Obtengo la cantidad de usuarios habilitados y comentarios creados.
        cantidadUsuarios = contarUsuariosHabilitados( usuarios, largoUsuarios );
        cantidadComentarios = contarComentariosCreados( comentarios, largoComentarios );

        if( cantidadUsuarios > 0 ) //Se verifica que haya usuarios cargados.
        {
            if( cantidadComentarios > 0 ) //Se verifica que hay comentarios cargados.
            {
                indexUsuario = solicitarYVerificarUsuarioClave( usuarios, largoUsuarios, ATTEMPTS );

                if( indexUsuario >= 0 )
                {
                    system(CLEAR_SCREEN); //Se lee el ID del comentario al que se le quiere dar 'me gusta'.
                    error = getInt( &idComentario, "Ingrese el ID del comentario a darle 'me gusta': ", 1, 1, 0, (CANT_COMENTARIOS-1), "Error! Ingrese un id dentro del rango v""\xA0""lido.", ATTEMPTS );

                    if( error == 0)
                    {
                        //Agrego el me gusta al comentario indicado
                        error = agregarMeGusta( comentarios, largoComentarios, idComentario );
                        if( error == 0 )
                        {
                            system(CLEAR_SCREEN);
                            printf("Nuevo 'me gusta' agregado con exito!");
                            Sleep(SLEEP_TIME);
                        }
                    }
                }
            }
            else if( cantidadComentarios == 0 )
            {
                printf("\nNo hay comentarios cargados en el sistema.\n\n");
                Sleep(SLEEP_TIME);
            }
        }
        else if( cantidadUsuarios == 0 )
        {
            printf("\nNo hay usuarios cargados en el sistema.\n\n");
            Sleep(SLEEP_TIME);
        }

    }
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
    int i;
    int indexsUsuariosMasComentarios[largoUsuarios];
    int indexsComentariosMasMeGusta[largoComentarios];
    int auxIndex;
    float promedioMeGusta;
    int error1, error2, error3;

    if( usuarios != NULL && largoUsuarios > 0 && comentarios != NULL && largoComentarios > 0 )
    {
        error1 = buscarUsuariosConMasComentarios( usuarios, largoUsuarios, comentarios, largoComentarios, indexsUsuariosMasComentarios );

//        printf("%d", error1);
//        system("pause");

        //error2 = buscarComentariosConMasMeGusta();

        //error3 = calcularPromediosMeGusta();

        switch( error1 )
        {
            case 0:
                printf("El/los usuario/s con m""\xA0""s comentarios es/son:\n");
                for( i=0 ; i<largoUsuarios ; i++ )
                {

                    if( indexsUsuariosMasComentarios[i] >= 0 && indexsUsuariosMasComentarios[i] >= 0 )
                    {
                        auxIndex = indexsUsuariosMasComentarios[i];
                        printf("%s\n", usuarios[auxIndex].nickName );
                    }
                }
                printf("\n");
                system("pause");
                break;
            case -3:
                printf("\n\nNo hay comentarios.");
                system("pause");
                break;
        }
        if( error1 == 0 )
        {

        }
        else if( error2 == -3 )
        {

        }
    }
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




/** \brief Busca los subíndices de los usuarios con mayor cantidad de comentarios.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array 'usuarios'.
 * \param comentarios (*comentario) Array de comentarios.
 * \param largoComentarios (int) Largo del array 'comentarios'.
 * \param indexs (*int) Array donde se guardan los index de los usuarios con más comentarios. Los '-1' son lugares vacios.
 * \return (int) [0]=Busqueda exitosa / [-1]=Argumentos inválidos / [-2]=No hay usuarios cargados / [-3]= No hay comentarios.
 *
 */
int buscarUsuariosConMasComentarios( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios , int *indexs )
{
    int retorno = -1;
    int i;
    int error;
    int cantUsuariosHabilitados;
    int cantComentariosCreados;
    int cantMaxDeComentarios = 0;

    if( usuarios != NULL && largoUsuarios > 0 && comentarios != NULL && largoComentarios > 0 && indexs != NULL )
    {
        //Obtengo la cantidad de usuarios habilitados.
        cantUsuariosHabilitados = contarUsuariosHabilitados( usuarios, largoUsuarios );
        cantComentariosCreados = contarComentariosCreados( comentarios, largoComentarios );

        if( cantUsuariosHabilitados > 0 && cantComentariosCreados > 0 )
        {

            //Inicializo el array en -1.
            for( i=0 ; i>largoUsuarios ; i ++ )
            {
                indexs[i] = -1;
                printf("%d\n", indexs[i]); /***************** NO INICIALIZA EN -1 VER *******************/
            }

            //Actualizo la cantidad de comentarios.
            error = actualizarCantidadesDeComentarios( usuarios, largoUsuarios, comentarios, largoComentarios );

            if( error == 0 )
            {
                //Hallo la cantidad máxima de comentarios.
                for( i=0 ; i<largoUsuarios ; i++ )
                {
                    if( usuarios[i].habilitado == 1 && usuarios[i].cantidadComentarios > cantMaxDeComentarios )
                    {
                        cantMaxDeComentarios = usuarios[i].cantidadComentarios;
                    }
                }


                if( cantMaxDeComentarios > 0 )
                {
                    //Una vez hallada la cantidad máxima de comentarios
                    //Busco los usuarios con esa cantidad de comentarios y lo guardo en el array de index.
                    int indexsUsados = 0;
                    for( i=0 ; i<largoUsuarios ; i++ )
                    {
                        if( usuarios[i].habilitado ==1 && usuarios[i].cantidadComentarios == cantMaxDeComentarios )
                        {
                            indexs[indexsUsados] = i;
                            indexsUsados++;
                        }
                    }

                    retorno = 0;
                }
                else if( cantMaxDeComentarios == 0 )
                {
                    retorno = -3;
                }

            }
        }
        else if( cantUsuariosHabilitados == 0 )
        {
            retorno = -2;
        }
        else if( cantComentariosCreados == 0 )
        {
            retorno = -3;
        }
    }

    return retorno;
}





