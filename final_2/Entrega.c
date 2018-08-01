#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Entrega.h"


/** \brief Allocate a new entrega.
 * \param void
 * \return Entrega* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new entrega) if ok
 */
Entrega* entrega_new(void){

    Entrega* returnAux = NULL;
    returnAux = (Entrega*)malloc(sizeof(Entrega));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


/** \brief Set pEntrega Entrega the id recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param entregaId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setId(Entrega* pEntrega, int entregaId, int lowLimit){

    int returnAux = -1;

    if(entregaId >= lowLimit){

        pEntrega->entregaId = entregaId;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pEntrega Entrega the producto recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param producto (char*) Pointer to the producto recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setProduct(Entrega* pEntrega, char* producto, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(producto, lowLimit, hiLimit)) {

        strcpy(pEntrega->producto,producto);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pEntrega Entrega the direccion recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param direccion (char*) Pointer to the direccion recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setDireccion(Entrega* pEntrega, char* direccion, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(direccion, lowLimit, hiLimit)) {

        strcpy(pEntrega->direccion,direccion);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pEntrega Entrega the localidad recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param localidad (char*) Pointer to the localidad recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setLocalidad(Entrega* pEntrega, char* localidad, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(localidad, lowLimit, hiLimit)) {

        strcpy(pEntrega->localidad,localidad);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pEntrega Entrega the recibe recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param recibe (char*) Pointer to the recibe recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setRecibe(Entrega* pEntrega, char* recibe, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(recibe, lowLimit, hiLimit)) {

        strcpy(pEntrega->recibe,recibe);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Get the id of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Id of the entrega
 */
int entrega_getId(Entrega* pEntrega){

    return pEntrega->entregaId;
}


/** \brief  Get the producto of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getProduct(Entrega* pEntrega){

    return pEntrega->producto;
}


/** \brief  Get the direccion of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getDireccion(Entrega* pEntrega){

    return pEntrega->direccion;
}


/** \brief  Get the localidad of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getLocalidad(Entrega* pEntrega){

    return pEntrega->localidad;
}


/** \brief  Get the recibe of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getRecibe(Entrega* pEntrega){

    return pEntrega->recibe;
}


/** \brief Shows the selected entrega by screen
 * \param pEntrega (Entrega*) Pointer to the entrega to be displayed
 * \return void
 */
void entrega_print(Entrega* pEntrega){

    printf("| Id: %4d | Producto: %20s | Direccion: %30s | Localidad: %20s | Recibe: %20s |\r\n",\
        pEntrega->entregaId,pEntrega->producto,pEntrega->direccion,pEntrega->localidad,pEntrega->recibe);
}


/** \brief Shows all the entrega in the list of entregas
 * \param entregasList (ArrayList*) Pointer to the list of entregas to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int entrega_printArrayList(ArrayList* entregasList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!entregasList->isEmpty(entregasList)){
        for(i=0; i<entregasList->len(entregasList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            entrega_print(entregasList->get(entregasList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Shows the localidad of the selected entrega by screen
 * \param pEntrega (Entrega*) Pointer to the entrega to be displayed
 * \return void
 */
void entrega_printLocalidad(Entrega* pEntrega){

    printf("| Localidad: %20s |\r\n",pEntrega->localidad);
}


/** \brief Shows all the localidades of the list of entregas
 * \param entregasList (ArrayList*) Pointer to the list of entregas to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int entrega_printLocalidadesList(ArrayList* entregasList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!entregasList->isEmpty(entregasList)){
        for(i=0; i<entregasList->len(entregasList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            entrega_printLocalidad(entregasList->get(entregasList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Compare entregas by localidad
 * \param pEntregaA (void*) Pointer to first entrega to compare
 * \param pEntregaB (void*) Pointer to second entrega to compare
 * \return int Return (1) if name of pEntregaA is major than name of pEntregaB
 *                  - (-1) name of pEntregaA is minor than name of pEntregaB
 *                  - (0) name of pEntregaA is equal than name of pEntregaB
 */
int entrega_compareByLocalidad(void* pEntregaA,void* pEntregaB){

    if(strcmp(((Entrega*)pEntregaA)->localidad,((Entrega*)pEntregaB)->localidad) > 0){

        return 1;
    }
    if(strcmp(((Entrega*)pEntregaA)->localidad,((Entrega*)pEntregaB)->localidad) < 0){

        return -1;
    }
    return 0;
}


/** \brief Request a valid localidad 
 * \param entregasList (ArrayList*) Pointer to the list of entregas
 * \param localidadesList (ArrayList*) Pointer to the list of localidades
 * \param msg (char*) message to be displayed to request a localidad
 * \param localidad (char*) pointer to the char where the localidad will be allocated
 * \return (void)
 */
void getValidLocalidad(ArrayList* entregasList, ArrayList* localidadesList, char *msg, char *localidad){

    int i;
    char localidadAux[51];
    Entrega* entregaAux;

    printf("\n=============================================\n| Lista de localidades:        \n=============================================\n");

    do{
        entrega_printLocalidadesList(localidadesList);
        getValidStringAlfanumerico(msg,"\nLa localidad debe ser solo letras y numeros\n",localidad);
        capitalize(localidad);
        for(i = 0; i < entregasList->len(entregasList); i++){
            entregaAux = entregasList->get(entregasList,i);
            strcpy(localidadAux,entrega_getLocalidad(entregaAux));
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

