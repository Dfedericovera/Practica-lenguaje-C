#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Random.h"

ETarea* __reserved()
{
    ETarea* pTarea = (ETarea*) malloc(sizeof(ETarea));
    return pTarea;
}

int bundle_carga(ArrayList* pList, char archivoName[])
{
    int result = -1;
    char descripcion[500], time[30], priority[20];

    FILE* pFile = NULL;
    pFile = fopen(archivoName, "r");

    if(pFile != NULL)
    {
        ETarea* tarea = NULL;

        while (!feof(pFile))
        {
            tarea = __reserved();
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", descripcion, priority, time);
            strcpy(tarea->_description, descripcion);
            tarea->_time = atoi(time);
            tarea->_priority = atoi(priority);

            result = pList->add(pList, tarea);
        }
        fclose(pFile);
    }
    return result;
}


void bundle_loop(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            ETarea* pTarea = __reserved();
            pTarea = (ETarea*) pList->get(pList, i);

            if(pTarea != NULL)
            {
                if(pTarea->_priority)
                {
                  printf("-- Alta  --- %d --- %s --\n", pTarea->_time, pTarea->_description);
                }
                else
                {
                  printf("-- Baja  --- %d --- %s --\n", pTarea->_time, pTarea->_description);
                }
            }
        }
    }
}

int bundle_particion(ArrayList* primary, ArrayList* pHigh, ArrayList* pLow)
{
    int result = -1, i;

    if((!pHigh->isEmpty(pHigh)) || (!pLow->isEmpty(pLow)))
    {
        pHigh->clear(pHigh);
        pLow->clear(pLow);
    }

    for(i = 0; i < primary->len(primary); i++)
    {
        ETarea* pTarea = __reserved();
        pTarea = (ETarea*) primary->get(primary, i);
        if(pTarea->_priority)
        {
            result = pHigh->add(pHigh, pTarea);
        }
        else
        {
            result = pLow->add(pLow, pTarea);
        }
    }
    primary->clear(primary);
    return result;
}

int bundle_order(ETarea* pTarea1, ETarea* pTarea2)
{
    if(pTarea1->_time > pTarea2->_time)
    {
        return 1;
    }
    if(pTarea1->_time < pTarea2->_time)
    {
        return -1;
    }
    return 0;
}

void bundle_resolve(ArrayList* pList)
{
    int result = -1;

    if(!pList->isEmpty(pList))
    {
        int i;
        char option;
        for(i = 0; i < pList->len(pList); i++)
        {
            ETarea* pTarea = __reserved();
            pTarea = (ETarea*) pList->get(pList, i);

            if(pTarea != NULL)
            {
                printf("-- %d  --- %d --- %s --\n", pTarea->_priority, pTarea->_time, pTarea->_description);
                option = get_char("Ingrese opcion: ");
                if(option == 'y')
                {
                    if(!pList->remove(pList, i))
                    {
                        printf("\nTarea resuelta.\n");
                    }
                    else
                    {
                        printf("\nA ocuurido un error.\n");
                        break;
                    }
                }else if(option == 'c')
                {
                  break;
                }
            }
        }
    }
}



















