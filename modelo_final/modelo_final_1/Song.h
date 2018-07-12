

#ifndef __Song
#define __Song
struct{

    int id;
    char title[256];
    char artist[256];
    
}typedef Song;
#endif // __Song


/** \brief Allocate a new song.
 * \param void
 * \return Song* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new song) if ok
 */
Song* song_new(void);


/** \brief Request a name to the song, validate that it is only letters and capitalize it
 * \param input (char*) Pointer to the string of characters where the entered name will be stored
 * \return void
 */
void song_askName(char* input);


/** \brief Set pSong Song the id recived as parameter
 * \param pSong (Song*)* Pointer to the song
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int song_setId(Song* pSong, int id, int lowLimit);


/** \brief Set pSong Song the name recived as parameter
 * \param pSong (Song*)* Pointer to the song
 * \param name (char*) Pointer to the name recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid name]
 *                  - ( 0) if Ok
 */
int song_setTitle(Song* pSong, char* title, int lowLimit, int hiLimit);


/** \brief Set pSong Song the mail recived as parameter
 * \param pSong (Song*)* Pointer to the song
 * \param mail (char*) Pointer to the mail recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid mail]
 *                  - ( 0) if Ok
 */
int song_setArtist(Song* pSong, char* artist, int lowLimit, int hiLimit);


/** \brief  Get the id of the song recived as parameter
 * \param pSong (Song*)* Pointer to the song
 * \return (int) Id of the song
 */
int song_getId(Song* pSong);


/** \brief  Get the name of the song recived as parameter
 * \param pSong (Song*)* Pointer to the song
 * \return (char*) Name of the song
 */
char* song_getTitle(Song* pSong);


/** \brief  Get the mail of the song recived as parameter
 * \param pSong (Song*)* Pointer to the song
 * \return (char*) Mail of the song
 */
char* song_getArtist(Song* pSong);


int song_compareByArtist(void* pSongA,void* pSongB);


/** \brief Compare songs by mail
 * \param pSongA (void*) Pointer to first song to compare
 * \param pSongB (void*) Pointer to second song to compare
 * \return int Return (1) if mail of pSongA is major than mail of pSongB
 *                  - (-1) mail of pSongA is minor than mail of pSongB
 *                  - (0) mail of pSongA is equal than mail of pSongB
 */
int song_compareByArtistTitle(void* pSongA,void* pSongB);


/** \brief Shows the selected song by screen
 * \param pSong (Song*) Pointer to the song to be displayed
 * \return void
 */
void song_print(Song* pSong);


/** \brief Shows all the song in the list of songs
 * \param songsList (ArrayList*) Pointer to the list of songs to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int song_printArrayList(ArrayList* songsList);


/** \brief Request, validate an Id and look in the list, passed as an argument, the element with that value.
 * \param songsList (ArrayList*) Pointer to the list
 * \return (Song*) Return (NULL) the id is not found and you do not want to continue the search
 *                        - (pointer to the found element) if ok
 */
Song *song_requestValidId(ArrayList* songsList);



