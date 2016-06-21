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
    int sizeAL;
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

#endif
