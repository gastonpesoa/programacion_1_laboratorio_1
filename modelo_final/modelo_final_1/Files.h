

/** \brief Open a binary file for writing and write the users list passed as argument in it
 * \param ptrFile (FILE*) Pointer to file
 * \param personsList (ArrayList*) Pointer to arrayList
 * \param fileName (char *) Name of the file to be written
 * \return int Return (-1) if Error [can't open file or write it] - (0) if Ok
 */
int file_listToBin(ArrayList *usersList, char *fileName);


/** \brief Open a binary file for reading, load structs with the data readed and add the new elements to a list
 * \param ptrFile (FILE*) Pointer to file
 * \param fileName (char *) Name of the file to be read
 * \return (ArrayList*) Return (NULL) if Error [can't open file, doesn't exists, can't added to the list or read file]
 *                           - (pointer to new arrayList) if ok
 */
int file_binToListSongs(ArrayList* list, char *fileName);

int file_parseUsers(char* fileName, ArrayList* listaUsers);


int file_parseSongs(char* fileName, ArrayList* listaSongs);


int file_binToListRep(ArrayList* listRep, char *fileName);	