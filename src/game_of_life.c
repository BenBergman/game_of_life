#include <stdbool.h>
#include <stdlib.h>
#include "game_of_life.h"

#define NOT_USED(x) ((void)(x))


World World_Create()
{
	World self = calloc(1, sizeof(WorldStruct));
    self->cell = Cell_Create();
	return self;
}

void World_Destroy(World self)
{
    Cell_Destroy(self->cell);
	free(self);
}

int World_CellCount(World world)
{
	NOT_USED(world);
	return 1;
}

Cell World_FirstCell(World self)
{
	return self->cell;
}

Cell World_NextCell(World self)
{
	NOT_USED(self);
	return NullCell();
}

Coords World_GetNeighbourCoords(World self, Coord coord)
{
	NOT_USED(self);

	Coords coords = Coords_Create();
	Coords_Add(coords, new_Coord(coord.x-1, coord.y-1));
	Coords_Add(coords, new_Coord(coord.x-1, coord.y));
	Coords_Add(coords, new_Coord(coord.x-1, coord.y+1));

	Coords_Add(coords, new_Coord(coord.x, coord.y-1));
	Coords_Add(coords, new_Coord(coord.x, coord.y+1));

	Coords_Add(coords, new_Coord(coord.x+1, coord.y-1));
	Coords_Add(coords, new_Coord(coord.x+1, coord.y));
	Coords_Add(coords, new_Coord(coord.x+1, coord.y+1));

	return coords;
}
