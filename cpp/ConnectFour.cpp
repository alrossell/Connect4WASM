#include "connectFour.h"

#include <stdint.h>
#include <math.h>
#include <iostream>

using namespace std;

int connectFour::rowCount = 6;
int connectFour::colCount = 7;

int connectFour::rowIndexCount = rowCount - 1;
int connectFour::colIndexCount = colCount - 1;

connectFour::connectFour()
{
    // Non Index form
    this->connectFour::lastPlacedCol = -1;
    // Non Index form
    this->connectFour::lastPlacedRow = -1;
    this->connectFour::lastPlayer = false;

    // Player 1 bool = true
    this->connectFour::player1Board = 0;
    // Player 2 bool = false
    this->connectFour::player2Board = 0;
    this->connectFour::mask = 0;

}

// -------------------------------------------------------------------

bool connectFour::placePiece(bool player, int col)
{
    if (col > 7) {
        std::cout << "Col placement is too big" << "\n";
        return false;
    } else if (col < 1) {
        std::cout << "Col placement is too small" << "\n";
        return false;
    }
    int openRow = -1;

    for (int row = 1; row <= rowCount; row++)
    {
        if (isOpen(col, row, true) && isOpen(col, row, false)) {
            openRow = row;
            break;
        }
    }

    if (openRow == -1)
        // std::cout << "Col is full" << "\n";
        return false;

    if (player) {
        player1Board = player1Board | rowColToInt(col, openRow);
    } else {
        player2Board = player2Board | rowColToInt(col, openRow);
    }
    mask = mask | rowColToInt(col, openRow);
      
    lastPlacedCol = col;
    lastPlacedRow = openRow;
    lastPlayer = player;

    return true;
}

// ---------------------------------------------------------------------------------

int connectFour::getColCount()
{
    return colCount;
}

uint64_t connectFour::rowColToInt(int col, int row)
{
    return (uint64_t)1 << (7 - col) << (8 * (row - 1));
}

bool connectFour::isOpen(int col, int row, bool player)
{
    uint64_t checkerInt = rowColToInt(col, row);
    if (player)
    {
        return checkerInt != (checkerInt & player1Board);
    }
    else
    {
        return checkerInt != (checkerInt & player2Board);
    }
}

bool connectFour::checkFour()
{
    int winCount = 1;

    // Vertical to the right
    for (int col = lastPlacedCol + 1; col <= colCount; col++)
    {
        if (!isOpen(col, lastPlacedRow, lastPlayer))
        {
            winCount++;
        }
        else
        {
            break;
        }
    }

    // Vertical to the left
    for (int col = lastPlacedCol - 1; col > 0; col--)
    {
        if (!isOpen(col, lastPlacedRow, lastPlayer))
        {
            winCount++;
        }
        else
        {
            break;
        }
    }

    if (winCount >= 4)
    {
        return true;
    }

    winCount = 1;

    // Horizantial Down
    for (int8_t row = lastPlacedRow - 1; row > 0; row--)
    {
        if (!isOpen(lastPlacedCol, row, lastPlayer))
        {
            winCount++;
        }
        else
        {
            break;
        }
    }

    
    if (winCount >= 4)
    {
        return true;
    }

    // Diagonal down to the left
    winCount = 1;

    for (int col = lastPlacedCol - 1, row = lastPlacedRow - 1; col > 0 && row > 0; col--, row--)
    {
        if (!isOpen(col, row, lastPlayer))
        {
            winCount++;
        }
        else
        {
            break;
        }
    }

    // Diagonal up to the right
    for (int col = lastPlacedCol + 1, row = lastPlacedRow + 1; col <= colCount && row > rowCount; col++, row++)
    {
        if (!isOpen(col, row, lastPlayer))
        {
            winCount++;
        }
        else
        {
            break;
        }
    }

    if (winCount >= 4)
    {
        return true;
    }

    winCount = 1;

    // Diagonal down to the right
    for (int col = lastPlacedCol + 1, row = lastPlacedRow - 1; col <= colCount && row > 0; col++, row--)
    {
        if (!isOpen(col, row, lastPlayer))
        {
            winCount++;
        }
        else
        {
            break;
        }
    }

    // Diagonal up to the left
    for (int col = lastPlacedCol - 1, row = lastPlacedRow + 1; col > 0 && row <= rowCount; col--, row++)
    {
        if (!isOpen(col, row, lastPlayer))
        {
            winCount++;
        }
        else
        {
            break;
        }
    }

    if (winCount >= 4)
    {
        return true;
    }

    return false;
}

// ---------------------------------------------------------------------

void connectFour::printBoard()
{
    for (int row = rowCount; row > 0; row--)
    {
        for (int col = 1; col <= colCount; col++)
        {
            if (!isOpen(col, row, true))
            {
                std::cout << "  " << 1;
            }
            else if (!isOpen(col, row, false))
            {
                std::cout << " " << -1;
            }
            else
            {
                std::cout << "  " << 0;
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n  ";
    for (int c = 1; c <= colCount; c++)
    {
        std::cout << c << "  ";
    }

    std::cout << "\n";
}

// int main()
// {
//     connectFour game{};

//     game.placePiece(true, 1);
//     // game.placePiece(true, 1);
//     game.placePiece(true, 1);
//     game.placePiece(true, 1);

//     std::cout << game.checkFour();
// }
