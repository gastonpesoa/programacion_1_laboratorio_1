#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int main()
{
        FILE *archivo;

        char variable[50]="Hola a todos";
		char buffer[1080]={};

        strcat(buffer,"<html><head><style>table, th, td {border: 1px solid black; border-collapse: collapse;}th, td { padding: 15px;}</style> </head><body><MARQUEE BGCOLOR=#7070ff><h1>");
        strcat(buffer,variable);

        strcat(buffer,"</h1></MARQUEE><br><br>");
        strcat(buffer,"<table style='width:100%'><tr><th>Firstname</th><th>Lastname</th> <th>Age</th></tr><tr><td>Jill</td><td>Smith</td><td>50</td></tr><tr> <td>Eve</td><td>Jackson</td><td>94</td></tr><tr> <td>John</td> <td>Doe</td> <td>80</td> </tr></table> </body></html>");
        archivo = fopen(".\\prueba.html","w");

         fprintf(archivo,buffer);

		 fclose(archivo);

        return 0;
}
