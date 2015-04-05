#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

typedef struct {
    bool is_dead;
} Cell;

bool Cell_IsDead(Cell);


typedef struct {
	Cell cell;
} World;

int World_CellCount(World);
Cell World_GetCell(World, int);


typedef struct {
	int placeholder;
} Coord;

Coord NullCoord(void);

bool compare_coords(Coord, Coord);


typedef struct {
	int placeholder;
} Coords;

Coord Coords_First(Coords);
Coord Coords_Next(Coords);

#endif
