#ifndef _CELL_H_
#define _CELL_H_

#include <stdbool.h>

typedef struct {
    bool is_dead;
	bool is_null;
} Cell;

Cell NullCell(void);
bool Cell_IsDead(Cell);

bool compare_cells(Cell, Cell);

#endif
