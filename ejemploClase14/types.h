//
//  types.h
//  ejemploClase14
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef ejemploClase14_types_h
#define ejemploClase14_types_h

#define BOOKS_MAX_QTY 200
#define AUTHORS_MAX_QTY 200

typedef struct{
    char title[51];
    int code;
    int stock;
    int authorId;
    int status; /**< Active (1) or Inactive (0) */
}book;

typedef struct{
    char name[51];
    char lastName[51];
    int authorId;
    int status; /**< Active (1) or Inactive (0)  */
}author;

#endif
