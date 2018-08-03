
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parserLlamadasListFile(FILE* pFile , ArrayList* llamadasList, char* fileName);
int llamadasListToFile(FILE *pFile, ArrayList *llamadasList, char *fileName);

#endif // PARSER_H_INCLUDED
