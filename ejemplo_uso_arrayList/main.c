#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int printArrayList(ArrayList* list){

    int returnAux = -1;
    int i;

    if(!list->isEmpty(list)){
        for(i=0; i<list->len(list); i++){
            printf("%d) ",i);
            printEmployee(list->get(list,i));
        }
        returnAux = 0;
    }
    return returnAux;
}

int main() {

    Employee* emp0 = newEmployee(1, "Emp1", "Sanchez", 4568.26, 3);
    Employee* emp1 = newEmployee(2, "Emp2", "Brown", 23566.12, 3);
    Employee* emp2 = newEmployee(3, "Emp3", "Garcia", 3566.12, 3);
    Employee* emp3 = newEmployee(4, "Emp4", "Gomez", 15566.12, 3);
    Employee* emp4 = newEmployee(5, "Emp5", "Perez", 60000.12, 3);

    printEmployee(emp0);
    printEmployee(emp1);
    printEmployee(emp2);
    printEmployee(emp3);
    printEmployee(emp4);

    printf("\r\nCargo ArraList...\r\n");
    ArrayList* list = al_newArrayList();
    if(al_add(list,emp0)==-1){
        printf("\nNo se cargo el empleado");
    }
    if(al_add(list,emp1)==-1){
        printf("\nNo se cargo el empleado");
    }
    if(al_add(list,emp2)==-1){
        printf("\nNo se cargo el empleado");
    }
    if(al_add(list,emp3)==-1){
        printf("\nNo se cargo el empleado");
    }
    if(al_add(list,emp4)==-1){
        printf("\nNo se cargo el empleado");
    }
    printArrayList(list);

    int sizeLen = list->len(list);
    printf("\r\nSize de la lista: %d\r\n",sizeLen);

//    list->sort(list,compareEmployee,1);
//    printf("\r\nLista Ordenada por Salario (UP):%p\r\n",list);
//    printArrayList(list);
//
//    list->sort(list,compareEmployee,0);
//    printf("\r\nLista Clonada Ordenada por Salario (DOWN):%p\r\n",list);
//    printArrayList(list);

    printf("\r\nRemuevo index 2\r\n");
    list->remove(list,2);
    printArrayList(list);

    printf("\r\nContiene emp0 ?\r\n");
    if(list->contains(list,emp0)){
        printf("El elemento se encuentra contenido en la lista\r\n");
    }
    else {
        printf("El elemento NO se encuentra contenido en la lista\r\n");
    }

    printf("\r\nContiene emp2 ?\r\n");
    if(list->contains(list,emp2)){
        printf("El elemento se encuentra contenido en la lista\r\n");
    }
    else {
        printf("El elemento NO se encuentra contenido en la lista\r\n");
    }

    printf("\r\nAgrego emp2 en la posicion 1\r\n");
    list->set(list,1,emp2);
    printArrayList(list);

    printf("\r\nClonamos array\r\n");
    ArrayList* listClone = al_newArrayList();
    if(listClone != NULL){
        listClone = list->clone(list);
    }
    else {
        printf("\r\nNo hay espacio en memoria para la nueva lista\r\n");
    }
    printf("\r\nLista Original: %p \r\n",list);
    printArrayList(list);
    printf("\r\nLista Clonada: %p \r\n",listClone);
    printArrayList(listClone);

    list->sort(listClone,compareEmployee,1);
    printf("\r\nLista Clonada Ordenada por Salario (UP):%p\r\n",listClone);
    printArrayList(listClone);

    list->sort(listClone,compareEmployee,0);
    printf("\r\nLista Clonada Ordenada por Salario (DOWN):%p\r\n",listClone);
    printArrayList(listClone);

    printf("\r\nlista contiene lista clonada?:");
    if(list->containsAll(list,listClone)){
        printf("SI\r\n");
    }
    else {
        printf("NO");
    }

    printf("\r\n\r\nPosicion de emp2: ");
    int empIndex;
    empIndex = list->indexOf(list,emp2);
    if(empIndex != -1){
        printf("%d\r\n",empIndex);
    }
    else {
        printf("El empleado no se encuentra registrado\r\n");
    }

    printf("\r\nPosicion de emp1: ");
    empIndex = list->indexOf(list,emp1);
    if(empIndex != -1){
        printf("%d\r\n",empIndex);
    }
    else {
        printf("El empleado no se encuentra registrado\r\n");
    }

    printf("\r\n\r\nHacemos push de emp1 en la posicion 1\r\n");
    printf("\r\nLista original: \r\n");
    printArrayList(list);
    if(list->push(list,1,emp1) != -1){
        printf("\r\nEmp1: \r\n");
        printEmployee(emp1);
        printf("\r\nLista con push: \r\n");
        printArrayList(list);
    }
    else {
        printf("\r\nNo se pudo realizar esta funcion\r\n");
    }

    printf("\r\nObtenemos sub-lista de 1 a 2\r\n");
    ArrayList* subList = al_newArrayList();
    if(subList != NULL){
        subList = list->subList(list,1,2);
    }
    else {
        printf("\r\nNo hay espacio en memoria para una nueva lista\r\n");
    }
    printArrayList(subList);

    printf("\r\n\r\nHacemos pop de emp1 en la posicion 1\r\n");
    Employee* empPop = list->pop(list,1);
    if(empPop != NULL){
        printf("\r\nElemento pop(): %s\r\n",empPop->name);
        //printEmployee(empPop);
        printArrayList(list);
    }
    else {
        printf("\r\nNo se pudo obterner el elemento\r\n");
    }

    printf("\r\nClear array\r\n");
    if(list->clear(list) != -1){
        printf("\r\nElementos eliminados\r\n");
    }
    else {
        printf("\r\nNo hay elemtos para eliminar\r\n");
    }
    if(printArrayList(list) == -1){
        printf("\r\nNo hay elementos para listar\r\n");
    }

    printf("\r\nEsta vacio?: \r\n");
    if(list->isEmpty(list)){
        printf("SI\r\n");
    }
    else {
        printf("NO\r\n");
    }

    printf("\r\n\r\nTest size\r\n");
    int j;
    for(j = 0; j < 1100; j++){
        Employee* empAux = (Employee*)malloc(sizeof(Employee));
        empAux->id = j+1;
        sprintf(empAux->name,"Juan %d",j);
        sprintf(empAux->lastName,"Perez %d",j);
        empAux->salary = j + 1000.00;
        empAux->sector = 1;
        list->add(list,empAux);
    }
    printf("\r\nCantidad de elementos: %d",list->len(list));
    //printArrayList(list);
    for(j = 0; j < 1100; j++){
        list->pop(list);
    }
    printf("\r\nCantidad de elementos luego de pop: %d",list->len(list));
    printf("\r\nLibero memoria y termino\r\n");

    list->deleteArrayList(list);
    list->deleteArrayList(subList);
    list->deleteArrayList(listClone);

    return 0;
}
