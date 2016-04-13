int buildMenu(void)
{
    int respuesta;
    printf("1) Agregar una persona.\n");
    printf("2) Borrar una persona.\n");
    printf("3) Imprimir lista ordenada por nombre.\n");
    printf("4) Imprimir gr""\xA0""fico de edades.\n");
    printf("5) Salir\n\n");
    printf("Ingrese la opci""\xA2""n deseada: ");
    fflush(stdin);
    scanf("%d", &respuesta);
    return respuesta;
}

/** \brief Agrega, por referencia, una persona al array pasado, verifica que el estado sea cero para cargar la persona.
 *
 * \param persona
 * \return int 1 si agregó el array correctamente, 0 si no hay lugar para cargar
 *
 */

int agregarPersona(persona personas[])
{
    int i=0, escribio=0;
    for(i=0;i<CANTIDAD;i++)
    {
        if(personas[i].estado==0)
        {
            system("cls");
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(personas[i].nombre);
            printf("\nIngrese la edad: ");
            fflush(stdin);
            scanf("%d", &personas[i].edad);
            printf("\nIngrese el DNI: ");
            fflush(stdin);
            gets(personas[i].dni)
            personas[i].estado=1;
            escribio=1;
            break;
        }
    }
    if(escribio==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

void imprimirListaOrdenadaAlfabeticamente(persona persona)
{
    //Recibe: el vector
    //Devuelve: NADA
}
