#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Services.h"

EServices* __newService()
{
    EServices* newService = (EServices*) malloc(sizeof(EServices));
    return newService;
}

int bundle_parserServices(ArrayList* pList)
{
    int result = -1;

    if(pList != NULL)
    {
        char id[11], name[33], email[65];
        FILE* pFile;
        pFile = fopen("services.txt", "r");
        pList->clear(pList);

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                EServices* service = __newService();
                if(service != NULL)
                {
                    fscanf(pFile,"%[^;];%[^;];%[^\n]\n", id, name, email);
                    service->id = atoi(id);
                    strcpy(service->name, name);
                    strcpy(service->email, email);

                    result = pList->add(pList, service);
                }
                else
                {
                    break;
                }
            }
            fclose(pFile);
        }
    }
    return result;
}

void bundle_loopServices(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            EServices* service = __newService();
            service = (EServices*) pList->get(pList, i);

            if(service != NULL)
            {
                printf("-- %d -- %s -- %s --\n", service->id, service->name, service->email);
            }
        }
    }
}
