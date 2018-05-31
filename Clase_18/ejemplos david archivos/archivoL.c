#include <stdio.h>

#define ARCH	".\\bin.dat"

struct a{
		char nombre[31];
		int edad;
	};


int main (void)
{
	FILE  *bin;
	struct a pers;
	int cant;
	system("cls");
	if ((bin=fopen(ARCH,"rb"))==NULL)
	{
		printf("No se pudo abrir el archivo");
		exit(1);
	}
	while(!feof(bin))
	{
			cant=fread(&pers,sizeof(pers),1,bin);
			if(cant!=1)
			{
				if(feof(bin))
					break;
				else
				{
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
