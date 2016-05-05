#ifndef __DEF

#define __DEF
typedef struct
{
    char nickName[15]; //Case sensitive
    char clave[15];
    char nombreReal[51];
    char correoElectronico[51];
    int habilitado; //[0]=Deshabilitado / [1]=Habilitado
}usuario;

typedef struct
{
    int idComentario;
    char ownerNickName[15];
    char texto[281];
    int contadorMeGusta;
    int creado; //[0]=Vacio / [1]=Ya hay un comentario
}comentario;

#endif // __DEF
