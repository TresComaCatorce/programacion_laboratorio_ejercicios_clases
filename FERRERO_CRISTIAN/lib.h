#include "estructuras.h"



/*****- PROTOTIPOS -*****/

void altaUsuario( usuario *usuarios, int largoUsuarios );

void bajaUsuario( usuario *usuarios, int largoUsuarios );

void modificarUsuario( usuario *usuarios, int largoUsuarios );

void nuevoComentario( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios );

void nuevoMeGusta( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios );

void informar( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios );

void listar( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios );

int buscarUsuariosConMasComentarios( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios , int *indexs );
