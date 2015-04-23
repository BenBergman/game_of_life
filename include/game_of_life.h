#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include "cell.h"
#include "coord.h"
#include "coords.h"


typedef struct {
	Cell cell;
} WorldStruct;

typedef WorldStruct * World;

World World_Create(void);
void World_Destroy(World);
int World_CellCount(World);
Cell World_GetCell(World, int);
Cell World_FirstCell(World);
Cell World_NextCell(World);
Coords World_GetNeighbourCoords(World, Coord);

#endif
