#include <stdlib.h>
#include <stdio.h>

#include "generation.h"
#include "cell.h"


#define NOT_USED(x) ((void)(x))


Generation Generation_Create()
{
	Generation self = calloc(1, sizeof(Generation));
    for (int i = 0; i < 1000; i++) {
        //self->cells[i] = Cell_Create();
    }
    self->cell_count = 0;
	return self;
}


void Generation_Destroy(Generation self)
{
    NOT_USED(self);
    for (int i = 0; i < 1000; i++) {
        //Cell_Destroy(self->cells[i]);
    }
    free(self);
}


int Generation_GetLiveCellCount(Generation self)
{
    return self->cell_count;
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (!self->cells[i]->is_dead) {
            printf("cell %d is alive\n", i);
            count++;
        }
    }
    return count;
}


void Generation_SpawnCell(Generation self, int cell_id)
{
    NOT_USED(cell_id);
    self->cell_count++;
}
