#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#include "estructuras.h"



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
