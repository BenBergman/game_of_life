#ifndef _COORD_H_
#define _COORD_H_

#include <stdbool.h>

/* TODO: hide the details in the src file, like TDDFEC 225 */
typedef struct {
	int x;
	int y;
} Coord;

Coord new_Coord(int x, int y);
Coord new_CoordFromCell(int cell);
Coord NullCoord(void);

int Coord_Cell(Coord);

bool compare_coords(Coord, Coord);

#endif
