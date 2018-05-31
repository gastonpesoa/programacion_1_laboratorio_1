#include <stdio.h>

#define ARCH	".\\bin.dat"
#define ESC 27

struct a{
		char nombre[31];
		int edad;
	};

int main (void)
{
	FILE  *bin;
	struct a pers;
	system("pause");
	printf("\nSe va a generar por primera vez el archivo\n");
	if ((bin=fopen(ARCH,"wb"))==NULL)
	{
		printf("El archivo no puede ser abierto");
		exit(1);
	}
	do
	{
		printf("\nIngrese el nombre: ");
		gets(pers.nombre);
		printf("Ingrese la edad: ");
		scanf("%d",&pers.edad);
		fflush(stdin);
		fwrite(&pers,sizeof(pers),1,bin);
		printf("\nPresione ESC para terminar");
	}while((getche())!=ESC);

	fclose(bin);
	
	return 0;
}
