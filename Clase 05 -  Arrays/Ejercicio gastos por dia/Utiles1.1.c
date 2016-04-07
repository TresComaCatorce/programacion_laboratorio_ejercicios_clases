
/** \brief Calcula el factorial de un n�mero entero
 *
 * \param numero (int) es el n�mero al que se le v� a calcular el factorial
 * \return el resultado del factorial
 *
 */

int calculaFactorial(int numero)
{
    if(numero==1) //Si el numero es 1, se devuelve el factorial de 1 (1).
    {
        return 1;
    }
    else{ //Sino se calcula el factorial del numero-1 y lo multiplico por el numero (recursividad)
        return ( numero * calculaFactorial(numero-1) );
    }
}

/** \brief Pregunta al usuario si desea continuar.
 *
 * \return int 0(cero) si el usuario eligi� NO continuar 1(uno) si el usuario eligi� continuar
 *
 */

int preguntarDeseaContinuar()
{
    char respuesta; //Respuesta que ingresa el usuario
    int contador = 0;


    do{
        if(contador==0)
        {
            printf("Desea continuar? (s/n)");
        }
        else
        {
            printf("ERROR! Desea continuar? (s/n) ");
        }
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta=tolower(respuesta);
        contador++;
    }while( respuesta!='s' && respuesta!='n');

    switch(respuesta)
    {
        case 's':
            return 1;
            break;
        case 'n':
            return 0;
            break;
    }
    return 0;
}
