#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Log.h"
#include "Class.Services.h"

ELog* __newLog()
{
    ELog* newLog = (ELog*) malloc(sizeof(ELog));
    return newLog;
}

int bundle_parserLog(ArrayList* pList)
{
    int result = -1;

    if(pList != NULL)
    {
        char date[11], time[6], serviceId[100], gravedad[100], msg[65];
        FILE* pFile;
        pFile = fopen("log.txt", "r");
        pList->clear(pList);

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                ELog* log = __newLog();
                if(log != NULL)
                {
                    fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n", date, time, serviceId, gravedad, msg);
                    strcpy(log->date, date);
                    strcpy(log->time, time);
                    log->serviceId = atoi(serviceId);
                    log->gravedad = atoi(gravedad);
                    strcpy(log->msg, msg);

                    result = pList->add(pList, log);
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

void bundle_loopLog(ArrayList* pList)
{
    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            ELog* log = __newLog();
            log = (ELog*) pList->get(pList, i);

            if(log != NULL)
            {
                printf("-- %s -- %s -- %d -- %d -- %s --\n", log->date, log->time, log->serviceId, log->gravedad, log->msg);
            }
        }
    }
}

int bundle_prossLog(ArrayList* pList, ArrayList* pServices)
{
    int result = -1;

    if(pList != NULL)
    {
        int i;
        for(i = 0; i < pList->len(pList); i++)
        {
            ELog* log = __newLog();
            log = (ELog*) pList->get(pList, i);

            if(log != NULL)
            {
                if(log->gravedad <= 3)
                {
                    if(log->gravedad < 3)
                    {
                        result = pList->remove(pList, i);
                    }
                    else if(log->serviceId != 45)
                    {
                        result = bundle_createFile(log,pServices, 1);
                    }
                }
                else if(log->gravedad > 3 && log->gravedad < 8)
                {
                    int j;
                    for(j = 0; j < pServices->len(pServices); j++)
                    {
                        EServices* service = __newService();
                        service = (EServices*) pServices->get(pServices, j);
                        if(log->serviceId == service->id)
                        {
                            printf("-- %s -- %s -- %s -- %s -- %d --\n", log->date, log->time, service->name, log->msg, log->gravedad);
                        }
                    }
                }
                else
                {
                    result = bundle_createFile(log,pServices, 2);
                }
            }
        }
    }
    return result;
}

int bundle_createFile(ELog* log, ArrayList* pList, int type)
{
    int result = 0;
    if(pList != NULL)
    {
        FILE* pFile;
        switch(type)
        {
        case 1:
            pFile = fopen("warnings.txt", "a");
            break;
        case 2:
            pFile = fopen("erros.txt", "a");
            break;
        }

        if(pFile != NULL)
        {
            int i;
            for(i = 0; i < pList->len(pList); i++)
            {
                EServices* service = __newService();
                service = (EServices*) pList->get(pList, i);
                if(service != NULL)
                {
                    if(log->serviceId == service->id)
                    {
                        result = fprintf(pFile,"%s;%s;%s;%s;%s\n",log->date, log->time, service->name, log->msg, service->email);
                    }
                }
            }
            fclose(pFile);
        }
    }
    return result;
}

int bundle_controller(ArrayList* pLogs, ArrayList* pService, int min, int max)
{
    int count = 0;
    if(pLogs != NULL && pService != NULL)
    {
        int i, j;
        for(i = 0; i < pService->len(pService); i++)
        {
            EServices* service = __newService();
            service = (EServices*) pService->get(pService, i);

            for(j = 0; j < pLogs->len(pLogs); j++)
            {
                ELog* log = __newLog();
                log = (ELog*) pLogs->get(pLogs, j);

                if(log->gravedad > min && log->gravedad < max)
                {
                    if(log->serviceId == service->id)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int controller_countSercice(ArrayList* pService, int id)
{
    int i, count = 0;
    for(i = 0; i < pService->len(pService); i++)
    {
        EServices* service = __newService();
        service = (EServices*) pService->get(pService, i);
        if(service->id == id)
        {
            count++;
        }
    }
    return count;
}




