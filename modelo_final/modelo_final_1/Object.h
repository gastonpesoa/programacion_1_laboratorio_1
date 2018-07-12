

#ifndef __User
#define __User

struct{

    int id;
    char name[256];
    char mail[256];
    char sexo[256];
    char pais[256];
    char password[256];
    char ip[256];

}typedef User;

#endif // __User


/** \brief Allocate a new user.
 * \param void
 * \return User* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new user) if ok
 */
User* user_new(void);


void user_askName(char *input);


void user_askPassword(char *input);


/** \brief Set pUser User the id recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int user_setId(User* pUser, int id, int lowLimit);


/** \brief Set pUser User the name recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \param name (char*) Pointer to the name recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid name]
 *                  - ( 0) if Ok
 */
int user_setName(User* pUser, char* name, int lowLimit, int hiLimit);


/** \brief Set pUser User the mail recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \param mail (char*) Pointer to the mail recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid mail]
 *                  - ( 0) if Ok
 */
int user_setMail(User* pUser, char* mail, int lowLimit, int hiLimit);


/** \brief Set pUser User the age recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \param age (int) Age recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int user_setSex(User* pUser, char* sexo, int lowLimit, int hiLimit);


int user_setPais(User* pUser, char* pais, int lowLimit, int hiLimit);

int user_setPassword(User* pUser, char* password, int lowLimit, int hiLimit);

int user_setIp(User* pUser, char* ip, int lowLimit, int hiLimit);


/** \brief  Get the id of the user recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \return (int) Id of the user
 */
int user_getId(User* pUser);


/** \brief  Get the name of the user recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \return (char*) Name of the user
 */
char* user_getName(User* pUser);


/** \brief  Get the mail of the user recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \return (char*) Mail of the user
 */
char* user_getMail(User* pUser);


/** \brief  Get the age of the user recived as parameter
 * \param pUser (User*)* Pointer to the user
 * \return (int) Age of the user
 */
char* user_getSex(User* pUser);


char* user_getPais(User* pUser);


char* user_getPassword(User* pUser);


char* user_getIp(User* pUser);


/** \brief Compare users by name
 * \param pUserA (void*) Pointer to first user to compare
 * \param pUserB (void*) Pointer to second user to compare
 * \return int Return (1) if name of pUserA is major than name of pUserB
 *                  - (-1) name of pUserA is minor than name of pUserB
 *                  - (0) name of pUserA is equal than name of pUserB
 */
int user_compareByName(void* pUserA,void* pUserB);


int user_compareByPaisName(void* pUserA,void* pUserB);


/** \brief Shows the selected user by screen
 * \param pUser (User*) Pointer to the user to be displayed
 * \return void
 */
void user_print(User* pUser);


/** \brief Shows all the user in the list of users
 * \param usersList (ArrayList*) Pointer to the list of users to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int user_printArrayList(ArrayList* usersList);


/** \brief Request, validate an Id and look in the list, passed as an argument, the element with that value.
 * \param usersList (ArrayList*) Pointer to the list
 * \return (User*) Return (NULL) the id is not found and you do not want to continue the search
 *                        - (pointer to the found element) if ok
 */
User *user_requestValidId(ArrayList* usersList);


