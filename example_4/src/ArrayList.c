#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void){

    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL){

        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL){

            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else{
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement){

    int returnAux = -1;
    void** thisAux;

    if(this == NULL || pElement == NULL){

        return returnAux;
    }

    this->pElements[this->size] = pElement;
    this->size++;

    if(this->size >= this->reservedSize){

        this->reservedSize += AL_INCREMENT;
        thisAux = (void**)realloc(this->pElements, sizeof(ArrayList*)*this->reservedSize);

        if(thisAux == NULL){

            printf("\nNo hay espacio en memoria para agrandar la lista\n");
            free(thisAux);
            return returnAux;
        }

        this->pElements = thisAux;
    }
    return 0;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this){

    if(this == NULL){

        return -1;
    }

    /*if(this->size < 1){

        return 1;
    }*/

    free(this->pElements);
    return 0;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this){

    if(this != NULL){

        return this->size;
    }
    return -1;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this == NULL || index < 0 || index > this->size){

        return returnAux;
    }
    return this->pElements[index];
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement){

    int i;

    if(this == NULL || pElement == NULL){

        return -1;
    }

    for(i = 0; i < al_len(this); i++){

        if(al_get(this,i) == pElement){

            return 1;
        }
    }
    return 0;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement){

    //int i;

    if(this == NULL || pElement == NULL || index < 0 || index > this->size){
        return -1;
    }

    //this->size++;

    /*for(i = index; i < al_len(this); i++){

        this->pElements[i] = this->pElements[i];
    }*/

    this->pElements[index] = pElement;
    return 0;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index){

    int i;

    if(this == NULL || index < 0 || index > this->size){
        return -1;
    }

    for(i = index; i < (al_len(this))-1; i++){

        this->pElements[i] = this->pElements[i+1];
    }
    this->size--;
    return 0;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this){

    if(this == NULL){

        return -1;
    }
    //free(this->pElements);
    this->size = 0;
    return 0;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this){

    ArrayList* returnAux = NULL;
    ArrayList* thisClone = al_newArrayList();
    int i;

    if(this == NULL || thisClone == NULL){

        return returnAux;
    }

    for(i = 0; i < al_len(this); i++){

        al_add(thisClone,al_get(this,i));
    }
    return thisClone;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement){

    int i;

    if(this == NULL || pElement == NULL || index < 0 || index > this->size){
        return -1;
    }

    this->size++;

    for(i = index; i < al_len(this); i++){

        this->pElements[i+1] = al_get(this,i);
    }

    this->pElements[index] = pElement;
    return 0;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement){

    int i;

    if(this == NULL || pElement == NULL){

        return -1;
    }

    for(i = 0; i < al_len(this); i++){

        if(al_get(this,i) == pElement){

            return i;
        }
    }
    return -1;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this){

    if(this == NULL){

        return -1;
    }

    if(al_len(this) == 0){
        return 1;
    }

    return 0;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this == NULL || index < 0 || index > this->size){

        return returnAux;
    }

    returnAux = al_get(this,index);

    al_remove(this,index);

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to){

    int i;
    void* returnAux = NULL;
    ArrayList* portionList = al_newArrayList();

    if(this == NULL || from < 0 || from > to || to < 0 || to > this->size){

        return returnAux;
    }

    for(i = from; i <= to; i++){

        al_add(portionList, this->pElements[i]);
    }

    returnAux = portionList;

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1, matchElmntsQty = 0;
    int i;

    if(this == NULL || this2 == NULL){

        return returnAux;
    }

    for(i = 0; i < al_len(this); i++){

        if(al_get(this,i) == al_get(this2,i)){
            matchElmntsQty++;
        }
    }

    if(al_len(this2) == matchElmntsQty){
        returnAux = 1;
    }
    else {
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order){

    int returnAux = -1;
    int i, j;
    ArrayList* thisAux = al_newArrayList();

    if(this == NULL || thisAux == NULL || pFunc == NULL || order < 0 || order > 1){
        return returnAux;
    }
    //if(order){
    for(i = 0; i < al_len(this)-1; i++){

        for(j = i+1; j < al_len(this); j++){

            if(pFunc(this->pElements[i],this->pElements[j])==1 && order==1){

                thisAux->pElements = this->pElements[j];
                this->pElements[j] = this->pElements[i];
                this->pElements[i] = thisAux->pElements;
            }
            else {

                if(pFunc(this->pElements[i],this->pElements[j])==-1 && order == 0){

                    thisAux->pElements = this->pElements[j];
                    this->pElements[j] = this->pElements[i];
                    this->pElements[i] = thisAux->pElements;
                }
            }
        }
    }
    //}
    /*else {
        if(pFunc(this->pElements[i],this->pElements[j]) == -1){

            thisAux->pElements = this->pElements[j];
            this->pElements[j] = this->pElements[i];
            this->pElements[i] = thisAux->pElements;

        }
    }*/

    /*for(i = 0; i < al_len(this)-1; i++){

        for(j = i+1; j < al_len(this); j++){

            if(pFunc(this->pElements[i],this->pElements[j])==1 && order == 1){

                thisAux->pElements = this->pElements[j];
                this->pElements[j] = this->pElements[i];
                this->pElements[i] = thisAux->pElements;
            }
            else {
                if(this->pElements[i],this->pElements[j])==-1 && order == 0){

                    thisAux->pElements = this->pElements[j];
                    this->pElements[j] = this->pElements[i];
                    this->pElements[i] = thisAux->pElements;
                }
            }
        }
    }*/
    returnAux = 0;
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}
