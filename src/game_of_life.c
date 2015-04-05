#include <stdbool.h>
#include "game_of_life.h"

#define NOT_USED(x) ((void)(x))

bool Cell_IsDead(Cell cell)
{
    NOT_USED(cell);
    return true;
}

int World_CellCount(World world)
{
	NOT_USED(world);
	return 1;
}

Cell World_GetCell(World world, int index)
{
	NOT_USED(index);
	return world.cell;
}

Coord NullCoord()
{
	Coord coord = {0};
	return coord;
}

bool compare_coords(Coord a, Coord b)
{
	NOT_USED(a);
	NOT_USED(b);
	return true;
}

Coords new_Coords()
{
	Coords coords = {0};
	return coords;
}

Coord Coords_First(Coords *coords)
{
	NOT_USED(coords);
	return NullCoord();
}

Coord Coords_Next(Coords *coords)
{
	NOT_USED(coords);
	return NullCoord();
}

int Coords_Count(Coords *coords)
{
	return coords->coord_count;
}

void Coords_Add(Coords *coords, Coord coord)
{
	NOT_USED(coord);
	coords->coord_count++;
}
