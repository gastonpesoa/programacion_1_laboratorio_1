//
//  types.h
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 02/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef practicaModeloParcial_1_types_h
#define practicaModeloParcial_1_types_h

#define PRODUCTS_MAX_QTY 1000
#define USERS_MAX_QTY 100

typedef struct{
    int productId;
    char name[51];
    int userId;
    float price;
    int stock;
    int salesQty;
    int status; /**< Active (1) or Inactive (0) */
}product;

typedef struct{
    int userId;
    char name[51];
    char password[51];
    int qualificationProm;
    int status; /**< Active (1) or Inactive (0)  */
}user;

#endif
