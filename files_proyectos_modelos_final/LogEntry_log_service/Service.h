
#ifndef __Service
#define __Service
struct{

    int id;
    char name[33];
    char email[65];

}typedef Service;
#endif // __Service


/** \brief Allocate a new service.
 * \param void
 * \return Service* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new service) if ok
 */
Service* service_new(void);


/** \brief Set pService Service the id recived as parameter
 * \param pService (Service*)* Pointer to the service
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int service_setId(Service* pService, int id, int lowLimit);


/** \brief Set pService Service the name recived as parameter
 * \param pService (Service*)* Pointer to the service
 * \param name (char*) Pointer to the name recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid name]
 *                  - ( 0) if Ok
 */
int service_setName(Service* pService, char* name, int lowLimit, int hiLimit);


/** \brief Set pService Service the email recived as parameter
 * \param pService (Service*)* Pointer to the service
 * \param email (char*) Pointer to the email recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid email]
 *                  - ( 0) if Ok
 */
int service_setEmail(Service* pService, char* email, int lowLimit, int hiLimit);


/** \brief  Get the id of the service recived as parameter
 * \param pService (Service*)* Pointer to the service
 * \return (int) Id of the service
 */
int service_getId(Service* pService);


/** \brief  Get the name of the service recived as parameter
 * \param pService (Service*)* Pointer to the service
 * \return (char*) Name of the service
 */
char* service_getName(Service* pService);


/** \brief  Get the email of the service recived as parameter
 * \param pService (Service*)* Pointer to the service
 * \return (char*) Email of the service
 */
char* service_getEmail(Service* pService);


/** \brief Shows the selected service by screen
 * \param pService (Service*) Pointer to the service to be displayed
 * \return void
 */
void service_print(Service* pService);


/** \brief Shows all the service in the list of services
 * \param servicesList (ArrayList*) Pointer to the list of services to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int service_printArrayList(ArrayList* servicesList);


