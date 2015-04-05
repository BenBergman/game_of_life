#ifndef _COORD_H_
#define _COORD_H_

#include <stdbool.h>

typedef struct {
	int x;
	int y;
} Coord;

Coord new_Coord(int x, int y);
Coord NullCoord(void);

bool compare_coords(Coord, Coord);

#endif
