#ifndef __DEF

#define __DEF

#define CLEAR_SCREEN "cls" //cambiar por "reset" para linux
#define SLEEP_TIME 1100
#define ATTEMPTS 3

#define CANT_USUARIOS 10
#define CANT_COMENTARIOS 100

typedef struct
{
    char nickName[15]; //Case sensitive.
    char clave[15]; //Case sensitive.
    char nombreReal[51];
    char correoElectronico[51];
    unsigned int cantidadComentarios;
    int habilitado; //[0]=Deshabilitado / [1]=Habilitado
}usuario;

typedef struct
{
    int idComentario; //Es su index del array.
    char ownerNickName[15];
    char texto[281];
    int contadorMeGusta;
    int creado; //[0]=Vacio / [1]=Ya hay un comentario
}comentario;

#endif // __DEF


int getUsuarioIndexByNickName( usuario *usuarios, int largoUsuarios, char *elNickName );
