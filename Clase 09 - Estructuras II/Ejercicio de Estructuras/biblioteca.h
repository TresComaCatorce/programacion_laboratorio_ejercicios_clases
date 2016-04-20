typedef struct{
    int legajo;
    char apellido[31];
    char nombre[31];
    float salario;
    short int sector; /*-- 1 Contabilidad - 2 Administracion - 3 Compras - 4 Ventas --*/
    short int estado; /*-- 0 borrado - 1 NO Borrado --*/
}empleado;

//Prototipos de funciones
int buildMenu(char menu[], int opcionMin, int opcionMax, int cantidadPreguntas, char mensajeError[]);
int agregarEmpleado(empleado empleados[], int largo);
//void imprimirListaOrdenadaAlfabeticamente(persona persona);
