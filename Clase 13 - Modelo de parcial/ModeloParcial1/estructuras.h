

#ifndef __STRUCTS

#define __STRUCTS

typedef struct
{
    int prov_id;
    char prov_nombre[31];
}proveedor;

typedef struct
{
    int prod_id;
    char prod_descripcion[51];
    int prod_cantidad;
    float prod_importe;
    int prod_prov_id;
    short int prod_habilitado;
}producto;

#endif
