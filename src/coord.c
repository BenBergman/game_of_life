/**
 * The purpose of a coordinate is to find neighbours of cells.
 */

#include "coord.h"

#define NOT_USED(x) ((void)(x))

Coord new_Coord(int x, int y)
{
	Coord coord;
	coord.x = x;
	coord.y = y;
	return coord;
}

Coord new_CoordFromCell(int cell)
{
    Coord coord;
    coord.x = cell % 11;
    coord.y = cell / 11;
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

int Coord_Cell(Coord self)
{
    return self.x + 11 * self.y;
}

bool compare_coords(Coord a, Coord b)
{
	return a.x == b.x && a.y == b.y;
}


