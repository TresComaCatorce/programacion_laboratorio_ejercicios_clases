#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int contA=0, contE=0, contI=0, contO=0, contU=0 , i=0;

    for( i ; i<20 ; i++ ){
        //Muestro un msj
        printf("Ingrese la letra numero %d : ",(i+1)) ;

        fflush(stdin); //Limpio el buffer del scanf

        //Pido el ingreso de la letra
        scanf("%c", &letra);
        printf("\n");
        switch(letra){

            case 'a':
                contA++;
                break;

            case 'e':
                contE++;
                break;

            case 'i':
                contI++;
                break;

            case 'o':
                contO;
                break;

            case 'u':
                contU++;
                break;

            }
    }

    system("cls");

    printf("La cantidad de letras 'a' es: %d \n", contA);
    printf("La cantidad de letras 'e' es: %d \n", contE);
    printf("La cantidad de letras 'i' es: %d \n", contI);
    printf("La cantidad de letras 'o' es: %d \n", contO);
    printf("La cantidad de letras 'u' es: %d \n", contU);

    return 0;

}
