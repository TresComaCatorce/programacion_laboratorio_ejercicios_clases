#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "parser.h"
#include "lib.h"


int main()
{


    Employee employeeList[1000];
    getEmployeeList(employeeList, 1000,"MOCK.txt"); // Made with https://www.mockaroo.com/

    int i, j;
    Employee auxEmployee;

//    for( i=0 ; i<999 ; i++ )
//    {
//        for( j=i+1 ; j<1000 ; j++)
//        {
//            if( strcmp( employeeList[i].name , employeeList[j].name ) > 0 )
//            {
//                auxEmployee = employeeList[i];
//                employeeList[i] = employeeList[j];
//                employeeList[j] = auxEmployee;
//            }
//        }
//    }

    sortEmployee( employeeList, 1000 );

    clock_t start = clock();

    printEmployeeList(employeeList, 1000);

    clock_t end = clock();

    printf("Elapsed: %0.2f ms\n", 1000 *((double)(end-start) / CLOCKS_PER_SEC));

    return 0;
}
