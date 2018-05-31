#include <stdio.h>

int main ()
{
 	FILE *fp;

 	char buffer[100] = "Esto es un texto dentro del fichero.";

 	fp = fopen ( "fichero.txt", "w+" );

 	fprintf(fp, buffer);
 	fprintf(fp, "%s", "\nEsto es otro texto dentro del fichero.");
 	fprintf(fp, "\nEsto es otro texto dentro del fichero. y el buffer contiene: %s", buffer);

 	fclose ( fp );

 	return 0;
}
