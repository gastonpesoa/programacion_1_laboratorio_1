
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

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
    void** pElements;
    this = (ArrayList*)malloc(sizeof(ArrayList));

    if(this != NULL){

        pElements = (void**)malloc(sizeof(void*)*AL_INITIAL_VALUE);
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
            this->map = al_map;
            this->removeDuplicates = al_removeDuplicates;
            this->refine = al_refine;
            returnAux = this;
        }
        else{
            free(this);
            this = NULL;
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

    if(this != NULL && pElement != NULL){

        this->pElements[this->size] = pElement;
        this->size++;
        if(this->size >= this->reservedSize){

            if(resizeUp(this) == -1){

                return returnAux;
            }
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this){

    int returnAux = -1;

    if(this != NULL){

        free(this->pElements);
        this->pElements = NULL;
        free(this);
        this = NULL;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief  Get the lenght of the arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this){

    int returnAux = -1;

    if(this != NULL){

        return this->size;
    }
    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index){

    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < this->len(this)){

        return this->pElements[index];
    }
    return returnAux;
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

    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL){

        for(i = 0; i < this->len(this); i++){

            if(this->get(this,i) == pElement){

                return 1;
            }
        }
        returnAux = 0;
    }
    return returnAux;
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

    int returnAux = -1;

    if(this != NULL && pElement != NULL && index >= 0 && index < this->len(this)){

        this->pElements[index] = pElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index){

    int returnAux = -1;

    if(this != NULL && index >= 0 && index < this->len(this)){

        if(contract(this,index) == 0){
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this){

    int returnAux = -1, i;

    if(this != NULL){

        for(i = 0; i < this->len(this); i++){

            free(this->get(this,i));
            this->pElements[i] = NULL;
            this->size--;
        }
        void *pElementsAux = realloc(this->pElements, sizeof(void*)*AL_INITIAL_VALUE);
        if(pElementsAux != NULL){

            this->pElements = pElementsAux;
            this->reservedSize = AL_INITIAL_VALUE;
            returnAux = 0;
        }
    }
    return returnAux;
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

    if(this != NULL && thisClone != NULL){

        for(i = 0; i < this->len(this); i++){

            this->add(thisClone,this->get(this,i));
        }
        returnAux = thisClone;
    }
    return returnAux;
}


/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement){

    int returnAux = -1;

    if(this != NULL && pElement != NULL && index >= 0 && index <= this->size){

        if(expand(this,index) == 0){

            this->pElements[index] = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement){

    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL){

        for(i = 0; i < this->len(this); i++){

            if(this->get(this,i) == pElement){

                return i;
            }
        }
    }
    return returnAux;
}


/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this){

    int returnAux = -1;

    if(this != NULL){

        if(this->len(this) == 0){

            returnAux = 1;
        }
        else {

           returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index){

    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < this->len(this)){

        returnAux = this->get(this,index);
        this->remove(this,index);
    }
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

    void* returnAux = NULL;
    ArrayList* portionList = al_newArrayList();
    int i;

    if(this != NULL && portionList != NULL && from >= 0 && from < to && to > 0 && to <= this->len(this)){

        for(i = from; i <= to; i++){

            this->add(portionList,this->get(this,i));
        }
        returnAux = portionList;
    }
    return returnAux ;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2){

    int returnAux = -1;
    int i;

    if(this != NULL && this2 != NULL){

        for(i = 0; i < this2->len(this2); i++){

            if(this->contains(this,this2->get(this2,i))){

                continue;
            }
            else {

                return 0;
            }
        }
        returnAux = 1;
    }
    return returnAux;
}


/** \brief Charge the field of a list passes as parameter, calculate the value use pFunc
 * \param this ArrayList* Pointer to arrayList
 * \param void (*pFunc) Pointer to fuction to calculate the value of sueldo
 * \return int Return -
 */
void al_map(ArrayList* this,void (*pFunc)(void*)){

    int i;
    for(i = 0; i < this->len(this); i++){
        pFunc(this->get(this,i));
    }

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
    void* temp = NULL;
    int i, j;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){

        for(i = 1; i < this->len(this); i++){

            temp = this->get(this,i);
            j = i - 1;
            if(pFunc(this->get(this,j),temp) != 0){

                if(order == 1){

                    while (j >= 0 && pFunc(this->get(this,j),temp) == 1){

                        this->pElements[j+1] = this->get(this,j);
                        j--;
                    }
                    this->pElements[j+1] = temp;
                }
                else {

                    while (j >= 0 && pFunc(this->get(this,j),temp) == -1){

                        this->pElements[j+1] = this->get(this,j);
                        j--;
                    }
                    this->pElements[j+1] = temp;
                } //  if(order == 1)
            } // if(returnedPFunc != 0)
        } // for(i = 1; i < this->len(this); i++)
        returnAux = 0;
    } // if(this != NULL && thisAux != NULL && pFunc != NULL && (order == 0 || order == 1))
    return returnAux;
}


/** \brief Returns a new list by removing the elements with repeated data,
 *   analyzing the field in the function passed as parameter.
 * \param this ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \return ArrayList* Return (NULL) if Error [this or pFunc are NULL pointer]
 *                  - (pointer to new array) if Ok
 */
ArrayList* al_removeDuplicates(ArrayList* this, int (*pFunc)(void*,void*)){

    void* returnAux = NULL;
    ArrayList* thisAux = this->clone(this);
    void* pElementAux = NULL;
    int i, j;

    if(this != NULL && pFunc != NULL){

        for(i = 0; i < thisAux->len(thisAux); i++){

            pElementAux = thisAux->get(thisAux,i);
            for(j = i + 1; j < thisAux->len(thisAux); j++){

                if(!pFunc(thisAux->get(thisAux,j),pElementAux)){

                    thisAux->remove(thisAux,j);
                    j--;
                }
            }
        }
        returnAux = thisAux;
    }
    return returnAux;
}


/** \brief Returns a new list with the elements of this that are not contained in this2.
 * \param this ArrayList* Pointer to arrayList with elements to be compared
 * \param this2 ArrayList* Pointer to arrayList with elements to be deleted
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \return ArrayList* Return (NULL) if Error [this, this2 or pFunc are NULL pointer]
 *                  - (pointer to new array) if Ok
 */
ArrayList* al_refine(ArrayList* this, ArrayList*  this2, int (*pFunc)(void*,void*)){

    void *pElementRefined, *pElementThis2;
    ArrayList* returnAux = NULL;
    ArrayList* refinedList = al_newArrayList();

    if(refinedList != NULL){

        refinedList = this->clone(this);

        int i, j, refinedLenght;
        refinedLenght = refinedList->len(refinedList);
        for(i = 0; i < refinedLenght; i++){

            pElementRefined = refinedList->get(refinedList,i);
            for(j = 0; j < this2->len(this2); j++){

                pElementThis2 = this2->get(this2,j);
                if(!pFunc(pElementRefined,pElementThis2)){

                    refinedList->remove(refinedList,i);
                    refinedLenght = refinedList->len(refinedList);
                    i--;
                    break;
                }
            }
        }
        returnAux = refinedList;
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this){

    void** thisAux;
    int returnAux = -1;

    if(this != NULL){

        this->reservedSize += AL_INCREMENT;
        thisAux = (void**)realloc(this->pElements, sizeof(void*)*this->reservedSize);

        if(thisAux == NULL){
            printf("\nNo hay espacio en memoria para agrandar la lista\n");
            free(thisAux);
            thisAux = NULL;
            return returnAux;
        }
        this->pElements = thisAux;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index){

    int i;
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= this->len(this)){

        this->size++;
        if(this->size >= this->reservedSize){

            if(resizeUp(this) == -1){

                return returnAux;
            }
        }
        for(i = this->len(this) -1 ; i > index ; i--){

             this->pElements[i] = this->get(this,i-1);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index){

    int returnAux = -1;
    int i;

    if(this != NULL && index >= 0 && index < this->len(this)){

        for(i = index; i < (this->len(this)); i++){

            this->pElements[i] = this->pElements[i+1];
        }

        free(this->get(this,(this->len(this))-1));
        this->pElements[this->len(this)-1] = NULL;
        this->size--;
        returnAux = 0;
    }
    return returnAux;
}

