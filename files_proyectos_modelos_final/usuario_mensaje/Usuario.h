
#ifndef __Usuario
#define __Usuario
struct{

    int userId;
    char nick[51];
    int followers;

}typedef Usuario;
#endif // __Usuario



#define USER_INACTIVE  0
#define USER_ACTIVE  1



/** \brief Allocate a new user.
 * \param void
 * \return Usuario* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new user) if ok
 */
Usuario* user_new(void);



/** \brief Set pUsuario Usuario the id recived as parameter
 * \param pUsuario (Usuario*)* Pointer to the user
 * \param userId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int user_setId(Usuario* pUsuario, int userId, int lowLimit);



/** \brief Set pUsuario Usuario the nick recived as parameter
 * \param pUsuario (Usuario*)* Pointer to the user
 * \param nick (char*) Pointer to the nick recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int user_setNick(Usuario* pUsuario, char* nick, int lowLimit, int hiLimit);



/** \brief Set pUsuario Usuario the followers recived as parameter
 * \param pUsuario (Usuario*)* Pointer to the user
 * \param followers (int) Followers recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid followers]
 *                  - ( 0) if Ok
 */
int user_setFollowers(Usuario* pUsuario, int followers, int lowLimit);



/** \brief  Get the id of the user recived as parameter
 * \param pUsuario (Usuario*)* Pointer to the user
 * \return (int) Id of the user
 */
int user_getId(Usuario* pUsuario);



/** \brief  Get the nick of the user recived as parameter
 * \param pUsuario (Usuario*)* Pointer to the user
 * \return (int) Nick of the user
 */
char* user_getNick(Usuario* pUsuario);



/** \brief  Get the followers of the user recived as parameter
 * \param pUsuario (Usuario*)* Pointer to the user
 * \return (int) Followers of the user
 */
int user_getFollowers(Usuario* pUsuario);



/** \brief Shows the selected user by screen
 * \param pUsuario (Usuario*) Pointer to the user to be displayed
 * \return void
 */
void user_print(Usuario* pUsuario);



/** \brief Shows all the user in the list of users
 * \param usersList (ArrayList*) Pointer to the list of users to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int user_printArrayList(ArrayList* usersList);


int user_compareByFollowers(void* pUserA,void* pUserB);


