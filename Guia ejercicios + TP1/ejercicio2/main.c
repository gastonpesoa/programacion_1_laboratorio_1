/*  main.c
//  ejercicio2
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//  2. Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado   */

#include <stdio.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;
    
    printf("Ingrese el primer numero: ");
    scanf("%d",&numeroUno);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numeroDos );
    
    resultado = numeroUno + numeroDos;
    
    printf("El resultado es: %d",resultado);
    
    return 0;
}
