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


ArrayList* al_newArrayList(void){

    ArrayList* this;
    ArrayList* returnAux = NULL;
    void** pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL){

        pElements = (void**)malloc(sizeof(void*)*AL_INITIAL_VALUE );
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
            this = NULL;
        }
    }

    return returnAux;
}


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


int al_deleteArrayList(ArrayList* this){

    int returnAux = -1;

    if(this != NULL){

        this->clear(this);

        free(this->pElements);
        this->pElements = NULL;

        free(this);
        this = NULL;

        returnAux = 0;
    }
    return returnAux;
}


int al_len(ArrayList* this){

    int returnAux = -1;

    if(this != NULL){

        return this->size;
    }
    return returnAux;
}


void* al_get(ArrayList* this, int index){

    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < this->len(this)){

        return this->pElements[index];
    }
    return returnAux;
}


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


int al_set(ArrayList* this, int index,void* pElement){

    int returnAux = -1;

    if(this != NULL && pElement != NULL && index >= 0 && index < this->size){

        this->pElements[index] = pElement;
        returnAux = 0;
    }
    return returnAux;
}


int al_remove(ArrayList* this,int index){

    int returnAux = -1;

    if(this != NULL && index >= 0 && index < this->len(this)){

        if(contract(this,index) == 0){
            returnAux = 0;
        }
    }
    return returnAux;
}


int al_clear(ArrayList* this){

    int returnAux = -1;

    if(this != NULL){

        for(int i = 0; i < this->len(this); i++){

            free(this->get(this,i)); 
            this->pElements[i] = NULL;
            this->size--;
        }

        this->size = 0;
        returnAux = 0;
    }
    return returnAux;
}


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


void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < this->len(this)){

        returnAux = this->get(this,index);
        this->remove(this,index);
    }
    return returnAux;
}


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


int al_containsAll(ArrayList* this,ArrayList* this2)
{
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


int resizeUp(ArrayList* this)
{
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


int expand(ArrayList* this,int index)
{
    int i;
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= this->len(this)){

        this->size++;

        for(i = this->len(this) -1 ; i > index ; i--){

             this->pElements[i] = this->get(this,i-1);
        }
        returnAux = 0;
    }
    return returnAux;
}


int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this != NULL && index >= 0 && index < this->len(this)){

        for(i = index; i < (this->len(this)); i++){

            this->pElements[i] = this->pElements[i+1];
        }

        free(this->get(this,(this->len(this))-1));
        this->pElements[this->len(this)-1] = NULL;
        //free(this->pElements[this->len(this)-1]);
        this->size--;
        returnAux = 0;
    }
    return returnAux;
}

