#include "../Bibliotecas/Utiles/Utiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NUMB_ATTEMPTS 3

/** \brief Principal function of the program. Execute the menu and handle every case.
 *
 * \return [0]=User choose "Salir" [1]=Exceeds the number of attempts.
 *
 */

short int runPersonas(void)
{
    int answer;//Answer obtained from the user.

    do{
        answer = 5;

        //Menu construction
        answer = buildMenu(  "1) Agregar una persona\n"
                                "2) Borrar una persona\n"
                                "3) Imprimir lista ordenada por nombre\n"
                                "4) Imprimir gr""\xA0""fico de edades\n"
                                "5) Salir", 1, 5, NUMB_ATTEMPTS, "Error! Ingrese una opci""\xE0""n correcta.");
        switch(answer)
        {
            case 1:
                //addPerson();
                printf("Add Person option!");
                system("pause");
                break;
            case 2:
                printf("Delete Person option!");
                system("pause");
                //deletePerson();
                break;
            case 3:
                printf("Print List option!");
                system("pause");
                //printListSortedByName();
                break;
            case 4:
                printf("Print Graph option!");
                system("pause");
                //printAgesGraph();
                break;
            case 5:
                printf("Exit option!");
                system("pause");
                answer = 5;
                break
            case -1:
                printf("Attempt exceed!");
                system("pause");
                return 1;
                break;
            default:

                /*VER Q SE HACE ACA*/

                break;
        }
    }while( answer != 5 );

    return 0;
}
