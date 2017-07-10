#include "ArrayList.h"
#include "Functions.h"
//Class
typedef struct{
    char _description[500];
    int _priority;
    int _time;
}ETarea;

// Metodos
ETarea* __reserved();

void bundle_loop(ArrayList* pList);

int bundle_carga(ArrayList* pList, char archivoName[]);

int bundle_particion(ArrayList* primary, ArrayList* pHigh, ArrayList* pLow);

int bundle_order(ETarea* pTarea1, ETarea* pTarea2);

void bundle_resolve(ArrayList* pList);
