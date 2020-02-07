#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Log.h"
#include "Class.Services.h"

int main()
{
    char option[20], seguir = 's';
    ArrayList* pLogs = al_newArrayList();
    ArrayList* pServices = al_newArrayList();
    int block = 0, menor3 = 0, tres = 0, entre4y7 = 0, mayores7 = 0;

    while(seguir == 's')
    {
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------     Error     -------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                        1- Leer Log                            -\n");
        printf("-                   2- Procesar informacion                     -\n");
        printf("-                  3- Mostrar estadisiticas                     -\n");
        printf("-                          4- Salir                             -\n");
        printf("-                                                               -\n");
        printf("-----------------------------------------------------------------\n");
        printf("------------------------------------------ Vera Daniel 1H -------\n");
        printf("-----------------------------------------------------------------\n");
        get_string("Ingrese una opcion: ", option);

        switch(atoi(option))
        {
        case 1:
            if(bundle_parserLog(pLogs) == 0 && bundle_parserServices(pServices) == 0)
            {
                printf("Logs Lidos.\n");
            }
            else
            {
                printf("Ha ocurrido un error.\n");
            }
            break;
        case 2:
            if(pLogs->isEmpty(pLogs) == 0 && pServices->isEmpty(pServices) == 0)
            {
                if(bundle_prossLog(pLogs, pServices) == 0)
                {
                    block = 1;
                    printf("Datos procesados.\n");
                }
                else
                {
                    printf("Ha ocurrido un error.\n");
                }
            }
            else
            {
                printf("Cargue los Logs.\n");
            }
            break;
        case 3:
            if(block)
            {
                menor3 = bundle_controller(pLogs, pServices, -1, 3);
                tres = bundle_controller(pLogs, pServices, 2, 4);
                entre4y7 = bundle_controller(pLogs, pServices, 3, 8);
                mayores7 = bundle_controller(pLogs, pServices, 7, 10);

                printf("-- Menores a 3: %d\n", menor3);
                printf("-- Iguales a 3: %d\n", tres);
                printf("-- Entre 4 y 7 (inclusive): %d\n", entre4y7);
                printf("-- Mayores a 7: %d\n", mayores7);
            }
            else
            {
                printf("Debe procesar la informacion primero.\n");
            }
            break;
        case 4:
            pLogs->deleteArrayList(pLogs);
            pServices->deleteArrayList(pServices);
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
        clear_screen();
    }
    return 0;
}
