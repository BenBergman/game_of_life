#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

typedef struct {
    bool is_dead;
	bool is_null;
} Cell;

Cell NullCell(void);
bool Cell_IsDead(Cell);

bool compare_cells(Cell, Cell);


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


typedef struct {
	int x;
	int y;
} Coord;

Coord new_Coord(int x, int y);
Coord NullCoord(void);

bool compare_coords(Coord, Coord);


#define COORDS_SIZE 10

typedef struct {
	int count;
	int index;
	Coord list[COORDS_SIZE];
} Coords;

Coords new_Coords(void);
Coord Coords_First(Coords*);
Coord Coords_Next(Coords*);
int Coords_Count(Coords*);
void Coords_Add(Coords*, Coord);

#endif
