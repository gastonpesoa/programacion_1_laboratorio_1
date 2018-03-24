//
//  main.c
//  ejercicio8
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
/*  8. Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y muestre el resultado. */

#include <stdio.h>

int main()
{
    int base;
    int altura;
    int area;
    
    printf("Ingrese la base del triangulo: ");
    scanf("%d", &base);
    
    printf("Ingrese la altura del triangulo: ");
    scanf("%d", &altura);
    
    area = (base * altura) / 2;
    
    printf("La superficie del triangulo es: %d\n", area);
    
    return 0;
}
