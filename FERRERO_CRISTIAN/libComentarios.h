
/*****- PROTOTIPOS -*****/

void initComentarios( comentario *comentarios, int largoComentarios );

void cargarComentariosFake( comentario *comentarios, int largoComentarios );

void imprimirListaComentarios( comentario *comentarios, int largoComentarios );

int contarComentariosCreados( comentario *comentarios, int largoComentarios );

int crearComentario( comentario *comentarios, int largoComentarios, int indexToCreate, char *elNickName, char *elMensaje );

int buscarLugarLibreComentarios( comentario *comentarios, int largoComentarios );

int agregarMeGusta( comentario *comentarios, int largoComentarios, int indexToAddLike );
