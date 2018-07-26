
/** \brief Open a file for reading, analyze it, load structs with the data readed and
 * \add the new element to a list
 * \param pFile (FILE*) Pointer to file
 * \param usersList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be read
 * \return (ArrayList*) Return (-1) if Error [can't open file, doesn't exists, can't added to the list or read file]
 *                           - (0) if ok
 */
int parserUsuariosListFile(FILE *pFile , ArrayList *usersList, char *fileName);


int parserMensajesListFile(FILE *pFile , ArrayList *mensajesList, char *fileName);


/** \brief Open a text file for writing and write the objects list passed as argument in it
 * \param pFile (FILE*) Pointer to file
 * \param usersList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be written
 * \return int Return (-1) if Error [can't open file or write it]
 * \				- (0) if Ok
 */
int usersListToFile(FILE *pFile, ArrayList *usersList, char *fileName);
