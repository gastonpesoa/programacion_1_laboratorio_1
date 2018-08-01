
int imprimirArchivoPorLocalidad(ArrayList* entregasList, char* localidad, FILE *pFile);

void getValidLocalidad(ArrayList* entregasList, ArrayList* localidadesList, char *msg, char *localidad);

int generarArchivoDeReparto(FILE *pFile, char *fileName, ArrayList* entregasList, ArrayList* localidadesList);
