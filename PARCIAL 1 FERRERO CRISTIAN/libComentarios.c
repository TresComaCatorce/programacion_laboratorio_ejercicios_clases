#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#include "estructuras.h"
#include "libComentarios.h"



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




/** \brief Imprime en pantalla una lista de los comentarios cargados.
 *
 * \param comentarios (*comentario) Array a imprimir.
 * \param largoComentarios (int) Largo del array.
 *
 */
void imprimirListaComentarios( comentario *comentarios, int largoComentarios )
{
    system(CLEAR_SCREEN);
    int i;
    int cantidadComentarios;

    if( comentarios != NULL && largoComentarios > 0 )
    {
        cantidadComentarios = contarComentariosCreados( comentarios, largoComentarios );

        if( cantidadComentarios > 0 )
        {
            printf("Nick Name\t\tComentario\t\tMe Gusta\n");
            for( i=0 ; i<largoComentarios ; i++)
            {
                if( comentarios[i].creado == 1 )
                {
                    printf("%s\t%s\t%d\n", comentarios[i].ownerNickName, comentarios[i].texto, comentarios[i].contadorMeGusta );
                }
            }
            printf("\n");
            system("pause");
        }
        else if( cantidadComentarios == 0 )
        {
            system(CLEAR_SCREEN);
            printf("\nNo hay comentarios cargados en el sistema.\n\n");
            system("pause");
        }

    }
}




/** \brief Cuenta la cantidad de comentarios cargados en el sistema.
 *
 * \param comentarios (*comentario) Array de comentarios.
 * \param largoComentarios (int) LargoComentarios.
 * \return (int) Cantidad de comentarios cargados. / [-1]=Argumentos inválidos.
 *
 */
int contarComentariosCreados( comentario *comentarios, int largoComentarios )
{
    int retorno = -1;
    int i;
    int contadorComentarios = 0;

    if( comentarios != NULL && largoComentarios > 0 )
    {
        for( i=0 ; i<largoComentarios ; i++ )
        {
            if( comentarios[i].creado == 1 )
            {
                contadorComentarios++;
            }
        }
        retorno = contadorComentarios;
    }

    return retorno;
}




/** \brief Inserta un nuevo comentario perteneciente a un usuario particular.
 *
 * \param
 * \param
 * \return [0]=Comentario creado exitosamente / [-1]=Error al crear el comentario.
 *
 */
int crearComentario( comentario *comentarios, int largoComentarios, int indexToCreate, char *elNickName, char *elMensaje )
{
    int retorno = -1;

    if( comentarios != NULL && largoComentarios > 0 && indexToCreate >= 0 && elNickName != NULL && elMensaje != NULL )
    {
        if( comentarios[indexToCreate].creado == 0 )
        {
            comentarios[indexToCreate].idComentario = indexToCreate;
            comentarios[indexToCreate].creado = 1;
            comentarios[indexToCreate].contadorMeGusta = 0;
            strcpy( comentarios[indexToCreate].ownerNickName, elNickName );
            strcpy( comentarios[indexToCreate].texto, elMensaje );
            retorno = 0;
        }
    }

    return retorno;
}




/** \brief Busca una posición libre en el array de comentarios.
 *
 * \param comentarios (*comentario) Array de comentarios donde se busca la posición libre.
 * \param largoComentarios (int) Largo del array.
 * \return (int) Subindice libre del array / [-1]=Si no hay lugar disponible
 *
 */
int buscarLugarLibreComentarios( comentario *comentarios, int largoComentarios )
{
    int retorno = -1;
    int i;

    if( comentarios != NULL && largoComentarios > 0 )
    {
        for( i=0 ; i<largoComentarios ; i++ )
        {
            if( comentarios[i].creado == 0 )
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}




/** \brief Agrega un nuevo 'me gusta' a un comentario dentro del array de comentarios.
 *
 * \param comentarios (*comentario) Array de usuarios.
 * \param largoComentarios (int) Largo del array.
 * \param indexToAddLike (int) Subíndice del array indicador del comentario al que se le debe agregar un 'me gusta'.
 * \return [0]=Exito al agregar 'me gusta' / [-1]=Argumentos inválidos / [-2]=No existe el comentario.
 *
 */
int agregarMeGusta( comentario *comentarios, int largoComentarios, int indexToAddLike )
{
    int retorno = -1;
    int estaCreado = comentarios[indexToAddLike].creado;
    if( comentarios != NULL && largoComentarios > 0 && indexToAddLike >= 0 )
    {
        //Si existe el comentario.
        if( estaCreado == 1 )
        {
            comentarios[indexToAddLike].contadorMeGusta = comentarios[indexToAddLike].contadorMeGusta + 1;
            retorno = 0;
        }
        else
        {
            retorno = -2;
        }
    }

    return retorno;
}





