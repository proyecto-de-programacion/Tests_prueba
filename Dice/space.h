/**
 * @brief It defines a space
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */


 /**
  *  @brief  It defines a space
  *
  *  We modified the defined functions
  *
  *  @file space.h
  *  @version 1.5
  *  @date 17/02/2019
  *  @authors Alonso Aquino Ciro, Conache Alexandr
  */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

/**
 * Definition of constant values
 */
#define MAX_SPACES 100
#define FIRST_SPACE 0
#define MAX_OBJECTS 4
#define ROWS 3
#define COLUMNS 8

/**
 * Definition of data structures
 */
typedef struct _Space Space;

/**
 *  Delcaration of public functions
 */


/* It creates a space */
Space* space_create(Id id);

/* It destroyes the memory allocated to the prviously created space, thus destroying it */
STATUS space_destroy(Space* space);

/* It returns the space's id */
Id space_get_id(Space* space);

/* It assigns a name to the space */
STATUS space_set_name(Space* space, char* name);

/* It returns the name assigned to the space */
const char* space_get_name(Space* space);

/* It assigns the space another space in the north direction */
STATUS space_set_north(Space* space, Id id);

/* It returns wether the space has another linked north of it */
Id space_get_north(Space* space);

/* It assigns the space another space in the south direction */
STATUS space_set_south(Space* space, Id id);

/* It returns wether the space has another linked south of it */
Id space_get_south(Space* space);

/* It assigns the space another space in the east direction */
STATUS space_set_east(Space* space, Id id);

/* It returns wether the space has another linked east of it */
Id space_get_east(Space* space);

/* It assigns the space another space in the west direction */
STATUS space_set_west(Space* space, Id id);

/* It returns wether the space has another linked west of it */
Id space_get_west(Space* space);

/* Makes sure the space exists and assign it an object */
STATUS space_set_object(Space* space, Id id);

/* It deletes the object form set if is in there returns OK if done, else ERROR  */
STATUS space_get_object(Space* space, Id id);

/* It prints the space on screen */
STATUS space_print(Space* space);


/* Returns true if the object you ask is in the space, false if everythings else   */
BOOL space_object_is_in(Space* space, Id id);


STATUS space_set_gdesc(Space* space, char *string, int i);

char* space_get_gdesc1(Space* space);
char* space_get_gdesc2(Space* space);
char* space_get_gdesc3(Space* space);



#endif
