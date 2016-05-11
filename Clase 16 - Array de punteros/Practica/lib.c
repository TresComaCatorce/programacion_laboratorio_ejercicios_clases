#include <stdlib.h>
#include <string.h>
#include "parser.h"

void sortEmployee( Employee *Employees, int lengthEmployees )
{
    int i, j;
    Employee auxEmployee;
    if( Employees != NULL && lengthEmployees > 0 )
    {
        for( i=0; i<(lengthEmployees-1) ; i++ )
        {
            for( j=(i+1) ; j<lengthEmployees ; j++ )
            {
                if( strcmp( (*(Employees+i)).name , (*(Employees+j)).name ) > 0 )
                {
                    auxEmployee = *(Employees+i);
                    *(Employees+i) = *(Employees+j);
                    *(Employees+j) = auxEmployee;
                }
            }
        }
    }
}
