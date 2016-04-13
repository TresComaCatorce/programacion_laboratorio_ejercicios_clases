#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

typedef struct empleado
    {
        char nombre[31];
        char apellido[31];
        int legajo;
        int ocupado;
     };

int menu(void);
void imprimirEmpleados(struct empleado empleados[]);
//struct empleado empleados[] borrarEmpleados(struct empleado empleados [], int legajo);


int main()
{
    int opcion;
    struct empleado empleados [CANTIDAD];

    do
    {
        system("CLS");
        opcion = menu();

        switch(opcion){
        case 1:
            imprimirEmpleados(empleados);
            break;
        case 2:
            agregarEmpleados();
            break;
//        case 3:
//            borrarEmpleados();
//            break;
//        case 4:
//            ordenarEmpleados();
//            break;
        }

    }while(opcion != 5);

    return 0;
}

int menu(void)
{
    int respuesta;

    printf("1. Imprimir/Listar\n");
    printf("2. Agregar/Editar\n");
    printf("3. Borrar\n");
    printf("4. Ordenar\n");
    printf("5. Salir\n\n");

    printf("Ingrese la opcion deseada: ");

    fflush(stdin);

    scanf("%d", &respuesta);

    while(respuesta < 1 || respuesta > 5){

    system("CLS");

    printf("1. Imprimir/Listar\n");
    printf("2. Agregar/Editar\n");
    printf("3. Borrar\n");
    printf("4. Ordenar\n");
    printf("5. Salir\n\n");

    printf("ERROR! Ingrese la opcion deseada: ");

    }
}

void imprimirEmpleados(struct empleado empleados[]){
    int i;
    printf("Legajos: \t Apellidos: \t Nombres: \t\n");
    for(i = 0; i < CANTIDAD; i++){
        printf("%d \t %s \t %s \n", empleados[i].legajo, empleados[i].apellido, empleados[i].nombre);
    }
    system("pause");
}

void agregarEmpleados(struct empleado empleados[]){
    int i;
    for(i = 0; i < CANTIDAD; i++){
        printf("Ingresar legajo: ");
        fflush(stdin);
        scanf("%d", &empleados[i].legajo);

        printf("Ingresar apellido: ");
        fflush(stdin);
        gets(empleados[i].apellido);

        printf("Ingresar nombre: ");
        fflush(stdin);
        gets(empleados[i].nombre);
    }
}
