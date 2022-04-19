#ifndef MINI_MAX_H
#define MINI_MAX_H

#include "ConnectFour.h"
#include "TransTable.h"

#include <stdint.h>

int miniMax(connectFour state, int depth, int8_t *alpha, int8_t *beta, bool maximizingAgent, TransTable *table);
int getMove(connectFour state, int depth, bool maximizingAgent);

#endif
