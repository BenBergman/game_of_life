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
