
#ifndef __Person
#define __Person
struct{

    char name[51];
    char mail[256];

}typedef Person;
#endif // __Person



/** \brief Allocate a new person.
 * \param void
 * \return Person* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new person) if ok
 */
Person* person_new(void);


/** \brief Set pPerson Person the name recived as parameter
 * \param pPerson (Person*)* Pointer to the person
 * \param name (char*) Pointer to the name recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int person_setName(Person* pPerson, char* name, int lowLimit, int hiLimit);


/** \brief Set pPerson Person the mail recived as parameter
 * \param pPerson (Person*)* Pointer to the person
 * \param name (char*) Pointer to the mail recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int person_setMail(Person* pPerson, char* mail, int lowLimit, int hiLimit);


/** \brief  Get the name of the person recived as parameter
 * \param pPerson (Person*)* Pointer to the person
 * \return (int) Id of the person
 */
char* person_getName(Person* pPerson);


/** \brief  Get the mail of the person recived as parameter
 * \param pPerson (Person*)* Pointer to the person
 * \return (char*) Name of the person
 */
char* person_getMail(Person* pPerson);


/** \brief Compare persons by name
 * \param pPersonA (void*) Pointer to first person to compare
 * \param pPersonB (void*) Pointer to second person to compare
 * \return int Return (1) if name of pPersonA is major than name of pPersonB
 *                  - (-1) name of pPersonA is minor than name of pPersonB
 *                  - (0) name of pPersonA is equal than name of pPersonB
 */
int person_compareByName(void* pPersonA,void* pPersonB);


/** \brief Shows the selected person by screen
 * \param pPerson (Person*) Pointer to the person to be displayed
 * \return void
 */
void person_print(Person* pPerson);


/** \brief Shows all the person in the list of persons
 * \param pPerson (Person*) Pointer to the person
 * \param personsList (ArrayList*) Pointer to the list of persons to be displayed
 * \return void
 */
void person_printAll(Person* pPerson,ArrayList* personsList);
