/*  main.c
//  ejercicio3
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//  3. Escribir un programa que realice las siguientes acciones
     Limpie la pantalla
     Asigne a 2 variables numero1 y numero2 valores distintos de cero
     Efectúe el producto de dichas variables
     Muestre el resultado pos pantalla
     Obtenga el cuadrado de numero1 y lo muestre par pantalla */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int producto;
    int potenciaCuadrado;
    
    do
    {
        printf("Ingrese el primer numero: ");
        scanf("%d", &numeroUno);
    } while (numeroUno < 0);
    
    do
    {
        printf("Ingrese el segundo numero: ");
        scanf("%d", &numeroDos);
    } while (numeroDos < 0);
    
    producto = numeroUno * numeroDos;
    printf("El producto de los numeros ingresados es: %d\n", producto);
    potenciaCuadrado = numeroUno * numeroUno;
    printf("El cuadrado del primer numero ingresado es: %d\n", potenciaCuadrado);
    return 0;
}
