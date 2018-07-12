

#ifndef __Artist
#define __Artist
struct{

    int id;
    char name[256];
    int qtySongs;

}typedef Artist;
#endif // __Artist


/** \brief Allocate a new artist.
 * \param void
 * \return Artist* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new artist) if ok
 */
Artist* artist_new(void);


/** \brief Set pArtist Artist the id recived as parameter
 * \param pArtist (Artist*)* Pointer to the artist
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int artist_setId(Artist* pArtist, int id, int lowLimit);


/** \brief Set pArtist Artist the name recived as parameter
 * \param pArtist (Artist*)* Pointer to the artist
 * \param name (char*) Pointer to the name recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid name]
 *                  - ( 0) if Ok
 */
int artist_setName(Artist* pArtist, char* name, int lowLimit, int hiLimit);


/** \brief Set pArtist Artist the id recived as parameter
 * \param pArtist (Artist*)* Pointer to the artist
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int artist_setQtySongs(Artist* pArtist, int qty, int lowLimit);


/** \brief  Get the id of the artist recived as parameter
 * \param pArtist (Artist*)* Pointer to the artist
 * \return (int) Id of the artist
 */
int artist_getId(Artist* pArtist);


/** \brief  Get the name of the artist recived as parameter
 * \param pArtist (Artist*)* Pointer to the artist
 * \return (char*) Name of the artist
 */
char* artist_getName(Artist* pArtist);


/** \brief  Get the mail of the artist recived as parameter
 * \param pArtist (Artist*)* Pointer to the artist
 * \return (char*) Mail of the artist
 */
int artist_getQtySongs(Artist* pArtist);


/** \brief Shows the selected artist by screen
 * \param pArtist (Artist*) Pointer to the artist to be displayed
 * \return void
 */
void artist_print(Artist* pArtist);


/** \brief Shows all the artist in the list of artists
 * \param artistsList (ArrayList*) Pointer to the list of artists to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int artist_printArrayList(ArrayList* artistsList);



