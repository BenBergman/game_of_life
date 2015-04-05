#ifndef _COORDS_H_
#define _COORDS_H_

#include "coord.h"

#define COORDS_SIZE 10

/* TODO: hide the details in the src file, like TDDFEC 225 */
typedef struct {
	int count;
	int index;
	Coord list[COORDS_SIZE];
} CoordsStruct;

typedef CoordsStruct * Coords;

Coords Coords_Create(void);
void Coords_Destroy(Coords);
Coord Coords_First(Coords);
Coord Coords_Next(Coords);
int Coords_Count(Coords);
void Coords_Add(Coords, Coord);

#endif
