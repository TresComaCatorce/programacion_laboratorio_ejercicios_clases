#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "lib.h"

#include "estructuras.h"

#define CANT_USUARIOS 10
#define CANT_COMENTARIOS 100

int main()
{
    int respuesta;

    usuario usuarios[CANT_USUARIOS];
    comentario comentarios[CANT_COMENTARIOS];

    initUsuarios(usuarios, CANT_USUARIOS);
    initComentarios(comentarios, CANT_COMENTARIOS);

    //cargarUsuariosFake(usuarios, CANT_USUARIOS);




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
                                , 1, 9, 3, "Error! Ingrese una opcion valida.");

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
                //nuevoMegusta();
                break;

            case 6:
                //informar();
                break;
            case 7:
                //listar();
                break;
            case 8:
                //SALIR;
                break;
        }

    }while( respuesta != 8 );

    return 0;
}
