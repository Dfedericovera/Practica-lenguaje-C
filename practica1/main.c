#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Random.h"

int main()
{
    char seguir = 's', option[30], archivo[50];
    ArrayList* pList = al_newArrayList();
    ArrayList* pHigh = al_newArrayList();
    ArrayList* pLow = al_newArrayList();

    while (seguir == 's')
    {
        printf("-----------------------------------------------------------------\n");
        printf("------------------------- System Persons ------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                 1 - Cargar lista de tareas                    -\n");
        printf("-                2 - Particionar por prioridad                  -\n");
        printf("-                        3 - Ordenar                            -\n");
        printf("-                    4 - Resolver tareas                        -\n");
        printf("-                           5- Salir                            -\n");
        printf("-                                                               -\n");
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------------------- Torrico Roberto 1H -------\n");
        printf("-----------------------------------------------------------------\n");
        get_string("Ingrese una opcion: ", option);
        switch (atoi(option))
        {
        case 1:
            get_string("Ingrese el nombre del archivo: ", archivo);
            if(bundle_carga(pList, archivo) == 0)
            {
                printf("Lista cargada con exito.\n");
            }
            else
            {
                printf("A ocurrido un error.\n");
            }
            break;
        case 2:
            if(!pList->isEmpty(pList))
            {
                if(bundle_particion(pList, pHigh, pLow) == 0)
                {
                    printf("Particion creada con exito.\n");
                }
                else
                {
                    printf("A ocurrido un error.\n");
                }
            }
            else
            {
                printf("Por favor cargue las tareas.\n");
            }
            break;
        case 3:
            if((!pHigh->isEmpty(pHigh)) || (!pLow->isEmpty(pLow)))
            {
                ArrayList* pHigh_clone = pHigh->clone(pHigh);
                ArrayList* pLow_clone = pLow->clone(pLow);

                if(!(pLow_clone->sort(pLow_clone,bundle_order,0)) && !(pHigh_clone->sort(pHigh_clone,bundle_order,0)) )
                {
                    printf("Listas ordenadas.\n");
                    if(get_char("Desea ver las listas ordenadas? s/n") == 's')
                    {
                        printf("\nLista prioridad Alta: \n");
                        bundle_loop(pHigh_clone);
                        system("pause");
                        printf("\nLista prioridad Baja: \n");
                        bundle_loop(pLow_clone);
                    }
                    printf("\n");
                }
                else
                {
                    printf("A ocurrido un error\n");
                }
            }
            else
            {
                printf("Por favor particione por prioridad.\n");
            }
            break;
        case 4:
            if((!pHigh->isEmpty(pHigh)) || (!pLow->isEmpty(pLow)))
            {
                if(!(pLow->sort(pLow,bundle_order,1)) && !(pHigh->sort(pHigh,bundle_order,1)) )
                {
                    printf("------------------------ Resolver tareas ------------------------\n");
                    printf("- Resolver = 'y' ------------------------------- Cancelar = 'c' -\n");
                    printf("------ Para pasar a la sig tarea precione cualquier tlecla ------\n");
                    get_string("--------------- Lista prioridad alta(1) o baja(2)? --------------\n",option);
                    switch(atoi(option))
                    {
                    case 1:
                        bundle_resolve(pHigh);
                        break;
                    case 2:
                        bundle_resolve(pLow);
                        break;
                    default:
                        printf("Opcion incorrecta.\n");
                        break;
                    }
                }
                else
                {
                    printf("A ocurrido un error.\n");
                }
            }
            else
            {
                printf("Por favor particione por prioridad.\n");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        case 6:
            bundle_loop(pHigh);
            system("pause");
            bundle_loop(pLow);
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }
        clear_screen();
    }

    return 0;
}
