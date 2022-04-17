#include "connectFour.h"
#include "mini_max.h"
#include "TranspositionTable.h"

#include <climits>
#include <limits.h>
#include <stdint.h>
#include <iostream>

using namespace std;

//Maximizing agemt: tells what agent's turn it currently is
//Maximizing agent: true  - our agent
//Maximizing agent: false - openent agent
//Depth: how many more turns to process
//state: current game state to evaluate
int miniMax(connectFour state, int depth, int alpha, int beta, bool maximizingAgent, TranspositionTable * table)
{
    if (depth == 0)
    {
        return 0;
    }

    if (state.checkFour())
    {
        if(maximizingAgent)
        {
            return -depth;   
        } else 
        {
            return depth;
        }
    }

    if (maximizingAgent)
    {
        int8_t maxEval = INT8_MIN;
        int8_t eval;

        for (int col = 1; col <= state.getColCount(); col++)
        {
            connectFour newState{state};
            if (newState.placePiece(maximizingAgent, col))
            {
                // int8_t score = table.get(newState.mask);
                // if(score != -128) 
                // {
                //     eval = score;
                // } else 
                // {
                //     eval = miniMax(newState, depth - 1, alpha, beta, !maximizingAgent, table);
                //     table.put(newState.mask, eval);
                // }

                eval = miniMax(newState, depth - 1, alpha, beta, !maximizingAgent, table);

                int test = eval;

                if (eval > maxEval)
                {
                    maxEval = eval;
                }
                if (eval > alpha)
                {
                    alpha = eval;
                }
                if(beta <= alpha)
                {
                    break;
                }
            }
        }
        return maxEval;
    } else 
    {
        int8_t minEval = INT8_MAX;
        int8_t eval;
        for (int col = 1; col <= state.getColCount(); col++)
        {
            connectFour newState{state};
            if (newState.placePiece(maximizingAgent, col))
            {
                // int8_t score = table.get(newState.mask);
                // if (score != -128)
                // {
                //     eval = score;
                // }
                // else
                // {
                //     eval = miniMax(newState, depth - 1, alpha, beta, !maximizingAgent, table);
                //     table.put(newState.mask, eval);
                // }

                eval = miniMax(newState, depth - 1, alpha, beta, !maximizingAgent, table);
                if (eval < minEval)
                {
                    minEval = eval;
                }
                if (eval < beta)
                {
                    beta = eval;
                }
                if (beta <= alpha)
                {
                    break;
                }
            }
        }
        return minEval;
    }
}

// int main() 
// {
//     connectFour game{};

//     int depth = 1;
//     int8_t alpha = 1;
//     int8_t beta = 1;
//     bool max = false;
//     miniMax(game, depth, alpha, beta, max);
// }
