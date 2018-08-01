
/** \brief Open a file for reading, analyze it, load structs with the data readed and
 * \add the new element to a list
 * \param pFile (FILE*) Pointer to file
 * \param entregasList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be read
 * \return (ArrayList*) Return (-1) if Error [can't open file, doesn't exists, can't added to the list or read file]
 *                           - (0) if ok
 */
int parserEntregasListFile(FILE* pFile , ArrayList* entregasList, char* fileName);


/** \brief Open a text file for writing and write the objects list passed as argument in it
 * \param pFile (FILE*) Pointer to file
 * \param entregasList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be written
 * \return int Return (-1) if Error [can't open file or write it]
 * \				- (0) if Ok
 */
int entregasListToFile(FILE *pFile, ArrayList *entregasList, char *fileName);
