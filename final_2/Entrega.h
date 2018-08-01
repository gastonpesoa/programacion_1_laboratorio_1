
#ifndef ENTREGA_H_INCLUDED
#define ENTREGA_H_INCLUDED
struct{

    int entregaId;
    char producto[51];
    char direccion[51];
    char localidad[51];
    char recibe[51];

}typedef Entrega;

Entrega* entrega_new(void);

int entrega_setId(Entrega* pEntrega, int entregaId, int lowLimit);
int entrega_setProduct(Entrega* pEntrega, char* producto, int lowLimit, int hiLimit);
int entrega_setDireccion(Entrega* pEntrega, char* direccion, int lowLimit, int hiLimit);
int entrega_setLocalidad(Entrega* pEntrega, char* localidad, int lowLimit, int hiLimit);
int entrega_setRecibe(Entrega* pEntrega, char* recibe, int lowLimit, int hiLimit);

int entrega_getId(Entrega* pEntrega);
char* entrega_getProduct(Entrega* pEntrega);
char* entrega_getDireccion(Entrega* pEntrega);
char* entrega_getLocalidad(Entrega* pEntrega);
char* entrega_getRecibe(Entrega* pEntrega);

void entrega_print(Entrega* pEntrega);
int entrega_printArrayList(ArrayList* entregasList);
void entrega_printLocalidad(Entrega* pEntrega);
int entrega_printLocalidadesList(ArrayList* entregasList);

int entrega_compareByLocalidad(void* pEntregaA,void* pEntregaB);

void getValidLocalidad(ArrayList* entregasList, ArrayList* localidadesList, char *msg, char *localidad);

#endif // ENTREGA_H_INCLUDED


