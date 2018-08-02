#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Product.h"

#define LOW_LIMIT 1
#define HI_LIMIT 999999999


/** \brief Allocate a new product.
 * \param void
 * \return Product* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new product) if ok
 */
Product* product_new(void){

    Product* returnAux = NULL;
    returnAux = (Product*)malloc(sizeof(Product));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


/** \brief Request a Id to the product, validate that it is only integer numbers and between the assigned range
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return (int) Id of the product
 */
int product_askId(int lowLimit, int hiLimit){

    int ageAux;
    ageAux = getValidInt("\nIngrese el Id: ", "\nEl Id debe ser numerico", lowLimit, hiLimit);
    return ageAux;
}


/** \brief Request a name to the product, validate that it is only letters and capitalize it
 * \param input (char*) Pointer to the string of characters where the entered name will be stored
 * \return void
 */
void product_askDescripcion(char *input){

    getValidString("\nIngrese la descripcion del producto: ", "\nLa descripcion debe ser solo letras", input);
    capitalize(input);
}


/** \brief Request a mail to the product
 * \param input (char*) Pointer to the string of characters where the entered mail will be stored
 * \return void
 */
void product_askMail(char *input){

    getValidStringMail("\nIngrese el mail del objeto: ","\nEl mail debe contener un '@' y por lo menos un punto", input);
}


/** \brief Request a age to the product, validate that it is only integer numbers and between the assigned range
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return (int) Age of the product
 */
int product_askAge(int lowLimit, int hiLimit){

    int ageAux;

    ageAux = getValidInt("Ingrese la edad: ", "La edad debe ser numerica", lowLimit, hiLimit);
    return ageAux;
}


/** \brief Request a direccion to the product, validate that it is only letters and numbers and capitalize it
 * \param input (char*) Pointer to the string of characters where the entered direccion will be stored
 * \return void
 */
void product_askDireccion(char *input){

    getValidStringAlfanumerico("\nIngrese la direccion: ", "\nLa direccion debe ser solo letras y numeros", input);
    capitalize(input);
}


/** \brief Request a localidad to the product, validate that it is only letters and numbers and capitalize it
 * \param input (char*) Pointer to the string of characters where the entered direccion will be stored
 * \return void
 */
void product_askLocalidad(char *input){

    getValidStringAlfanumerico("\nIngrese la localidad: ", "\nLa localidad debe ser solo letras y numeros", input);
    capitalize(input);
}


/** \brief Request a recibe to the product, validate that it is only letters and capitalize it
 * \param input (char*) Pointer to the string of characters where the entered name will be stored
 * \return void
 */
void product_askRecibe(char *input){

    getValidString("\nIngrese quien recibe el producto: ", "\nQuien recibe el producto debe ser solo letras", input);
    capitalize(input);
}


/** \brief Request a stock to the product, validate that it is only integer numbers and between the assigned range
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return (int) Stock of the product
 */
int product_askStock(int lowLimit, int hiLimit){

    int ageAux;
    ageAux = getValidInt("\nIngrese el stock: ", "\nEl stock debe ser numerico", lowLimit, hiLimit);
    return ageAux;
}


/** \brief Set pProduct Product the id recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param productId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setId(Product* pProduct, int productId, int lowLimit){

    int returnAux = -1;

    if(productId >= lowLimit){

        pProduct->productId = productId;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pProduct Product the descripcion recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param descripcion (char*) Pointer to the producto recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setDescripcion(Product* pProduct, char* descripcion, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(descripcion, lowLimit, hiLimit)) {

        strcpy(pProduct->descripcion,descripcion);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pProduct Product the mail recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param mail (char*) Pointer to the mail recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid mail]
 *                  - ( 0) if Ok
 */
int product_setMail(Product* pProduct, char* mail, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(mail, lowLimit, hiLimit)) {

        strcpy(pProduct->mail,mail);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Set pProduct Product the age recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param age (int) Age recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setAge(Product* pProduct, int age, int lowLimit, int hiLimit){

    int returnAux = -1;

    if(age >= lowLimit && age <= hiLimit){

        pProduct->age = age;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Set pProduct Product the direccion recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param direccion (char*) Pointer to the direccion recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setDireccion(Product* pProduct, char* direccion, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(direccion, lowLimit, hiLimit)) {

        strcpy(pProduct->direccion,direccion);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pProduct Product the localidad recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param localidad (char*) Pointer to the localidad recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setLocalidad(Product* pProduct, char* localidad, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(localidad, lowLimit, hiLimit)) {

        strcpy(pProduct->localidad,localidad);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pProduct Product the recibe recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param recibe (char*) Pointer to the recibe recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setRecibe(Product* pProduct, char* recibe, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(recibe, lowLimit, hiLimit)) {

        strcpy(pProduct->recibe,recibe);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pProduct Product the stock recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param stock (int) Pointer to the stock recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setStock(Product* pProduct, int stock, int lowLimit){

    int returnAux = -1;

    if(stock >= lowLimit){

        pProduct->stock = stock;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief  Get the id of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Id of the product
 */
int product_getId(Product* pProduct){

    return pProduct->productId;
}


/** \brief  Get the descrpcion of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Product of the product
 */
char* product_getDescripcion(Product* pProduct){

    return pProduct->descripcion;
}


/** \brief  Get the mail of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (char*) Mail of the product
 */
char* product_getMail(Product* pProduct){

    return pProduct->mail;
}


/** \brief  Get the direccion of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Product of the product
 */
char* product_getDireccion(Product* pProduct){

    return pProduct->direccion;
}


/** \brief  Get the localidad of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Product of the product
 */
char* product_getLocalidad(Product* pProduct){

    return pProduct->localidad;
}


/** \brief  Get the recibe of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Product of the product
 */
char* product_getRecibe(Product* pProduct){

    return pProduct->recibe;
}


/** \brief  Get the stock of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Stock of the product
 */
int product_getStock(Product* pProduct){

    return pProduct->stock;
}


/** \brief Shows the selected product by screen
 * \param pProduct (Product*) Pointer to the product to be displayed
 * \return void
 */
void product_print(Product* pProduct){

    printf("| Id: %4d | Descripcion: %20s | Direccion: %30s | Localidad: %20s | Recibe: %20s |\r\n",\
        pProduct->productId,pProduct->descripcion,pProduct->direccion,pProduct->localidad,pProduct->recibe);
}


/** \brief Shows all the product in the list of products
 * \param productsList (ArrayList*) Pointer to the list of products to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int product_printArrayList(ArrayList* productsList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!productsList->isEmpty(productsList)){
        for(i=0; i<productsList->len(productsList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            product_print(productsList->get(productsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Shows the localidad of the selected product by screen
 * \param pProduct (Product*) Pointer to the product to be displayed
 * \return void
 */
void product_printLocalidad(Product* pProduct){

    printf("| Localidad: %20s |\r\n",pProduct->localidad);
}


/** \brief Shows all the localidades of the list of products
 * \param productsList (ArrayList*) Pointer to the list of products to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int product_printLocalidadesList(ArrayList* productsList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!productsList->isEmpty(productsList)){
        for(i=0; i<productsList->len(productsList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            product_printLocalidad(productsList->get(productsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Compare products by localidad
 * \param pProductA (void*) Pointer to first product to compare
 * \param pProductB (void*) Pointer to second product to compare
 * \return int Return (1) if name of pProductA is major than name of pProductB
 *                  - (-1) name of pProductA is minor than name of pProductB
 *                  - (0) name of pProductA is equal than name of pProductB
 */
int product_compareByLocalidad(void* pProductA,void* pProductB){

    if(strcmp(((Product*)pProductA)->localidad,((Product*)pProductB)->localidad) > 0){

        return 1;
    }
    if(strcmp(((Product*)pProductA)->localidad,((Product*)pProductB)->localidad) < 0){

        return -1;
    }
    return 0;
}


/** \brief Compare products by name
 * \param pProductA (void*) Pointer to first object to compare
 * \param pProductB (void*) Pointer to second object to compare
 * \return int Return (1) if name of pProductA is major than name of pProductB
 *                  - (-1) name of pProductA is minor than name of pProductB
 *                  - (0) name of pProductA is equal than name of pProductB
 */
int product_compareByName(void* pProductA,void* pProductB){

    if(strcmp(((Product*)pProductA)->name,((Product*)pProductB)->name) > 0){

        return 1;
    }
    if(strcmp(((Product*)pProductA)->name,((Product*)pProductB)->name) < 0){

        return -1;
    }
    return 0;
}


/** \brief Compare products by mail
 * \param pProductA (void*) Pointer to first object to compare
 * \param pProductB (void*) Pointer to second object to compare
 * \return int Return (1) if mail of pProductA is major than mail of pProductB
 *                  - (-1) mail of pProductA is minor than mail of pProductB
 *                  - (0) mail of pProductA is equal than mail of pProductB
 */
int product_compareByMail(void* pProductA,void* pProductB){

    if(strcmp(((Product*)pProductA)->mail,((Product*)pProductB)->mail) > 0){

        return 1;
    }
    if(strcmp(((Product*)pProductA)->mail,((Product*)pProductB)->mail) < 0){

        return -1;
    }
    return 0;
}


/** \brief Compare products by age
 * \param pProductA (void*) Pointer to first object to compare
 * \param pProductB (void*) Pointer to second object to compare
 * \return int Return (1) if age of pProductA is major than age of pProductB
 *                  - (-1) age of pProductA is minor than age of pProductB
 *                  - (0) age of pProductA is equal than age of pProductB
 */
int product_compareByAge(void* pProductA,void* pProductB){

    if(((Product*)pProductA)->age > ((Product*)pProductB)->age){

        return 1;
    }
    if(((Product*)pProductA)->age < ((Product*)pProductB)->age){

        return -1;
    }
    return 0;
}


/** \brief Request a valid product by Id
 * \param productsList (ArrayList*) Pointer to the list of products
 * \return (Product*) Pointer to the product
 */
Product* getValidProduct(ArrayList* productsList){

    int productsListLenght, productIdAux, i;
    Product *productAux;

    productsListLenght = productsList->len(productsList);
    
    do{
        //Se listan los productos 
        product_printArrayList(productsList);
        productIdAux = getValidInt("\nIngrese el codigo del producto: ","\nEl codigo debe ser numerico\n",LOW_LIMIT,HI_LIMIT);
        //Se recorre la lista buscando coincidencia
        for(i = 0; i < productsListLenght; i++){
            productAux = productsList->get(productsList,i);
            //Si lo encuentro salgo del for
            if(productAux->productId == productIdAux){
                break;
            }
        }
        //Si se recorrio toda la lista y no hubo coincidencia se informa y se vuelve a solicitar el codigo
        if(productAux->productId != productIdAux){
            clearScreen();
            printf("\r\nNo se encontro ningun producto con el codigo ingresado, vuelva a intentar\n");
        }
    }while(productAux->productId != productIdAux);
    return productAux;
}


/** \brief Request a valid localidad
 * \param productsList (ArrayList*) Pointer to the list of products
 * \param localidadesList (ArrayList*) Pointer to the list of localidades
 * \param msg (char*) message to be displayed to request a localidad
 * \param localidad (char*) pointer to the char where the localidad will be allocated
 * \return (void)
 */
void getValidLocalidad(ArrayList* productsList, ArrayList* localidadesList, char *msg, char *localidad){

    int i;
    char localidadAux[51];
    Product* productAux;

    printf("\n=============================================\n| Lista de localidades:        \n=============================================\n");

    do{
        product_printLocalidadesList(localidadesList);
        getValidStringAlfanumerico(msg,"\nLa localidad debe ser solo letras y numeros\n",localidad);
        capitalize(localidad);
        for(i = 0; i < productsList->len(productsList); i++){
            productAux = productsList->get(productsList,i);
            strcpy(localidadAux,product_getLocalidad(productAux));
            if(!strcmp(localidadAux,localidad)){
                break;
            }
        }
        if(strcmp(localidadAux,localidad) != 0){
            clearScreen();
            printf("No se encontro coincidencia con la localidad ingresasda, vuelva a intentar\n");
        }
    }while(strcmp(localidadAux,localidad) != 0);
}

