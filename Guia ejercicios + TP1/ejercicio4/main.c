/*  main.c
//  ejercicio4
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//  4. Escribir un programa que realice las siguientes acciones:
     Limpie la pantalla
     Declare 2 variables y les asigne sendos valores
     Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor que cero o "Resultado negativo" si es menor que cero */

#include <stdio.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resta;
    
    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);
    
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);
    
    resta = numeroUno - numeroDos;
    
    if (resta > 0)
    {
        printf("Resultado: %d\nResultado positivo\n", resta);
    }
    else
    {
        if (resta == 0)
        {
            printf("Resultado: %d\nEl resultado es 0\n", resta);
        }
        else
        {
            printf("Resultado: %d\nResultado negativo\n", resta);
        }
    }
    return 0;
}
