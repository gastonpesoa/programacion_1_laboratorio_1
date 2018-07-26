#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Object.h"
#include "Song.h"
#include "Artist.h"
#include "Reproduction.h"
#include "Input.h"
#include "Files.h"

#define ARCH_1 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final/modelo_final_1/usuarios.dat"
#define ARCH_2 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final/modelo_final_1/temas.dat"
#define ARCH_3 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final/modelo_final_1/estadistica.dat"

int main()
{
    //Se crean listas del tipo arrayList de manera dinamica
    ArrayList* usersList = al_newArrayList();
    ArrayList* songsList = al_newArrayList();
    ArrayList* reproductionsList = al_newArrayList();
    ArrayList* qtyArtistSongsList = al_newArrayList();

    if(usersList == NULL || songsList == NULL || reproductionsList == NULL || qtyArtistSongsList == NULL){
    	printf("\r\nEspacio en memoria insuficiente\n");
    	pause("\r\nPresione ENTER para salir\r\n");
    	return 0;
    }
    //Se crean variables auxiliares
    User *userAux;
    Song *songAux, *songAuxI;
    //Reproduction* repAux;
    Artist* artistAux;
    char nameAux[51], passAux[256];
    int idAux, idRepAux, idUsrAux;

    int i, j, flag = 0;
    int nameStrcmpRtr, passStrcmpRtr, strcmpSongArtistRtr;
    int qtyAux;

    //Cargamos el archivo de usuarios a la lista correspondiente
    if(file_parseUsers(ARCH_1, usersList) == -1){
    	printf("\r\nError cargando lista\n");
    	pause("\r\nPresione ENTER para volver al menu\r\n");
    }

    //Cargamos el archivo de temas a la lista correspondiente
	if(file_parseSongs(ARCH_2, songsList) == -1){
    	printf("\r\nError cargando lista\n");
    	pause("\r\nPresione ENTER para volver al menu\r\n");
    }
    //Cargamos el archivo de reproducciones a la lista correspondiente
    if(file_binToListRep(reproductionsList, ARCH_3) == -1){
    	printf("\r\nNo se ha creado el archivo de estadisticas, reproduzca una cancion para iniciarlo\n");
    	pause("\r\nPresione ENTER para continuar\r\n");
    }
    //Menu principal
 	int optionMenu = 0;
    while(optionMenu != 6){

    	optionMenu = optionMainMenu();

    	switch(optionMenu){

    		case 1://Lista de usuarios
			    //Ordenamos la lista por nombre y la imprimimos
			    printf("\r\n\n---------------------------------------------------------------------------------------------------------\
			    	        \n| LISTA DE USUARIOS ORDENADA POR NOMBRE:                                                                |\
			    	        \n---------------------------------------------------------------------------------------------------------\n\n");
			    usersList->sort(usersList,user_compareByName,1);
			    user_printArrayList(usersList);
			    pause("\r\nPresione ENTER para mostrar lista ordenada por pais y nombre\r\n");
			    //Ordenamos la lista por pais y nombre y la imprimimos
			    printf("\r\n\n---------------------------------------------------------------------------------------------------------\
			    	        \n| LISTA DE USUARIOS ORDENADA POR PAIS Y NOMBRE:                                                         |\
			    	        \n---------------------------------------------------------------------------------------------------------\n\n");
			    usersList->sort(usersList,user_compareByPaisName,1);
			    user_printArrayList(usersList);
			    pause("\r\nPresione ENTER para volver al menu principal\r\n");
    			break;

    		case 2:	//Lista de temas
			    //Ordenamos la lista por artista y titulo y la imprimimos
			    printf("\r\n\n--------------------------------------------------------------------------------------------------------------------\
			    	        \n| LISTA DE CANCIONES ORDENADA POR ARTISTA Y TITULO:                                                                |\
			    	        \n--------------------------------------------------------------------------------------------------------------------\n\n");
			    songsList->sort(songsList,song_compareByArtistTitle,1);
			    song_printArrayList(songsList);
			    pause("\r\nPresione ENTER para volver al menu principal\r\n");
    			break;

    		case 3://Escuchar tema
    			//Ingreso y validacion de usuario
    			printf("\r\n----------------------------------------------------------------\
    					  \n| INICIO DE CESION:                                            |\
                          \n----------------------------------------------------------------");
    			do {
    				//Se solicita nombre y clave de usuario
    				getValidString("\r\nIngrese su nombre de usuario: ","\r\nEl nombre deben ser solo letras\r\n",nameAux);
	    			capitalize(nameAux);
	    			getStringSpace("\r\nIngrese su clave de acceso: ",passAux);
	    			//Se recorre el la lista de usuarios buscando coincidencia
    				for(i = 0; i < usersList->len(usersList); i++){

	    				userAux = usersList->get(usersList, i);

	    				nameStrcmpRtr = strcmp(userAux->name,nameAux);
	    				passStrcmpRtr = strcmp(userAux->password,passAux);
	    				//Si lo encuentro salgo del for
	    				if(!nameStrcmpRtr && !passStrcmpRtr){
	    					break;
	    				}
	    			}
	    			//Si se recorrio toda la lista y no se encontro se informa y se vuelven a solicitar los datos
	    			if(nameStrcmpRtr != 0 || passStrcmpRtr != 0){
	    				printf("\r\nUsuario o clave incorrecta, vuelva a intentar\n");
	    			}
    			} while(nameStrcmpRtr != 0 || passStrcmpRtr != 0);
    			//Se muestran los datos del usuario ingresado
    			printf("\r\n--------------------------------------------------------------------------------------------------------------------\
    				      \n| INGRESO :   \
    				    \r\n--------------------------------------------------------------------------------------------------------------------\n");
    			user_print(userAux);
    			printf("\r\n--------------------------------------------------------------------------------------------------------------------");
    			//Se listan los temas para su seleccion
				printf("\r\n\n--------------------------------------------------------------------------------------------------------------------\
	    	                \n| LISTA DE TEMAS:                                                                                                  |\
	    	                \n--------------------------------------------------------------------------------------------------------------------\n\n");
				song_printArrayList(songsList);
				printf("\n------------------------------------------------------------------------------------------------------------------------\n");
				//Se solicita Id del tema a reproducir
				idAux = getValidInt("\r\nSeleccione una cancion por su Id: ","\r\nEl Id debe ser numerico\r\n",1,songsList->len(songsList));
				//Se recorre la lista de temas buscando coincidencia
				for(i = 0; i < songsList->len(songsList); i++){

					songAux = songsList->get(songsList,i);

					if(songAux->id == idAux){
						break;
					}
				}//for(i = 0; i < songsList->len(songsList); i++)
				//Se muestra el tema siendo reproducido
				printf("\r\n----------------------------------------------------------------\
					      \n| REPRODUCIENDO:                                               |\
					      \n----------------------------------------------------------------\
					      \n----------------------------------------------------------------\
					      \n| TITULO: %40s                                                 |\
					      \n----------------------------------------------------------------\
					      \n| ARTISTA: %40s                                                |\
					      \n----------------------------------------------------------------\n",\
					      songAux->title,songAux->artist);
				//Se agrega el id del tema y del usuario a la lista de reproducciones
				Reproduction* reproduccion = reproduction_new();

				idRepAux = reproductionsList->len(reproductionsList) + 1;
				idUsrAux = userAux->id;

				reproduction_setId(reproduccion,idRepAux,1);
				reproduction_setIdUser(reproduccion,idUsrAux,1);
				reproduction_setIdSong(reproduccion,idAux,1);

				reproductionsList->add(reproductionsList,reproduccion);

				reproduction_printArrayList(reproductionsList);
				pause("\r\nPresione ENTER para volver al menu principal\r\n");
    			break;

    		case 4: // Guardar estadistica
    			//Se carga la lista de reproducciones al archivo correspondiente
    			if(!file_listToBin(reproductionsList,ARCH_3)){

    				printf("\r\nEstadistica generada\n");
    				pause("\r\nPresione ENTER para volver al menu");
    			}
    			else {

    				printf("\r\nError. No se genero el archivo de estadistica\n");
    				pause("\r\nPresione ENTER para volver al menu");
    			}

    			break;

    		case 5: //Informes

    			printf("\r\n----------------------------------------------------------------\
    				      \n| INFORMES:                                                    |\
    				      \n----------------------------------------------------------------\n");

    			/*for(i = 0; i < reproductionsList->len(reproductionsList); i++){
    				repAux = reproductionsList->get(reproductionsList,i);
    				idSongRepAux = repAux->idSong;
    				for(j = i + 1; j < reproductionsList->len(reproductionsList); j++){

    					if(){}
    				}
    			}*/
    			
    			//Recorro la lista de canciones
    			for(i = 0; i < songsList->len(songsList); i++){
    				//Obtengo la primer cancion y su nombre a comparar
					songAuxI = songsList->get(songsList,i);
					strcpy(nameAux,songAuxI->artist);
					printf("\r\nNombre del artista a comparar: %s", nameAux);

					//Recorro la lista de cantidad de canciones de artistas
					for(j = 0; j < 200; j++){

						if(flag == 0){
    					
	    					Artist* artistNew = artist_new();
							idAux = qtyArtistSongsList->len(qtyArtistSongsList)+1;
							artist_setId(artistNew,idAux,1);
							artist_setName(artistNew,nameAux,1,256);
							artist_setQtySongs(artistNew,1,1);
							qtyArtistSongsList->add(qtyArtistSongsList,artistNew);
							printf("\r\nSe inicializa la lista de artistas con el primer elemento de la lista de canciones\r\n");
							artist_printArrayList(qtyArtistSongsList);
	    					flag = 1;
	    					//j--;
	    					break;
	    				}
						//Obtengo el primer artista de la lista
						artistAux = qtyArtistSongsList->get(qtyArtistSongsList,j);
						//Comparo el nombre del artista, de la lista de canciones,
						//con los nombres de la lista de catidad de canciones de artistas
						strcmpSongArtistRtr = strcmp(artistAux->name,nameAux);
						printf(" - Comparo con: %s", artistAux->name);
						//Si hay coincidencia
						if(!strcmpSongArtistRtr){
							//Aumento en uno la cantidad de canciones del artista y salgo del for
							qtyAux = artist_getQtySongs(artistAux);
							qtyAux++;
							artist_setQtySongs(artistAux,qtyAux,1);
							printf("\r\nCoincidencia, se aumenta en uno la cantidad de canciones del artista\r\n");
							artist_print(artistAux);
							break;
						}
					}

					//Si recorri toda la lista y no hubo coincidencia
					if(strcmpSongArtistRtr != 0){
						//agrego un nuevo elemento a la lista de catidad de canciones de artistas
						Artist* artistNew = artist_new();
						idAux = qtyArtistSongsList->len(qtyArtistSongsList)+1;
						artist_setId(artistNew,idAux,1);
						artist_setName(artistNew,nameAux,1,256);
						artist_setQtySongs(artistNew,1,1);
						qtyArtistSongsList->add(qtyArtistSongsList,artistNew);
						printf("\r\nNo hubo coincidencia, se agrega un elemento a la lista de artistas\r\n");
						artist_printArrayList(qtyArtistSongsList);
					}
				}
				pause("\r\nPresione ENTER para volver al menu");
    			break;

    		case 6: //Salir
    			continue;
    	}
    }
    free(usersList);
    free(songsList);
    free(reproductionsList);
    free(qtyArtistSongsList);
    return 0;
}
