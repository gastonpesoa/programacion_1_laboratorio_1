//
//  types.h
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef practica_modelo_parcial_2_types_h
#define practica_modelo_parcial_2_types_h

#define PRODUCTS_MAX_QTY 200
#define PROVS_MAX_QTY 200

#define ACTIVE 1
#define INACTIVE 0

typedef struct{
    char name[51];
    int productId;
    int provId;
    float price;
    int stock;
    int status; /**< Active (1) or Inactive (0) */
}EProduct;

typedef struct{
    char name[51];
    int provId;
    int status; /**< Active (1) or Inactive (0)  */
}EProv;

#endif
