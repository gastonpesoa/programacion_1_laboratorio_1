
#define OBJECT_INACTIVE  0
#define OBJECT_ACTIVE  1

#ifndef __Object
#define __Object
struct{

    int id;
    char name[51];
    char mail[256];
    int age;
    int status;

}typedef Object;
#endif // __Object


/** \brief Hardcode of data testing of objects in a objects list recived as parameter.
 * \param objectsList (ArrayList*) Pointer to the list of objects to be hardcode
 * \return (void)
 */
void object_testing(ArrayList* objectsList);


/** \brief Allocate and set a new object with the values recived as parameters
 * \param id (int)
 * \param name (char*)
 * \param mail (char*)
 * \param age (int)
 * \return Object* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new object) if ok
 */
Object* object_newTest(int id, char* name,char* mail,int age);


/** \brief Allocate a new object.
 * \param void
 * \return Object* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new object) if ok
 */
Object* object_new(void);

/** \brief Requests, validates, set all the values ​​of a new object and add it to the list passed as a parameter
 * \param objectsList (ArrayList*) Pointer to the list of objects
 * \param lowLimitId (int) Lower id limit allowed
 * \param hiLimitId (int) Higher id limit allowed
 * \param lowLimitName (int) Lower name limit allowed
 * \param hiLimitName (int) Higher name limit allowed
 * \param lowLimitMail (int) Lower mail limit allowed
 * \param hiLimitMail (int) Higher mail limit allowed
 * \param lowLimitAge (int) Lower age limit allowed
 * \param hiLimitAge (int) Higher age limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int object_enter(ArrayList* objectsList,int lowLimitId,int hiLimitId,\
    int lowLimitName,int hiLimitName,\
    int lowLimitMail,int hiLimitMail,int lowLimitAge,int hiLimitAge);


/** \brief Request a name to the object, validate that it is only letters and capitalize it
 * \param input (char*) Pointer to the string of characters where the entered name will be stored
 * \return void
 */
void object_askName(char* input);


/** \brief Request a mail to the object
 * \param input (char*) Pointer to the string of characters where the entered mail will be stored
 * \return void
 */
void object_askMail(char *input);


/** \brief Request a age to the object, validate that it is only integer numbers and between the assigned range
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return (int) Age of the object
 */
int object_askAge(int lowLimit, int hiLimit);


/** \brief Set pObject Object the id recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int object_setId(Object* pObject, int id, int lowLimit, int hiLimit);


/** \brief Set pObject Object the name recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \param name (char*) Pointer to the name recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid name]
 *                  - ( 0) if Ok
 */
int object_setName(Object* pObject, char* name, int lowLimit, int hiLimit);


/** \brief Set pObject Object the mail recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \param mail (char*) Pointer to the mail recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid mail]
 *                  - ( 0) if Ok
 */
int object_setMail(Object* pObject, char* mail, int lowLimit, int hiLimit);


/** \brief Set pObject Object the age recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \param age (int) Age recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int object_setAge(Object* pObject, int age, int lowLimit, int hiLimit);


/** \brief Set pObject Object the status recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \param status (int) Status recived
 * \return (void)
 */
void object_setStatus(Object* pObject, int status);


/** \brief  Get the id of the object recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \return (int) Id of the object
 */
int object_getId(Object* pObject);


/** \brief  Get the name of the object recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \return (char*) Name of the object
 */
char* object_getName(Object* pObject);


/** \brief  Get the mail of the object recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \return (char*) Mail of the object
 */
char* object_getMail(Object* pObject);


/** \brief  Get the age of the object recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \return (int) Age of the object
 */
int object_getAge(Object* pObject);


/** \brief  Get the status of the object recived as parameter
 * \param pObject (Object*)* Pointer to the object
 * \return (int) Status of the object
 */
int object_getStatus(Object* pObject);


/** \brief Compare objects by name
 * \param pObjectA (void*) Pointer to first object to compare
 * \param pObjectB (void*) Pointer to second object to compare
 * \return int Return (1) if name of pObjectA is major than name of pObjectB
 *                  - (-1) name of pObjectA is minor than name of pObjectB
 *                  - (0) name of pObjectA is equal than name of pObjectB
 */
int object_compareByName(void* pObjectA,void* pObjectB);


/** \brief Compare objects by mail
 * \param pObjectA (void*) Pointer to first object to compare
 * \param pObjectB (void*) Pointer to second object to compare
 * \return int Return (1) if mail of pObjectA is major than mail of pObjectB
 *                  - (-1) mail of pObjectA is minor than mail of pObjectB
 *                  - (0) mail of pObjectA is equal than mail of pObjectB
 */
int object_compareByMail(void* pObjectA,void* pObjectB);


/** \brief Compare objects by age
 * \param pObjectA (void*) Pointer to first object to compare
 * \param pObjectB (void*) Pointer to second object to compare
 * \return int Return (1) if age of pObjectA is major than age of pObjectB
 *                  - (-1) age of pObjectA is minor than age of pObjectB
 *                  - (0) age of pObjectA is equal than age of pObjectB
 */
int object_compareByAge(void* pObjectA,void* pObjectB);


/** \brief Shows the selected object by screen
 * \param pObject (Object*) Pointer to the object to be displayed
 * \return void
 */
void object_print(Object* pObject);


/** \brief Shows all the object in the list of objects
 * \param objectsList (ArrayList*) Pointer to the list of objects to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int object_printArrayList(ArrayList* objectsList);


/** \brief Low logic of the object received as parameter
 * \param pObject (Object*) Pointer to the object to be deleted
 * \return void
 */
void object_delete(Object* pObject);


/** \brief Returns an array with the elements that are not found in blackList
 * \param destList (ArrayList*) Pointer to the list to be refined
 * \param blackList (ArrayList*) Pointer to the list with the elements to be removed from destList
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                   - (pointer to new arrayList) if ok
 */
ArrayList* listDebugger(ArrayList* destList, ArrayList* blackList);

