
#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
struct{

    int productId;
    char descripcion[51];
    char direccion[51];
    char localidad[51];
    char recibe[51];

}typedef Product;

Product* product_new(void);

int product_askId(int lowLimit, int hiLimit);
void product_askDescripcion(char *input);
void product_askMail(char *input);
int product_askAge(int lowLimit, int hiLimit);
void product_askDireccion(char *input);
void product_askLocalidad(char *input);
void product_askRecibe(char *input);
int product_askStock(int lowLimit, int hiLimit);

int product_setId(Product* pProduct, int productId, int lowLimit);
int product_setDescripcion(Product* pProduct, char* descripcion, int lowLimit, int hiLimit);
int product_setMail(Product* pProduct, char* mail, int lowLimit, int hiLimit);
int product_setAge(Product* pProduct, int age, int lowLimit, int hiLimit);
int product_setDireccion(Product* pProduct, char* direccion, int lowLimit, int hiLimit);
int product_setLocalidad(Product* pProduct, char* localidad, int lowLimit, int hiLimit);
int product_setRecibe(Product* pProduct, char* recibe, int lowLimit, int hiLimit);
int product_setStock(Product* pProduct, int stock, int lowLimit);

int product_getId(Product* pProduct);
char* product_getDescripcion(Product* pProduct);
char* product_getDireccion(Product* pProduct);
char* product_getLocalidad(Product* pProduct);
char* product_getRecibe(Product* pProduct);
int product_getStock(Product* pProduct);

void product_print(Product* pProduct);
int product_printArrayList(ArrayList* productsList);
void product_printLocalidad(Product* pProduct);
int product_printLocalidadesList(ArrayList* productsList);

int product_compareByLocalidad(void* pProductA,void* pProductB);
int product_compareByName(void* pProductA,void* pProductB);
int product_compareByMail(void* pProductA,void* pProductB);
int product_compareByAge(void* pProductA,void* pProductB);

Product* getValidProduct(ArrayList* productsList);
void getValidLocalidad(ArrayList* productsList, ArrayList* localidadesList, char *msg, char *localidad);

#endif // PRODUCT_H_INCLUDED


