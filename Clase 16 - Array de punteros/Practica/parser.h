#ifndef __PARSER
#define __PARSER
struct
{
    int id;
    char name[50];
    char lastName[50];
    char email[50];
    char gender[50];
    char ip[50];

}typedef Employee;
#endif


char** str_split( char* str, char delim, int* numSplits );

int getEmployeeList(Employee employeeList[],int length,char fileName[]);

int printEmployeeList(Employee employeeList[],int length);

