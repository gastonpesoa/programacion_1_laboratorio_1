#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "ArrayList.h"


/** \brief Open a file for reading, analyze it, load structs with the data readed and add the new element to a list
 * \param fileName (char *) Name of the file to be read
 * \param listaEmpleados ArrayList* Pointer to arrayList
 * \return int Return (0) if Error [can't open file or read it, listaEmpleados are NULL pointer]
 *                  - (1) if ok
 */
int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados);


#endif // PARSER_H_INCLUDED
