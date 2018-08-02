
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parserProductsListFile(FILE* pFile , ArrayList* productsList, char* fileName);
int productsListToFile(FILE *pFile, ArrayList *productsList, char *fileName);

int imprimirArchivoPorLocalidad(ArrayList* productsList, char* localidad, FILE *pFile);
int generarArchivoDeReparto(FILE *pFile, char *fileName, ArrayList* productsList, ArrayList* localidadesList);

#endif // PARSER_H_INCLUDED
