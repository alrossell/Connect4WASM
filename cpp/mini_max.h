#ifndef MINI_MAX_H
#define MINI_MAX_H

#include "connectFour.h"
#include "TranspositionTable.h"

#include <stdint.h>

int miniMax(connectFour state, int depth, int alpha, int beta, bool maximizingAgent, TranspositionTable * table);

#endif
