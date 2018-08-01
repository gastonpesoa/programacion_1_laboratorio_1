
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parserEntregasListFile(FILE* pFile , ArrayList* entregasList, char* fileName);

int imprimirArchivoPorLocalidad(ArrayList* entregasList, char* localidad, FILE *pFile);
int generarArchivoDeReparto(FILE *pFile, char *fileName, ArrayList* entregasList, ArrayList* localidadesList);

#endif // PARSER_H_INCLUDED
