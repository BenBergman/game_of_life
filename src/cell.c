#include <stdbool.h>
#include <stdlib.h>
#include "cell.h"

#define NOT_USED(x) ((void)(x))

Cell Cell_Create()
{
    Cell cell = calloc(1, sizeof(CellStruct));
    cell->is_dead = true;
    cell->is_null = false;
    return cell;
}

void Cell_Destroy(Cell self)
{
    if (self != 0) {
        free(self);
    }
}

Cell NullCell()
{
	return 0;
}

bool Cell_IsDead(Cell cell)
{
    NOT_USED(cell);
    return true;
}

bool compare_cells(Cell a, Cell b)
{
    if (a == 0) {
        if (b == 0) {
            return true;
        }
        return false;
    }
    if (b == 0) {
        return false;
    }
	return a->is_null == b->is_null && a->is_dead == b->is_dead;
}
