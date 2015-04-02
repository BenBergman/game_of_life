#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

typedef struct {
    bool is_dead;
} Cell;

bool Cell_IsDead(Cell cell);

#endif
