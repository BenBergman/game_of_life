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

Coords World_GetNeighbourCoords(World self, Coord coord)
{
	NOT_USED(self);

	Coords coords = Coords_Create();
	Coords_Add(coords, new_Coord(coord.x-1, coord.y-1));
	Coords_Add(coords, new_Coord(coord.x-1, coord.y));
	Coords_Add(coords, new_Coord(coord.x-1, coord.y+1));

	Coords_Add(coords, new_Coord(coord.x, coord.y-1));
	Coords_Add(coords, new_Coord(coord.x, coord.y+1));

	Coords_Add(coords, new_Coord(coord.x+1, coord.y-1));
	Coords_Add(coords, new_Coord(coord.x+1, coord.y));
	Coords_Add(coords, new_Coord(coord.x+1, coord.y+1));

	return coords;
}
