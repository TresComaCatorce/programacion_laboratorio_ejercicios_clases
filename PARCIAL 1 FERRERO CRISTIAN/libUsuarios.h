
/*******  PROTOTIPOS  *******/

int initUsuarios( usuario *usuarios, int largoUsuarios );

void cargarUsuariosFake( usuario *usuarios, int largoUsuarios );

void imprimirListaUsuarios( usuario *usuarios, int largoUsuarios );

int contarUsuariosHabilitados( usuario *usuarios, int largoUsuarios );

int buscarLugarLibreUsuarios( usuario *usuarios, int largoUsuarios );

int verificarDisponibilidadNickName( usuario *usuarios, int largoUsuarios, char *elNickName );

int solicitarIngresoNuevoUsuario( usuario *usuarios, int largoUsuarios, int index );

int solicitarYVerificarUsuarioClave( usuario *usuarios, int largoUsuarios, int intentos );

int actualizarCantidadesDeComentarios( usuario *usuarios, int largoUsuarios, comentario *comentarios, int largoComentarios );

 int setComentariosEnCero( usuario *usuarios, int largoUsuarios );
