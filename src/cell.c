#include <stdbool.h>
#include <stdlib.h>
#include "cell.h"

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
