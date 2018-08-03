
#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
struct{

    int llamadaId;
    char nombreCliente[64];
    char mail[64];
    int dni;
    char producto[64];
    char observaciones[256];

}typedef Llamada;

Llamada* llamada_new(void);

int llamada_setId(Llamada* pLlamada, int llamadaId, int lowLimit);
int llamada_setNombreCliente(Llamada* pLlamada, char* nombreCliente, int lowLimit, int hiLimit);
int llamada_setMail(Llamada* pLlamada, char* mail, int lowLimit, int hiLimit);
int llamada_setDni(Llamada* pLlamada, int dni, int lowLimit);
int llamada_setProducto(Llamada* pLlamada, char* producto, int lowLimit, int hiLimit);
int llamada_setObservaciones(Llamada* pLlamada, char* observaciones, int lowLimit, int hiLimit);

int llamada_getId(Llamada* pLlamada);
char* llamada_getNombreCliente(Llamada* pLlamada);
char* llamada_getMail(Llamada* pLlamada);
int llamada_getDni(Llamada* pLlamada);
char* llamada_getProducto(Llamada* pLlamada);
char* llamada_getObservaciones(Llamada* pLlamada);

void llamada_print(Llamada* pLlamada);
int llamada_printArrayList(ArrayList* llamadasList);

int llamada_compareByDni(void* pLlamadaA,void* pLlamadaB);
int llamada_compareById(void* pLlamadaA,void* pLlamadaB);

void imprimirEstadisticas(ArrayList *llamadasList);

#endif // LLAMADA_H_INCLUDED


