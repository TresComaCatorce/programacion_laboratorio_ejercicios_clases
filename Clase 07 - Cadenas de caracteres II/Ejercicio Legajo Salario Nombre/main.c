/*
    Se pide el ingreso de los siguientes datos de empleados:
        1. Legajo
        2. Apellido
        3. Nombre
        4. Salario

    Luego ordenar los empleados por orden alfabetico al apellido.
    Y como segundo criterio de ordenamiento, ordenar de mayor a menor por el salario.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2

int main(void){
    int legajos[MAX], legajoAux, i, j;
    float salarios[MAX], salarioAux;
    char nombres[MAX][31];
    char apellidos[MAX][31];
    char auxiliar[31];

    //Pido el ingreso de datos
    for(i=0; i<MAX; i++)
	{
        printf("Ingrese el legajo del empleado: ");
        fflush(stdin);
        scanf("%d", &legajos[i]);


        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(apellidos[i]);

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese el salario del empleado: ");
        fflush(stdin);
        scanf("%f", &salarios[i]);

        system("cls");
    }


    /**--Ordeno los array por nombre (orden alfabetico ascendente)--**/
    for(i=0 ; i<MAX-1 ; i++)
    {
        for(j=i+1 ; j<MAX ; j++)
        {
            //Ordeno por apellidos
            if( strcmpi(apellidos[i] , apellidos[j])>0 )
            {
                strcpy(auxiliar, apellidos[i]);
                strcpy(apellidos[i], apellidos[j]);
                strcpy(apellidos[j], auxiliar);

                strcpy(auxiliar, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxiliar);

                legajoAux=legajos[i];
                legajos[i]=legajos[j];
                legajos[j]=legajoAux;

                salarioAux=salarios[i];
                salarios[i]=salarios[j];
                salarios[j]=salarioAux;
            }

            //Si son iguales los apellidos, ordeno por salario (de mayor a menor)
            if( strcmpi(apellidos[i] , apellidos[j])==0 )
            {
                if( salarios[i]<salarios[j] )
                {
                    strcpy(auxiliar, apellidos[i]);
                    strcpy(apellidos[i], apellidos[j]);
                    strcpy(apellidos[j], auxiliar);

                    strcpy(auxiliar, nombres[i]);
                    strcpy(nombres[i], nombres[j]);
                    strcpy(nombres[j], auxiliar);

                    legajoAux=legajos[i];
                    legajos[i]=legajos[j];
                    legajos[j]=legajoAux;

                    salarioAux=salarios[i];
                    salarios[i]=salarios[j];
                    salarios[j]=salarioAux;
                }
            }

        }
    }
    /***********************--Fin del ordenamiento--**************************/


    /****--Imprimo los datos--****/
    printf("Legajo \tApellido y nombre \tSalario \n");

    for(i=0; i<MAX; i++){
        printf("%d \t%s, %s \t\t%.2f \n", legajos[i], apellidos[i], nombres[i], salarios[i]);
    }

    return 0;
}
