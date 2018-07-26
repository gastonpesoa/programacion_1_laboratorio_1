#include "Service.h"

int procesarInformacion(FILE* pWarningsFile, FILE* pErrorsFile, ArrayList* logsEntryList, ArrayList* servicesList, char* warningsFileName, char* errorsFileName);

void mostrarEstadisticas(ArrayList* logsEntryList, ArrayList* servicesList);

//Service* getServiceById(ArrayList* servicesList, int serviceId);