#include <stdlib.h>

#include "generation.h"
#include "cell.h"

#define NOT_USED(x) ((void)(x))

typedef struct {
    Cell cells[1000];
} GenerationStruct;


Generation Generation_Create()
{
	Generation self = calloc(1, sizeof(Generation));
	return self;
}


void Generation_Destroy(Generation self)
{
    free(self);
}


int Generation_GetLiveCellCount(Generation self)
{
    NOT_USED(self);
    return 0;
}
