#ifndef ARRAY_LIST_INCLUDES

#define ARRAY_LIST_INCLUDES

//Include's
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10

#include "arrayList.h"

typedef struct{
    int size;
    void **pElements;
    int reservedSize;

    int (*add)();
    int (*len)();
    int (*contains)();
    int (*set)();
    int (*remove)();
    int (*clear)();
    int (*push)();
    int (*indexOf)();
    int (*isEmpty)();
    void* (*get)();
    void* (*pop)();
    int (*containsAll)();
    int (*sort)();
    struct arrayList* (*clone)();
    struct arrayList* (*subList)();
    int (*deleteArrayList)();

}ArrayList;

ArrayList* al_newArrayList(void);

int al_add( ArrayList* pList, void* pElemento );

int al_deleteArrayList(ArrayList* pList);

void* al_get(ArrayList* pList , int index);

int al_len( ArrayList* pList );

int al_contains(ArrayList* pList, void* pElement);

int al_set(ArrayList* pList, int index, void* pElement);

int al_remove( ArrayList* pList, int index );

ArrayList* al_clone(ArrayList* pList);

int al_clear( ArrayList* pList );

int al_push( ArrayList* pList, int index, void* pElement );

int al_indexOf(ArrayList* pList, void* pElement);

int al_isEmpty( ArrayList* pList );

void* al_pop( ArrayList* pList, int index );

ArrayList* al_subList( ArrayList* pList, int from, int to );

int al_containsAll( ArrayList* pList, ArrayList* pList2 );

int al_sort( ArrayList* pList, int (*pFunc)(void* ,void*), int order );

int resizeUp(ArrayList* pList);

int resizeDown( ArrayList* pList );

int contract( ArrayList* pList, int index );

int expand( ArrayList* pList, int index);

void* al_pop( ArrayList* pList, int index );

#endif
