#include <stdio.h>

#define ARCH	".\\bin.dat"
#define ESC 27

struct a{
		char nombre[31];
		int edad;
		int legajo;
	};

int main (void)
{
   FILE  *bin;
   struct a pers;
   int cant;
   int legajoAux;

   if ((bin=fopen(ARCH,"rb+"))==NULL){
      if ((bin=fopen(ARCH,"wb+"))==NULL){
         printf("No se pudo abrir el archivo");
         exit(1);
      }
   }

   do{
      printf("\nIngrese el nombre: ");
      gets(pers.nombre);

      printf("Ingrese la edad: ");
      scanf("%d",&pers.edad);

      printf("Ingrese la legajo: ");
      scanf("%d",&pers.legajo);

      fflush(stdin);
      fseek(bin , 0L, SEEK_END);
      fwrite(&pers,sizeof(pers),1,bin);

      printf("\nPresione ESC para terminar");
   }while((getche())!=ESC);

   /* Busqueda */
   system("cls");
   printf("Legajo: ");
   scanf("%d", &legajoAux);

   //se lleva el indicador de posición al principio para comenzar a leer
   rewind (bin);

   while(!feof(bin)){
      cant = fread(&pers,sizeof(pers),1,bin);

      if(cant!=1){
         if(feof(bin)){
			break;
         }
         else{
			printf("No leyo el ultimo registro");
			break;
         }
      }

      if(legajoAux == pers.legajo){
        printf("\nIngrese nuevo nombre: ");
        fflush(stdin);
        gets(pers.nombre);

        fseek(bin , (long) (-1) * sizeof(pers), SEEK_CUR);
        fflush(stdin);
        fwrite(&pers,sizeof(pers),1,bin);
        break;
      }

      //printf("\n%s\t%d",pers.nombre,pers.edad);
   }

   //se lleva el indicador de posición al principio para comenzar a leer
   rewind (bin);

   while(!feof(bin)){
      cant = fread(&pers,sizeof(pers),1,bin);

      if(cant!=1){
         if(feof(bin)){
			break;
         }
         else{
			printf("No leyo el ultimo registro");
			break;
         }
      }

      printf("\n%s\t%d",pers.nombre,pers.edad);
   }

   fclose(bin);
   getch();

   return 0;
}
