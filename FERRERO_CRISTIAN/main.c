#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"
#include "lib.h"
#include "libUsuarios.h"
#include "libComentarios.h"

#include "estructuras.h"


int main()
{
    int respuesta;

    usuario usuarios[CANT_USUARIOS];
    comentario comentarios[CANT_COMENTARIOS];

    initUsuarios(usuarios, CANT_USUARIOS);
    initComentarios(comentarios, CANT_COMENTARIOS);

    cargarUsuariosFake(usuarios, CANT_USUARIOS);
    cargarComentariosFake(comentarios, CANT_COMENTARIOS);




    do
    {
        system("cls");
        respuesta = buildMenu(  "1)Alta de usuario\n"
                                "2)Modificar usuario\n"
                                "3)Baja de usuario\n"
                                "4)Nuevo comentario\n"
                                "5)Nuevo me gusta\n"
                                "6)Informar\n"
                                "7)Listar\n"
                                "8)Salir\n"
                                "9)IMPRIMIR LISTADO DE USUARIOS (P/TEST)\n"
                                "10)IMPRIMIR LISTADO DE COMENTARIOS (P/TEST)\n"
                                , 1, 10, 3, "Error! Ingrese una opcion valida.");

        switch( respuesta )
        {
            case 1:
                altaUsuario( usuarios, CANT_USUARIOS );
                break;

            case 2:
                modificarUsuario( usuarios, CANT_USUARIOS );
                break;

            case 3:
                bajaUsuario( usuarios, CANT_USUARIOS);
                break;

            case 4:
                nuevoComentario( usuarios, CANT_USUARIOS, comentarios, CANT_COMENTARIOS );
                break;

            case 5:
                nuevoMeGusta( usuarios, CANT_USUARIOS, comentarios, CANT_COMENTARIOS );
                break;

            case 6:
                informar( usuarios, CANT_USUARIOS, comentarios, CANT_COMENTARIOS );
                break;
            case 7:
                listar( usuarios, CANT_USUARIOS, comentarios, CANT_COMENTARIOS );
                break;
            case 8:
                //SALIR;
                break;
            case 9:
                imprimirListaUsuarios( usuarios, CANT_USUARIOS );
                break;
            case 10:
                imprimirListaComentarios( comentarios, CANT_COMENTARIOS );
                break;
        }

    }while( respuesta != 8 );

    return 0;
}
