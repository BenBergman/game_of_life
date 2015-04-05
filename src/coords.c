#include <stdlib.h>
#include "coords.h"

Coords Coords_Create()
{
	Coords coords = calloc(1, sizeof(CoordsStruct));
	coords->count = 0;
	coords->index = 0;
	/* TODO: is there a better way to set all in the list no null? */
	for (int i = 0; i < COORDS_SIZE; i++) {
		coords->list[i] = NullCoord();
	}
	return coords;
}

void Coords_Destroy(Coords self)
{
	free(self);
}

Coord Coords_First(Coords coords)
{
	coords->index = 0;
	return coords->list[coords->index++];
}

Coord Coords_Next(Coords coords)
{
	return coords->list[coords->index++];
}

int Coords_Count(Coords coords)
{
	return coords->count;
}

void Coords_Add(Coords coords, Coord coord)
{
	for (int i = 0; i < COORDS_SIZE; i++) {
		if (compare_coords(coords->list[i], coord)) {
			return;
		}
	}

	coords->list[coords->count++] = coord;
}
