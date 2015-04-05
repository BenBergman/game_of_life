#include <stdbool.h>
#include <stdlib.h>
#include "game_of_life.h"

#define NOT_USED(x) ((void)(x))

Cell NullCell()
{
	Cell cell = {
		.is_dead = true,
		.is_null = false,
	};
	return cell;
}

bool Cell_IsDead(Cell cell)
{
    NOT_USED(cell);
    return true;
}

bool compare_cells(Cell a, Cell b)
{
	return a.is_null == b.is_null && a.is_dead == b.is_dead;
}


World World_Create()
{
	World self = calloc(1, sizeof(WorldStruct));
	return self;
}

void World_Destroy(World self)
{
	free(self);
}

int World_CellCount(World world)
{
	NOT_USED(world);
	return 1;
}

Cell World_FirstCell(World self)
{
	NOT_USED(self);
	Cell cell = NullCell();
	cell.is_null = !cell.is_null;
	return cell;
}

Cell World_NextCell(World self)
{
	NOT_USED(self);
	return NullCell();
}


Coord new_Coord(int x, int y)
{
	Coord coord;
	coord.x = x;
	coord.y = y;
	return coord;
}

Coord NullCoord()
{
	/* TODO: get C99 or C11 working so struct literal initializations with field names */
	Coord coord;
	coord.x = -1;
	coord.y = -1;
	return coord;
}

bool compare_coords(Coord a, Coord b)
{
	return a.x == b.x && a.y == b.y;
}

/* TODO: C90 sucks (I had to declare this outside the funtion to please the compiler) */
int loop_index;
Coords new_Coords()
{
	Coords coords;
	coords.count = 0;
	coords.index = 0;
	/* TODO: is there a better way to set all in the list no null? */
	for (loop_index = 0; loop_index < COORDS_SIZE; loop_index++) {
		coords.list[loop_index] = NullCoord();
	}
	return coords;
}

Coord Coords_First(Coords *coords)
{
	coords->index = 0;
	return coords->list[coords->index++];
}

Coord Coords_Next(Coords *coords)
{
	return coords->list[coords->index++];
}

int Coords_Count(Coords *coords)
{
	return coords->count;
}

void Coords_Add(Coords *coords, Coord coord)
{
	coords->list[coords->count++] = coord;
}
