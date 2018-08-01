
#ifndef __Entrega
#define __Entrega
struct{

    int entregaId;
    char producto[51];
    char direccion[51];
    char localidad[51];
    char recibe[51];

}typedef Entrega;
#endif // __Entrega


/** \brief Allocate a new entrega.
 * \param void
 * \return Entrega* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new entrega) if ok
 */
Entrega* entrega_new(void);



/** \brief Set pEntrega Entrega the id recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param entregaId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setId(Entrega* pEntrega, int entregaId, int lowLimit);



/** \brief Set pEntrega Entrega the producto recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param producto (char*) Pointer to the producto recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setProduct(Entrega* pEntrega, char* producto, int lowLimit, int hiLimit);



/** \brief Set pEntrega Entrega the producto recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param producto (char*) Pointer to the producto recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setDireccion(Entrega* pEntrega, char* direccion, int lowLimit, int hiLimit);


/** \brief Set pEntrega Entrega the producto recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param producto (char*) Pointer to the producto recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setLocalidad(Entrega* pEntrega, char* localidad, int lowLimit, int hiLimit);



/** \brief Set pEntrega Entrega the producto recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \param producto (char*) Pointer to the producto recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int entrega_setRecibe(Entrega* pEntrega, char* recibe, int lowLimit, int hiLimit);




/** \brief  Get the id of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Id of the entrega
 */
int entrega_getId(Entrega* pEntrega);



/** \brief  Get the producto of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getProduct(Entrega* pEntrega);


/** \brief  Get the producto of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getDireccion(Entrega* pEntrega);


/** \brief  Get the producto of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getLocalidad(Entrega* pEntrega);


/** \brief  Get the producto of the entrega recived as parameter
 * \param pEntrega (Entrega*)* Pointer to the entrega
 * \return (int) Product of the entrega
 */
char* entrega_getRecibe(Entrega* pEntrega);



/** \brief Shows the selected entrega by screen
 * \param pEntrega (Entrega*) Pointer to the entrega to be displayed
 * \return void
 */
void entrega_print(Entrega* pEntrega);



/** \brief Shows all the entrega in the list of entregas
 * \param entregasList (ArrayList*) Pointer to the list of entregas to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int entrega_printArrayList(ArrayList* entregasList);


int entrega_compareByLocalidad(void* pEntregaA,void* pEntregaB);

void entrega_printLocalidad(Entrega* pEntrega);

int entrega_printLocalidadesList(ArrayList* entregasList);


