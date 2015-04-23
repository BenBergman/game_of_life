typedef struct GenerationStruct * Generation;

Generation Generation_Create(void);
void Generation_Destroy(Generation self);
int Generation_GetLiveCellCount(Generation self);
