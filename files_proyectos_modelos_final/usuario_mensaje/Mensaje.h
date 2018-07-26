
#ifndef __Mensaje
#define __Mensaje
struct{

    int mensajeId;
    int userId;
    int followers;
    char mensaje[9999];

}typedef Mensaje;
#endif // __Mensaje


/** \brief Allocate a new mensaje.
 * \param void
 * \return Mensaje* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new mensaje) if ok
 */
Mensaje* mensaje_new(void);


/** \brief Set pMensaje Mensaje the id recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \param mensajeId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int mensaje_setUserId(Mensaje* pMensaje, int userId, int lowLimit);


/** \brief Set pMensaje Mensaje the id recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \param mensajeId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int mensaje_setMensajeId(Mensaje* pMensaje, int mensajeId, int lowLimit);


/** \brief Set pMensaje Mensaje the mensaje recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \param mensaje (char*) Pointer to the mensaje recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int mensaje_setMensaje(Mensaje* pMensaje, char* mensaje, int lowLimit, int hiLimit);


/** \brief Set pMensaje Mensaje the followers recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \param followers (int) Followers recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid followers]
 *                  - ( 0) if Ok
 */
int mensaje_setFollowers(Mensaje* pMensaje, int followers, int lowLimit);



/** \brief  Get the id of the mensaje recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \return (int) Id of the mensaje
 */
int mensaje_getUserId(Mensaje* pMensaje);


/** \brief  Get the id of the mensaje recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \return (int) Id of the mensaje
 */
int mensaje_getMensajeId(Mensaje* pMensaje);



/** \brief  Get the mensaje of the mensaje recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \return (int) Mensaje of the mensaje
 */
char* mensaje_getMensaje(Mensaje* pMensaje);



/** \brief  Get the followers of the mensaje recived as parameter
 * \param pMensaje (Mensaje*)* Pointer to the mensaje
 * \return (int) Followers of the mensaje
 */
int mensaje_getFollowers(Mensaje* pMensaje);



/** \brief Shows the selected mensaje by screen
 * \param pMensaje (Mensaje*) Pointer to the mensaje to be displayed
 * \return void
 */
void mensaje_print(Mensaje* pMensaje);



/** \brief Shows all the mensaje in the list of mensajes
 * \param mensajesList (ArrayList*) Pointer to the list of mensajes to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int mensaje_printArrayList(ArrayList* mensajesList);


int mensaje_compareByFollowers(void* pMensajeA,void* pMensajeB);
