#include "ConnectFour.h"
#include "MiniMax.h"
#include "TransTable.h"

#include <climits>
#include <limits.h>
#include <stdint.h>
#include <iostream>

using namespace std;

// 1,2,3,4,5,6,7
// 4,3,5,2,6,1,7
int moveOrder[8] = {0,4,3,5,2,6,1,7};

//Maximizing agemt: tells what agent's turn it currently is
//Maximizing agent: true  - our agent
//Maximizing agent: false - openent agent
//Depth: how many more turns to process
//state: current game state to evaluate
int miniMax(connectFour state, int depth, int8_t alpha, int8_t beta, bool player1, TransTable *table)
{
    
    if (depth == 0)
    {
        return 0;
    }

    if (state.checkFour())
    {
        // If player 2 won last turn
        if (player1)
        {
            return -(depth);   
        } else 
        {
            return depth;
        }
    }

    // int8_t because its stored as one byte in Transposition Table
    int8_t eval;

    // Player 1 turn
    if (player1)
    {
        // int8_t because its stored as one byte in Transposition Table
        int8_t maxEval = INT8_MIN;
        for (int i = 1; i <= state.getColCount(); i++)
        {
            int col = moveOrder[i];
            connectFour newState{state};
            if (newState.placePiece(player1, col))
            {
                // if score is -128 then it's
                eval = miniMax(newState, depth - 1, alpha, beta, !player1, table);

                // eval = miniMax(newState, depth - 1, alpha, beta, !player1, table);

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
        for (int i = 1; i <= state.getColCount(); i++)
        {
            int col = moveOrder[i];
            connectFour newState{state};
            if (newState.placePiece(player1, col))
            {
                int8_t score = table->get(newState.getMask(player1));
                if (score != -128)
                {
                    eval = score;
                }
                else
                {
                    eval = miniMax(newState, depth - 1, alpha, beta, !player1, table);
                    table->put(newState.getMask(player1), eval);
                }

                // eval = miniMax(newState, depth - 1, alpha, beta, !player1, table);
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

int getMove(connectFour state, int depth, bool player1)
{
    int bestCol = 1;
    int8_t alpha = INT8_MIN;
    int8_t beta = INT8_MAX;
    int8_t bestEval;

    int8_t eval;
    TransTable* table = new TransTable(1000000);

    if (player1) {
        bestEval = INT8_MIN;
        for (int i = 1; i <= state.getColCount(); i++)
        {
            int col = moveOrder[i];
            connectFour newState{state};
            if (newState.placePiece(player1, col))
            {
                eval = miniMax(newState, depth - 1, alpha, beta, !player1, table);
                std::cout << "Col: " << col << " Eval: " << (depth - (int)eval) << "\n";

                if (eval > bestEval)
                {
                    bestEval = eval;
                    bestCol = col;
                } 
            }
        }
    } else {
        bestEval = INT8_MAX;
        for (int i = 1; i <= state.getColCount(); i++)
        {
            int col = moveOrder[i];
            connectFour newState{state};
            if (newState.placePiece(player1, col))
            {
                eval = miniMax(newState, depth - 1, alpha, beta, !player1, table);
                std::cout << "Col: " << col << "   Eval: " << (depth - (int)eval) << "\n";
                if (eval < bestEval)
                {
                    bestEval = eval;
                    bestCol = col;
                }
            }
        }
    }

    return bestCol;
}