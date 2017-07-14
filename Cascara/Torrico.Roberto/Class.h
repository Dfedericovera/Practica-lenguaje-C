#include "ArrayList.h"

//Class for ...
typedef struct
{

}EMolde;

//Metodos for class

/** \brief Genera un espacio en memoria para un dato de tipo AGREGA TIPO DE DATO
 *
 * \param void
 * \return Puntero a AGREGA TIPO DE DATO
 *
 */
EUser* __newUser();

/** \brief Genera un objeto cargado con los datos de un archivo
 *
 * \param Puntero a lista
 * \param Nombre del archivo a cargar
 * \return retorna cero (0) si todo es OK
                   menos uno (-1) si ocurrio un error
 *
 */
int bundle_parser(ArrayList* pList, char file_name[]);

/** \brief Imprime en pantalla el contenido del objeto
 *
 * \param Puntero a lista
 * \return void
 *
 */
void bundle_loop(ArrayList* pList);

/** \brief Genera un nuevo dato dentro del objeto
 *
 * \param
 * \param
 * \return
 *
 */
int bundle_alta(ArrayList* pList /* agregar datos necesarios */);

/** \brief Criterio de ordenamiento
 *
 * \param Puntero a objeto 1
 * \param Puntero a objeto 2
 * \return retorna cero (0) si todo es OK
                   menos uno (-1) si ocurrio un error
 */
int bundle_order(ETramite* pTramite1, ETramite* pTramite2);
