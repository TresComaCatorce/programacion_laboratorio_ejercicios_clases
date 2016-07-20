#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"


/** \brief Getter de usuario por nick name.
 *
 * \param usuarios (*usuario) Array de usuarios.
 * \param largoUsuarios (int) Largo del array.
 * \return (int) Subindice del array donde se encuentra dicho usuario / [-1]=Si no se encuentra el usuario.
 *
 */
int getUsuarioIndexByNickName( usuario *usuarios, int largoUsuarios, char *elNickName )
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




