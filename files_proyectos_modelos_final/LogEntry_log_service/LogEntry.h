
#ifndef __LogEntry
#define __LogEntry
struct{

    char date[11]; 
    char time[6]; 
    int serviceId; 
    int gravedad; 
    char msg[65];

}typedef LogEntry;
#endif // __LogEntry



/** \brief Allocate a new logEntry.
 * \param void
 * \return LogEntry* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new logEntry) if ok
 */
LogEntry* logEntry_new(void);


/** \brief Set pLogEntry LogEntry the msg recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \param msg (char*) Pointer to the msg recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int logEntry_setDate(LogEntry* pLogEntry, char* date, int lowLimit, int hiLimit);


/** \brief Set pLogEntry LogEntry the msg recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \param msg (char*) Pointer to the msg recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int logEntry_setTime(LogEntry* pLogEntry, char* time, int lowLimit, int hiLimit);


/** \brief Set pLogEntry LogEntry the id recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \param serviceId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int logEntry_setServiceId(LogEntry* pLogEntry, int serviceId, int lowLimit);


/** \brief Set pLogEntry LogEntry the id recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \param serviceId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int logEntry_setGravedad(LogEntry* pLogEntry, int gravedad, int lowLimit);



/** \brief Set pLogEntry LogEntry the msg recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \param msg (char*) Pointer to the msg recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int logEntry_setMsg(LogEntry* pLogEntry, char* msg, int lowLimit, int hiLimit);


/** \brief  Get the msg of the logEntry recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \return (int) Msg of the logEntry
 */
char* logEntry_getDate(LogEntry* pLogEntry);



/** \brief  Get the msg of the logEntry recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \return (int) Msg of the logEntry
 */
char* logEntry_getTime(LogEntry* pLogEntry);



/** \brief  Get the id of the logEntry recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \return (int) Id of the logEntry
 */
int logEntry_getServiceId(LogEntry* pLogEntry);


/** \brief  Get the gravedad of the logEntry recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \return (int) Gravedad of the logEntry
 */
int logEntry_getGravedad(LogEntry* pLogEntry);



/** \brief  Get the msg of the logEntry recived as parameter
 * \param pLogEntry (LogEntry*)* Pointer to the logEntry
 * \return (int) Msg of the logEntry
 */
char* logEntry_getMsg(LogEntry* pLogEntry);




/** \brief Shows the selected logEntry by screen
 * \param pLogEntry (LogEntry*) Pointer to the logEntry to be displayed
 * \return void
 */
void logEntry_print(LogEntry* pLogEntry);



/** \brief Shows all the logEntry in the list of logEntrys
 * \param logEntrysList (ArrayList*) Pointer to the list of logEntrys to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int logEntry_printArrayList(ArrayList* logEntrysList);



/** \brief Compare services by age
 * \param pServiceA (void*) Pointer to first service to compare
 * \param pServiceB (void*) Pointer to second service to compare
 * \return int Return (1) if age of pServiceA is major than age of pServiceB
 *                  - (-1) age of pServiceA is minor than age of pServiceB
 *                  - (0) age of pServiceA is equal than age of pServiceB
 */
int logEntry_compareByGravedad(void* pLogEntryA,void* pLogEntryB);


