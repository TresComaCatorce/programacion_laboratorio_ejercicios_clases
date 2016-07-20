
#define ROJO 1
#define VERDE 2
#define AZUL 3
#define GRIS 4
#define NEGRO 5
#define BLANCO 6

typedef struct
{
    char marca[20];
    int modelo;
    int color;
    char patente[8];
}s_Auto;

int auto_setMarca( s_Auto* pAuto, char* marca );

int auto_setModelo( s_Auto* pAuto, int modelo );

int auto_setColor( s_Auto* pAuto, int color );

int auto_setPatente( s_Auto* pAuto, char* patente );

int auto_cargarAuto( s_Auto* pAuto, char* marca, int modelo, int color, char* patente );

int esColorValido( int color );

int esModeloValido( int modelo );

int esMarcaValida( char* marca );

int esPatenteValida( char* patente );

int isNumber( char letra );

int isLetter( char letra );

int isSpace( char letra );
