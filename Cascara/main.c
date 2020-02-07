#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Functions.h"

int main()
{
    char option[20], seguir = 's';

    while(seguir == 's')
    {
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------               -------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-----------------------------------------------------------------\n");
        printf("--------------------------------- Vera Daniel Federico 1H -------\n");
        printf("-----------------------------------------------------------------\n");
        get_string("Ingrese una opcion: ", option);

        switch(atoi(option))
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
        clear_screen();
    }
    return 0;
}
