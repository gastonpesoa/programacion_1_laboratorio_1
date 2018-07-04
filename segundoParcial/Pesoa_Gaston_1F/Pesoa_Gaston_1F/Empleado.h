#include "ArrayList.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;


/** \brief Calculate the field 'sueldo' of the element passes as argument in function of the hours works
 * \param p (void*) Pointer to the object to charge
 * \return int Return -
 */
void em_calcularSueldo(void* p);


/** \brief Allocate a new object.
 * \param void
 * \return Empleado* Return (NULL) if Error [if can't allocate memory]
 *                        - (pointer to new object) if ok
 */
Empleado* em_new(void);


/** \brief Set pEmpleado Empleado the id recived as parameter
 * \param pEmpleado (Empleado*)* Pointer to the object
 * \param id (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int em_setId(Empleado* pEmpleado, int id, int lowLimit);


/** \brief Set pEmpleado Empleado the name recived as parameter
 * \param pEmpleado (Empleado*)* Pointer to the object
 * \param name (char*) Pointer to the name recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid name]
 *                  - ( 0) if Ok
 */
int em_setName(Empleado* pEmpleado, char* name, int lowLimit, int hiLimit);


/** \brief Set pEmpleado Empleado the hs recived as parameter
 * \param pEmpleado (Empleado*)* Pointer to the object
 * \param horasTrabajadas (int) Hs recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int em_setHs(Empleado* pEmpleado, int horasTrabajadas, int lowLimit);


/** \brief Set pEmpleado Empleado the sueldo recived as parameter
 * \param pEmpleado (Empleado*)* Pointer to the object
 * \param sueldo (int) Sueldo recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int em_setSueldo(Empleado* pEmpleado, int sueldo, int lowLimit);


/** \brief  Get the id of the object recived as parameter
 * \param pEmpleado (Empleado*)* Pointer to the object
 * \return (int) Id of the object
 */
int em_getId(Empleado* pEmpleado);


/** \brief  Get the name of the object recived as parameter
 * \param pEmpleado (Empleado*) Pointer to the object
 * \return (char*) Name of the object
 */
char* em_getName(Empleado* pEmpleado);


/** \brief  Get the hs worked of the object recived as parameter
 * \param pEmpleado (Empleado*) Pointer to the object
 * \return (int) Hs worked of the object
 */
int em_getHs(Empleado* pEmpleado);


/** \brief  Get the sueldo of the object recived as parameter
 * \param pEmpleado (Empleado*) Pointer to the object
 * \return (int) Sueldo of the object
 */
int em_getSueldo(Empleado* pEmpleado);


/** \brief Shows the selected object by screen
 * \param pEmpleado (Empleado*) Pointer to the object to be displayed
 * \return void
 */
void em_print(Empleado* pEmpleado);


/** \brief Shows all the object in the list
 * \param empList (ArrayList*) Pointer to the list of objects to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int em_printArrayList(ArrayList* empList);

#endif // EMPLEADO_H_INCLUDED
