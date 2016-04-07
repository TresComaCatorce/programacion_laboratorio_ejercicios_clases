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
