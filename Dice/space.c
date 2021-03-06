/**
 *  @brief An implementation to use 'space' data type
 *
 *  Here all functions related to 'space' data types are implemented as well as the structure Object
 *
 *  @file space.c
 *  @version 1.0
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

/**
 *   @brief Space structure
 *
 *   Stores relevant information about the space the game is held in
 *
 */

struct _Space {
  Id id;                      /*!< The ID the space has assigned */
  char name[WORD_SIZE + 1];   /*!< The name we can assign to the space */
  Id north;                   /*!< The upper part of the space */
  Id south;                   /*!< The downwards part of the space */
  Id east;                    /*!< The right part of the space */
  Id west;                    /*!< The left part of te space */
  Set *objects;               /*!< What object iss currently on the space */
  char gdesc[ROWS][COLUMNS];             /*!< campo gdesc*/
};


/**
 *  @brief Creates the space
 *
 *  space_create Reserves enough memory to create the space
 *                it assigns it an id, a name, whether it has any other space adjacent,
 *                and initialize the new objects , as well as making sure everything is working
 *                properly
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param id is the id the space has assigned and will be used to identify it
 *
 */

Space* space_create(Id id) {
  Space *newSpace = NULL;
  int i = 0;
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));

  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->objects = set_create();
 
  for( i = 0; i < ROWS; i++){
    newSpace->gdesc[i][0] = '\0';
  }

  return newSpace;
}

/**
 *  @brief Destroys the space by freeing the allocated memory
 *
 *  space_destroy Frees the memory we reserved with the function space_create
 *                 it also assigns it a NULL value to tie up loose ends
 *                 furthermore it has a control code to prevent possible
 *                 errors
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space the space created that's going to be destroyed
 *
 */



STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }
  set_destroy(space->objects);
  free(space);
  space=NULL;

  return OK;
}

/**
 *  @brief Assigns a name to the space
 *
 *  space_set_name Gives the space a name to differentiate it
 *                  from another space
 *
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param name is the name we're going to assign to the space
 */

STATUS space_set_name(Space* space, char* name) {

  /* This code makes sure a player exists and if it does it has a name */

  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}


/**
 * @brief Links the space to another in the north direction
 *
 *  space_set_north Asks the Space structure if the space exists and if so it links it
 *                 to another space in the north direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 */

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

/**
 * @brief Links the space to another in the south direction
 *
 *  space_set_south Asks the Space structure if the space exists and if so it links it
 *                 to another space in the south direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 */


STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}



/**
 * @brief Links the space to another in the east direction
 *
 *  space_set_east Asks the Space structure if the space exists and if so it links it
 *                 to another space in the east direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 */


STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

/**
 * @brief Links the space to another in the west direction
 *
 *  space_set_west Asks the Space structure if the space exists and if so it links it
 *                 to another space in the west direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 */

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

/**
 *  @brief Assigns an object to the space
 *
 *  space_set_object Makes sure the space exists and it assigns it an object
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param Id is identification of the object
 *  @param space is the space we created
 *  @param value is the value the space has to confirm the object's exsistence and it's either a TRUE or a FALSE
 */

STATUS space_set_object(Space* space, Id id) {
  
  if (!space || id == NO_ID) {
    return ERROR;
  }
  
  return set_add(space->objects,id);
}

/**
 *  @brief Gets the space's name
 *
 *  space_get_name Is a constant function so it can't be changed.
 *                  Makes sure space exists and gets/returns it's assigned name
 *
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param name is the space's name
 */


const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

/**
 *  @brief Returns the space's id
 *
 *  space_get_id    Is a function that assesses whether the space exists and
 *                  it calls the space's structure to get its id
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 */


Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

/**
 * @brief Returns the space in the north of the box we're inquiring about
 *
 *  space_get_north Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its north direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 */

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

/**
 * @brief Returns the space in the south of the box we're inquiring about
 *
 *  space_get_south Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its south direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 */

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

/**
 * @brief Returns the space in the east of the box we're inquiring about
 *
 *  space_get_east Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its east direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 */

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}


/**
 * @brief Returns the space in the west of the box we're inquiring about
 *
 *  space_get_west Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its west direction
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 */

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

/**
 *  @brief Confirms the space has an object
 *
 *  space_get_object  The function checks if the object is in the set structure
 *   deletes it from the structure and returns OK if done correctly 
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 */
STATUS space_get_object(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  if(set_Id_inArray(space->objects, id)==TRUE){
    set_del(space->objects, id);
    return OK;
  }
  
  return ERROR;  
}


/**
 *  @brief Prints the space on screen
 *
 *  space_print    Is a simple function that prints the space on screen with
 *                 its name and id after making sure it exists. It also prints on
 *                 screen wether the space is where it's supposed to be and if it has
 *                 other spaces or boxes in each direction (n,s,e,w)
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 *  @param name is the space's name
 *  @param idaux is and auxiliary Id variable that helps simplify the code when asking about the adjacent spaces
 *  @param object is the object we created and we check if it's in the space or not
 */
STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }
  /* Me he cargado el print de los objects*/
  return OK;
}


STATUS space_set_gdesc(Space* space, char *string, int i) {
  
  if ((!space) ||(!string)) {
    return ERROR;
  }
  
  strncpy(space->gdesc[i],string,COLUMNS-1);

  
  return OK;
}

char* space_get_gdesc1(Space* space) {
  if (!space) {
    return ERROR;
  }
  return space->gdesc[0];
}

char* space_get_gdesc2(Space* space) {
  if (!space) {
    return ERROR;
  }
  return space->gdesc[1];
}

char* space_get_gdesc3(Space* space) {
  if (!space) {
    return ERROR;
  }
  return space->gdesc[2];
}


/*  Returns True if the object is in the space, false if everything else  */
BOOL space_object_is_in(Space* space, Id id){
  if(!space ){
    return FALSE;
  }
  if(set_Id_inArray(space->objects, id) == TRUE){
    return TRUE;
  }
  return FALSE;
}

