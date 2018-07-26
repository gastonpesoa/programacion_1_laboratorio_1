
#ifndef __Reproduction
#define __Reproduction
struct{

	int idReproduction;
    int idUser;
    int idSong;

}typedef Reproduction;
#endif // __Reproduction



/** \brief Allocate a new reproduction.
 * \param void
 * \return Reproduction* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new reproduction) if ok
 */
Reproduction* reproduction_new(void);


/** \brief Set pReproduction Reproduction the id recived as parameter
 * \param pReproduction (Reproduction*)* Pointer to the reproduction
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int reproduction_setId(Reproduction* pReproduction, int id, int lowLimit);


int reproduction_setIdUser(Reproduction* pReproduction, int idUser, int lowLimit);


int reproduction_setIdSong(Reproduction* pReproduction, int idSong, int lowLimit);


/** \brief  Get the id of the reproduction recived as parameter
 * \param pReproduction (Reproduction*)* Pointer to the reproduction
 * \return (int) Id of the reproduction
 */
int reproduction_getId(Reproduction* pReproduction);


int reproduction_getIdUser(Reproduction* pReproduction);


int reproduction_getIdSong(Reproduction* pReproduction);


/** \brief Shows the selected reproduction by screen
 * \param pReproduction (Reproduction*) Pointer to the reproduction to be displayed
 * \return void
 */
void reproduction_print(Reproduction* pReproduction);


/** \brief Shows all the reproduction in the list of reproductions
 * \param reproductionsList (ArrayList*) Pointer to the list of reproductions to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int reproduction_printArrayList(ArrayList* reproductionsList);


/** \brief Request, validate an Id and look in the list, passed as an argument, the element with that value.
 * \param reproductionsList (ArrayList*) Pointer to the list
 * \return (Reproduction*) Return (NULL) the id is not found and you do not want to continue the search
 *                        - (pointer to the found element) if ok
 */
Reproduction *reproduction_requestValidId(ArrayList* reproductionsList);



