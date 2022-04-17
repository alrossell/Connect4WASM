#ifndef CONNECTFOUR
#define CONNECTFOUR

#include <stdint.h>

class connectFour
{
private:
    static int rowCount;
    static int colCount;

    static int rowIndexCount;
    static int colIndexCount;

    int lastPlacedCol;
    int lastPlacedRow;
    bool lastPlayer;
public:
    uint64_t player1Board;
    uint64_t player2Board;
    uint64_t mask;

    connectFour();

    bool placePiece(bool player, int col);

    uint64_t rowColToInt(int col, int row);
    int getColCount();
    bool checkFour();
    bool isOpen(int col, int row, bool player);

    void printBoard();
};

#endif