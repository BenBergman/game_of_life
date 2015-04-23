#include "cell.h"

typedef struct {
    Cell cells[1000];
    int cell_count;
} GenerationStruct;

typedef GenerationStruct * Generation;

Generation Generation_Create(void);
void Generation_Destroy(Generation self);

int Generation_GetLiveCellCount(Generation self);
void Generation_SpawnCell(Generation self, int);
