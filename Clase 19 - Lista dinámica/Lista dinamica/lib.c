#include "lib.h"


void run(void)
{
    ArrayList* al_Players = al_newArrayList();
    int opcion;
    do
    {
        opcion = buildMenu( "1)Agregar personaje\n"
                            "2)Eliminar personaje\n"
                            , 1, 5, 3, "Opcion incorrecta.\n");

        switch(opcion)
        {
            case 1:
                add_player(al_Players);
                break;
            case 2:
                break;
            case 3:
                break;
        }


    }while(opcion!=5);
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void add_player(ArrayList* players)
{

}
