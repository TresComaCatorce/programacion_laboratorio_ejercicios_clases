

void cargarTodosLosDatosDelAuto( s_Auto* pAuto );

void mostrarDatosDelAuto( s_Auto* pAuto );

void modificarMarca( s_Auto* pAuto );

void modificarModelo( s_Auto* pAuto );

void modificarColor( s_Auto* pAuto );

void modificarPantente( s_Auto* pAuto );


//EJERCICIO 1
void persona_ordenarPorEdadMayor( Persona* personas, int len )
{
    int i, j;
    Persona auxPersona;

    for( i=0 ; i<(len-1) ; i++ )
    {
        for( j=i+1 ; j<len ; j++ )
        {
            if( personas[i]->edad < personas[j]->edad )
            {
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;
            }
            else if( personas[i]->edad == personas[j]->edad )
            {
                if( strcmpi(personas[i], personas[j]) > 0 )
                {
                    auxPersona = personas[i];
                    personas[i] = personas[j];
                    personas[j] = auxPersona;
                }
            }
        }
    }
}



//EJERCICIO 2
//a
int buscarX( char* letras );
//b
int buscarX( char* letras )
{
    int retorno = 0;
    int i;
    for( i=0 ; i<strlen(letras) ; i++ )
    {
        if( letras[i] == 'X' )
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}


//EJERCICIO 3
int *ptrInt;
int i;

ptrInt = malloc( sizeof(int)*5 );

if( ptrInt != NULL )
{
    for( i=0 ; i<5 ; i++ )
    {
        *(ptrInt+i) = datoACargar;
    }

    ptrInt = realloc( ptrInt, sizeof(int)*10 );

    if( ptrInt != NULL )
    {
        for( i=5 ; i<10 ; i++ )
        {
            *(ptrInt+i) = datoACargar;
        }

        for( i=0 ; i<10 ; i++ )
        {
            printf("%d \n", *(ptrInt+i));
        }

        for( i=0 ; i<10 ; i++ )
        {
            free(ptrInt+i);
        }
    }
}
