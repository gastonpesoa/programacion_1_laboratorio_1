#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Llamada.h"

#define LOW_LIMIT 1
#define HI_LIMIT 999999999


/** \brief Allocate a new llamada.
 * \param void
 * \return Llamada* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new llamada) if ok
 */
Llamada* llamada_new(void){

    Llamada* returnAux = NULL;
    returnAux = (Llamada*)malloc(sizeof(Llamada));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


/** \brief Set pLlamada Llamada the id recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \param llamadaId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int llamada_setId(Llamada* pLlamada, int llamadaId, int lowLimit){

    int returnAux = -1;

    if(llamadaId >= lowLimit){

        pLlamada->llamadaId = llamadaId;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pLlamada Llamada the nombreCliente recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \param nombreCliente (char*) Pointer to the llamadao recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int llamada_setNombreCliente(Llamada* pLlamada, char* nombreCliente, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(nombreCliente, lowLimit, hiLimit)) {

        strcpy(pLlamada->nombreCliente,nombreCliente);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pLlamada Llamada the Mail recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \param Mail (char*) Pointer to the Mail recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int llamada_setMail(Llamada* pLlamada, char* mail, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(mail, lowLimit, hiLimit)) {

        strcpy(pLlamada->mail,mail);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pLlamada Llamada the id recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \param llamadaId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int llamada_setDni(Llamada* pLlamada, int dni, int lowLimit){

    int returnAux = -1;

    if(dni >= lowLimit){

        pLlamada->dni = dni;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pLlamada Llamada the producto recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \param producto (char*) Pointer to the producto recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int llamada_setProducto(Llamada* pLlamada, char* producto, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(producto, lowLimit, hiLimit)) {

        strcpy(pLlamada->producto,producto);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Set pLlamada Llamada the observaciones recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \param observaciones (char*) Pointer to the observaciones recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int llamada_setObservaciones(Llamada* pLlamada, char* observaciones, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(observaciones, lowLimit, hiLimit)) {

        strcpy(pLlamada->observaciones,observaciones);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Get the id of the llamada recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \return (int) Id of the llamada
 */
int llamada_getId(Llamada* pLlamada){

    return pLlamada->llamadaId;
}


/** \brief  Get the descrpcion of the llamada recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \return (int) Llamada of the llamada
 */
char* llamada_getNombreCliente(Llamada* pLlamada){

    return pLlamada->nombreCliente;
}


/** \brief  Get the Mail of the llamada recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \return (int) Llamada of the llamada
 */
char* llamada_getMail(Llamada* pLlamada){

    return pLlamada->mail;
}


/** \brief  Get the id of the llamada recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \return (int) Id of the llamada
 */
int llamada_getDni(Llamada* pLlamada){

    return pLlamada->dni;
}


/** \brief  Get the producto of the llamada recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \return (int) Llamada of the llamada
 */
char* llamada_getProducto(Llamada* pLlamada){

    return pLlamada->producto;
}


/** \brief  Get the observaciones of the llamada recived as parameter
 * \param pLlamada (Llamada*)* Pointer to the llamada
 * \return (int) Llamada of the llamada
 */
char* llamada_getObservaciones(Llamada* pLlamada){

    return pLlamada->observaciones;
}


/** \brief Shows the selected llamada by screen
 * \param pLlamada (Llamada*) Pointer to the llamada to be displayed
 * \return void
 */
void llamada_print(Llamada* pLlamada){

    printf("%3d %15s %15s %10d %15s\n",\
        pLlamada->llamadaId,pLlamada->nombreCliente,pLlamada->mail,pLlamada->dni,pLlamada->producto,pLlamada->observaciones);
}


/** \brief Shows all the llamada in the list of llamadas
 * \param llamadasList (ArrayList*) Pointer to the list of llamadas to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int llamada_printArrayList(ArrayList* llamadasList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!llamadasList->isEmpty(llamadasList)){
        for(i=0; i<llamadasList->len(llamadasList); i++){

            if(cont %250 == 0){
                pause("");
               //system("pause");
            }
            cont++;
            //printf("%4d) ",i);
            llamada_print(llamadasList->get(llamadasList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Compare products by age
 * \param pProductA (void*) Pointer to first object to compare
 * \param pProductB (void*) Pointer to second object to compare
 * \return int Return (1) if age of pProductA is major than age of pProductB
 *                  - (-1) age of pProductA is minor than age of pProductB
 *                  - (0) age of pProductA is equal than age of pProductB
 */
int llamada_compareByDni(void* pLlamadaA,void* pLlamadaB){

    if(((Llamada*)pLlamadaA)->dni > ((Llamada*)pLlamadaB)->dni){

        return 1;
    }
    if(((Llamada*)pLlamadaA)->dni < ((Llamada*)pLlamadaB)->dni){

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
int llamada_compareById(void* pLlamadaA,void* pLlamadaB){

    if(((Llamada*)pLlamadaA)->llamadaId > ((Llamada*)pLlamadaB)->llamadaId){

        return 1;
    }
    if(((Llamada*)pLlamadaA)->llamadaId < ((Llamada*)pLlamadaB)->llamadaId){

        return -1;
    }
    return 0;
}


void imprimirEstadisticas(ArrayList *llamadasList){

    int i, j, dniAux, dniAuxDos;
    int maxCantLlamados = 0, cantLlamados = 0;
    int productMax = 0, productCant = 0;
    Llamada *llamadaAux, *llamadaAuxDos, *llamadaMaxCant, *llamadaMaxProduct;
    char productoAux[64], productoAuxDos[64];

    for(i = 0; i < llamadasList->len(llamadasList); i++){

        cantLlamados = 0;

        llamadaAux = llamadasList->get(llamadasList,i);
        dniAux = llamada_getDni(llamadaAux);
        strcpy(productoAux,llamada_getProducto(llamadaAux));

        for(j = i + 1; j < llamadasList->len(llamadasList); j++){

            llamadaAuxDos = llamadasList->get(llamadasList,j);
            dniAuxDos = llamada_getDni(llamadaAuxDos);
            strcpy(productoAuxDos,llamada_getProducto(llamadaAuxDos));

            if(dniAux == dniAuxDos){

                cantLlamados++;
            }

            if(cantLlamados > maxCantLlamados){
                maxCantLlamados = cantLlamados;
                llamadaMaxCant = llamadaAux;
            }

            if(!strcmp(llamada_getProducto(llamadaAux),llamada_getProducto(llamadaAuxDos))){

                productCant++;
            }

            if(productCant > productMax){

                productMax = productCant;
                llamadaMaxProduct = llamadaAux;
            }
        }
    }

    printf("\nCliente con mas llamadas: ");
    printf("\nNombre: %s Dni: %d",llamada_getNombreCliente(llamadaMaxCant),llamada_getDni(llamadaMaxCant));
    printf("\n\nProducto mas consultado: %s",llamada_getProducto(llamadaMaxProduct));
}

