#include "coord.h"

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

