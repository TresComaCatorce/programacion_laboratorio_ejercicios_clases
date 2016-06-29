#include "arrayList.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* retorno = NULL;
    void* pElements;
    pList = (ArrayList*)malloc( sizeof(ArrayList) );

    if(pList != NULL)
    {
        pElements = malloc( sizeof(void *) * AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            retorno = pList;
        }
        else
        {
            free(pList);
        }
    }

    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_add( ArrayList* pList, void* pElemento )
{
    int retorno = -1;

    if( pList != NULL && pElemento != NULL )
    {

        if( pList->size >= pList->reservedSize )
        {
            resizeUp( pList );
        }

        pList->pElements[pList->size] = pElemento;
        pList->size++;

        retorno = 0;

    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int retorno = -1;

    int i;

    if (pList != NULL)
    {
        for(i=pList->size ; i>0 ; i--)
        {
            free(pList->pElements[i]);
        }

        if(pList->size == 0)
        {
            retorno = 0;
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void* al_get(ArrayList* pList , int index)
{
    void* retorno = NULL;

    if( pList !=NULL && (index>=0 && index < pList->size) )
    {
        retorno = pList->pElements[index];
    }

    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_len( ArrayList* pList )
{
    int retorno = -1;

    if(pList != NULL)
    {
        return pList->size;
    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i;

    if(pList != NULL && pElement != NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            if( pList->pElements[i] == pElement )
            {
                return 1;
            }
            else
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_set(ArrayList* pList, int index, void* pElement)
{
    int retorno = -1;

    if(pList !=NULL && pElement != NULL && (index>=0 && index < pList->size))
    {
        pList->pElements[index] = pElement;
        retorno = 0;
    }

    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_remove( ArrayList* pList, int index )
{
    int retorno = -1;

    if(pList !=NULL && (index>=0 && index < pList->size))
    {
        pList->pElements[index]=NULL;
        pList->size-=1;
        contract( pList, index );
        resizeDown(pList);
        retorno = 0;
    }

    return retorno;

}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList* retorno = NULL;
    int i;

    if(pList != NULL)
    {
        retorno = al_newArrayList();

        for( i=0 ; i<pList->size ; i++ )
        {
            retorno->add( retorno , pList->pElements[i] );
        }

        if( !retorno->containsAll( pList, retorno ) )
        {
            retorno = NULL;
        }
    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_clear( ArrayList* pList )
{
    int returnAux = -1;
    int i;

    if(pList !=NULL)
    {
        for(i=0 ; i<pList->size ; i++)
        {
            pList->pElements[i] = NULL;
        }

        pList->size = 0;
        resizeDown( pList );
        returnAux = 0;

    }
    return returnAux;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_push( ArrayList* pList, int index, void* pElement )
{
    int returnAux = -1;

    if( pList != NULL && pElement != NULL && index>=0 && index < pList->size )
    {
        expand( pList, index );
        pList->set( pList, index, pElement );
        returnAux = 0;
    }

    return returnAux;

}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i;

    if(pList != NULL && pElement != NULL)
    {
        for(i=0 ; i<pList->size ; i++)
        {
            if( pList->pElements[i] == pElement )
            {
                return i;
            }
        }
    }

    return returnAux;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_isEmpty( ArrayList* pList )
{
    int retorno = -1;
    int i;

    if( pList != NULL )
    {
        for( i=0 ; i<pList->size ; i++ )
        {
            if( pList->pElements[i] != NULL )
            {
                retorno = 0;
                break;
            }
        }
        if( retorno != 0 )
        {
            retorno = 1;
        }
    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void* al_pop( ArrayList* pList, int index )
{
    void* retorno = NULL;

    if( pList !=NULL && index>=0 && index < pList->size )
    {
        retorno = pList->pElements[index];
        pList->remove( pList, index );
    }

    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ArrayList* al_subList( ArrayList* pList, int from, int to )
{
    ArrayList* retorno = NULL;
    int i;

    if( pList!=NULL && from>=0 && from<pList->size && to>=0 && to<pList->size )
    {
        retorno = al_newArrayList();

        for(i=from ; i<=to ; i++)
        {
            retorno->add( retorno, pList->get(pList, i) );
        }
    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_containsAll( ArrayList* pList, ArrayList* pList2 )
{
    int retorno = -1;
    int contador = 0;
    int i;
    int j;

    if( pList != NULL && pList2 != NULL )
    {
        for( i=0 ; i<pList->size ; i++ )
        {
            for( j=0 ; j<pList2->size ; j++ )
            {
                if( pList->pElements[i] == pList2->pElements[j] )
                {
                    contador++;
                }
            }
        }
        if( contador == pList2->size )
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int al_sort( ArrayList* pList, int (*pFunc)(void* ,void*), int order )
{
    int retorno = -1;
    int i;
    int j;
    void* auxP;

    if( pList != NULL && pFunc != NULL && (order != 0 || order != 1))
    {

        switch(order)
        {
            case 0 :
                for( i=0 ; i<pList->size-1 ; i++ )
                {
                    for( j=i+1 ; j<pList->size ; j++ )
                    {
                        if( pFunc(pList->pElements[i],pList->pElements[j]) < 0)
                        {
                            auxP = pList->pElements[i];
                            pList->pElements[i] = pList->pElements[j];
                            pList->pElements[j] = auxP;
                        }
                    }
                }
                retorno = 0;
            break;

            case 1 :
                for(i=0; i<pList->size-1; i++)
                {
                    for(j=i+1; j<pList->size; j++)
                    {
                        if(pFunc(pList->pElements[i],pList->pElements[j]) > 0)
                        {
                            auxP=pList->pElements[i];
                            pList->pElements[i]=pList->pElements[j];
                            pList->pElements[j]=auxP;
                        }
                    }
                }
                retorno = 0;
            break;
        }
    }
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int resizeUp(ArrayList* pList)
{
    int retorno = -1;
    int auxSize = 0;
    void* auxPelement;
    int auxNewSize = 0;

    if(pList !=NULL)
    {
        auxNewSize = pList->reservedSize + AL_INCREMENT;
        auxSize = auxNewSize * sizeof(void*);
        auxPelement = realloc( pList->pElements, auxSize );
        if(auxPelement != NULL)
        {
            pList->pElements = auxPelement;
            pList->reservedSize = auxNewSize;
            retorno = 0;
        }
    }

    return retorno;

}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int resizeDown( ArrayList* pList )
{
    int retorno = -1;
    int auxSize = 0;
    void* auxPelement;
    int auxNewSize = 0;

    if(pList !=NULL)
    {
        if( (pList->reservedSize - pList->size) > 10 )
        {
            auxNewSize = pList->size + AL_INCREMENT;
            auxSize = auxNewSize * sizeof(void*);
            auxPelement = realloc( pList->pElements, auxSize );
            if(auxPelement != NULL)
            {
                pList->pElements = auxPelement;
                pList->reservedSize = auxNewSize;
                retorno = 0;
            }
        }
    }

    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int contract( ArrayList* pList, int index )
{
    int returnAux = -1;
    int i;

    if( pList !=NULL && (index>=0 && index < pList->size) )
    {
        for(i=index ; i<pList->size-1 ; i++)
        {
            pList->pElements[i] = pList->pElements[i+1];
        }
        returnAux = 0;
    }
   return returnAux;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int expand( ArrayList* pList, int index)
{
    int retorno = -1;
    int i;

    if( pList != NULL && index >= 0 && index < pList->size )
    {

        if( pList->size == pList->reservedSize )
        {
            resizeUp(pList);
        }

        for( i=pList->size ; i>=index ; i-- )
        {
            pList->pElements[i] = pList->pElements[i-1];
        }
        pList->size++;
        retorno = 0;
    }

    return retorno;
}



/** \brief
 *
 * \param pList (ArrayList*) Arraylist que contiene los elementos.
 * \param pFunc (pFunc*) Función que deberá devolver 1 si el elemento pasado como parámetro debe ser incluido en la copia del AL.
 * \return (ArrayList*) Puntero al nuevo AL que contiene los elementos filtrados por la función 'pFunc'.
 *
 */
ArrayList* al_filter( ArrayList* pList, int (*pFunc)(void*) )
{
    ArrayList* retorno = NULL;
    int i;

    if( pList != NULL && pFunc != NULL)
    {
        retorno = al_newArrayList();

        for( i=0 ; i<pList->size ; i++ )
        {
            if( pFunc(pList->pElements[i]) == 1)
            {
                retorno->add( retorno , pList->pElements[i] );
            }
        }
    }

    return retorno;
}
