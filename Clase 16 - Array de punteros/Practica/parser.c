#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"


int printEmployeeList(Employee employeeList[],int length)
{
    int i;
    int ret = -1;
    if(employeeList != NULL && length >0)
    {
        for(i=0;i<length;i++)
        {
            printf("\n%d %s %s %s %s %s",employeeList[i].id ,employeeList[i].name,employeeList[i].lastName,employeeList[i].email,employeeList[i].gender,employeeList[i].ip);
        }
        ret = 0;
    }

    return ret;
}


char** str_split( char* str, char delim, int* numSplits )
{
    char** ret;
    int retLen;
    char* c;

    if ( ( str == NULL ) || ( delim == '\0' ) )
    {
        /* Either of those will cause problems */
        ret = NULL;
        retLen = -1;
    }
    else
    {
        retLen = 0;
        c = str;

        /* Pre-calculate number of elements */
        do
        {
            if ( *c == delim )
            {
                retLen++;
            }

            c++;
        } while ( *c != '\0' );

        ret = malloc( ( retLen + 1 ) * sizeof( *ret ) );
        ret[retLen] = NULL;

        c = str;
        retLen = 1;
        ret[0] = str;

        do
        {
            if ( *c == delim )
            {
                ret[retLen++] = &c[1];
                *c = '\0';
            }

            c++;
        } while ( *c != '\0' );
    }

    if ( numSplits != NULL )
    {
        *numSplits = retLen;
    }

    return ret;
}

int getEmployeeList(Employee employeeList[],int length,char fileName[])
{
    char** split;
    int num,i;
    char line[256];

    FILE* file = fopen(fileName, "r+"); /* should check the result */


    i=0;
    while (fgets(line, 255, file)) {

        //printf("%s", line);
        num = 6;
        split = str_split( line, ',', &num );
        if ( split == NULL )
        {
            puts( "ERROR IN SPLIT OPERATION" );
        }
        else
        {
            employeeList[i].id = atoi(split[0]);
            strcpy(employeeList[i].name,split[1]);
            strcpy(employeeList[i].lastName,split[2]);
            strcpy(employeeList[i].email,split[3]);
            strcpy(employeeList[i].gender,split[4]);
            strcpy(employeeList[i].ip,split[5]);
            i++;
        }
        if(i >= length)
            break;
        free( split );
    }

    fclose(file);

    return 0;
}



