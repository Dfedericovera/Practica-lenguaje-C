#include "ArrayList.h"

//Class for ...
typedef struct
{
    int id;
    char name[33];
    char email[65];
}EServices;

//Metodos for class

/** \brief Genera un espacio en memoria para un dato de tipo Services
 *
 * \param void
 * \return Puntero a Services
 *
 */
EServices* __newService();

/** \brief Genera un objeto cargado con los datos de un archivo
 *
 * \param Puntero a lista
 * \param Nombre del archivo a cargar
 * \return retorna cero (0) si todo es OK
                   menos uno (-1) si ocurrio un error
 *
 */
int bundle_parserServices(ArrayList* pList);

/** \brief Imprime en pantalla el contenido del objeto
 *
 * \param Puntero a lista
 * \return void
 *
 */
void bundle_loopServices(ArrayList* pList);


