#include "estructuras.h"

int initUsuarios( usuario *usuarios, int largoUsuarios );

void cargarUsuariosFake( usuario *usuarios, int largoUsuarios );

int contarUsuariosHabilitados( usuario *usuarios, int largoUsuarios );

void bajaUsuario( usuario *usuarios, int largoUsuarios );

int contarUsuariosHabilitados( usuario *usuarios, int largoUsuarios );

void altaUsuario( usuario *usuarios, int largoUsuarios );

int buscarLugarLibreUsuarios( usuario *usuarios, int largoUsuarios );

int solicitarIngresoNuevoUsuario( usuario *usuarios, int largoUsuarios, int index );

int verificarDisponibilidadNickName( usuario *usuarios, int largoUsuarios, char *elNickName );

void modificarUsuario( usuario *usuarios, int largoUsuarios );

int buscaUsuarioPorNickName( usuario *usuarios, int largoUsuarios, char *elNickName );

void nuevoComentario( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios );

int crearComentario( comentario *comentarios, int largoComentarios, char *elNickName, char *elMensaje );

void initComentarios( comentario *comentarios, int largoComentarios );

void imprimirListaUsuarios( usuario *usuarios, int largoUsuarios );
