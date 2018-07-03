

/** \brief Open a text file for writing and write the text passed as argument
 * \param ptrFile (FILE*) Pointer to file
 * \param fileName (char *) Name of the file to be written
 * \param textToWrite (char *) Text to be written
 * \return int Return (-1) if Error [can't open file or write it] - (0) if Ok
 */
int file_writeText(FILE *pFile, char *fileName, char *textToWrite);


/** \brief Open a text file for reading and store the read text in the string passed as argument
 * \param ptrFile (FILE*) Pointer to file
 * \param fileName (char *) Name of the file to be read
 * \param readText (char *) String where the read text will be stored
 * \return int Return (-1) if Error [can't open file or read it] - (0) if Ok
 */
int file_readText(FILE *pFile, char *fileName, char *readText);


/** \brief Open a file for reading, analyze it, load structs with the data readed and add the new element to a list
 * \param pFile (FILE*) Pointer to file
 * \param fileName (char *) Name of the file to be read
 * \return (ArrayList*) Return (NULL) if Error [can't open file, doesn't exists, can't added to the list or read file] 
 *                           - (pointer to new arrayList) if ok
 */
ArrayList *file_parserText(FILE *pFile, char *fileName);


/** \brief Open a text file for writing and write the objects list passed as argument in it
 * \param ptrFile (FILE*) Pointer to file
 * \param personsList (ArrayList*) Pointer to arrayList
 * \param fileName (char *) Name of the file to be written
 * \return int Return (-1) if Error [can't open file or write it] - (0) if Ok
 */
int file_listToText(FILE* pFile, ArrayList* list, char *fileName);


/** \brief Open a binary file for writing and write the objects list passed as argument in it
 * \param ptrFile (FILE*) Pointer to file
 * \param personsList (ArrayList*) Pointer to arrayList
 * \param fileName (char *) Name of the file to be written
 * \return int Return (-1) if Error [can't open file or write it] - (0) if Ok
 */
int file_listToBin(FILE *pFile, ArrayList *objectsList, char *fileName);


/** \brief Open a binary file for reading, load structs with the data readed and add the new elements to a list
 * \param ptrFile (FILE*) Pointer to file
 * \param fileName (char *) Name of the file to be read
 * \return (ArrayList*) Return (NULL) if Error [can't open file, doesn't exists, can't added to the list or read file] 
 *                           - (pointer to new arrayList) if ok
 */
ArrayList *file_binToList(FILE *pFile, char *fileName);


/** \brief Open a binary file and request an Id for modify in the file the object with this number
 * \param ptrFile (FILE*) Pointer to file
 * \param objectsList (ArrayList*) Pointer to arrayList
 * \param fileName (char *) Name of the file to be modify
 * \return int Return (-1) if Error [can't open file, doesn't exists, can't modify the file or read it] 
 *					 - (1) if Ok but not modificated
 *					 - (0) if Ok and modificated
 */
int file_modifyInBin(FILE *pFile, ArrayList* objectsList, char *fileName);


/** \brief Open a binary file and modify in it the object passed as argument
 * \param ptrFile (FILE*) Pointer to file
 * \param pObject (Object*)* Pointer to the object
 * \param fileName (char *) Name of the file to be modify
 * \return int Return (-1) if Error [can't open file, doesn't exists, can't modify the file or read it]
 *					 - (1) if Ok but not modificated
 *					 - (0) if Ok and modificated 
 */
int file_modifyObjectFromBin(FILE *pFile, Object* pObject, char *fileName);


/** \brief Open a binary file, set the state of the object passed as an argument as inactive and save it
 * \param ptrFile (FILE*) Pointer to file
 * \param pObject (Object*)* Pointer to the object
 * \param fileName (char *) Name of the file to be modify
 * \return int Return (-1) if Error [can't open file, doesn't exists, can't logical low logic the file or read it]
 *					 - (1) if Ok but not logical low logic
 *					 - (0) if Ok and logical low logic 
 */
int file_logicRemove(FILE *pFile, Object* pObject, char *fileName);

