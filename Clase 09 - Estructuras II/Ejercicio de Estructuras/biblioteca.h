
//Prototipos de funciones
int buildMenu(void);
int agregarPersona(persona personas[]);
void imprimirListaOrdenadaAlfabeticamente(persona persona);

typedef struct{
    short int edad;
    short int estado=0;
    char dni[9];
    char nombre[31];
}persona;
