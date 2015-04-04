#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

typedef struct {
    bool is_dead;
} Cell;

bool Cell_IsDead(Cell cell);


typedef struct {
	Cell cell;
} World;

int World_CellCount(World world);
Cell World_GetCell(World world, int index);

#endif
