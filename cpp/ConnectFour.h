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

    connectFour();

    bool placePiece(bool player, int col);

    int getLastPlacedRow();
    uint64_t rowColToInt(int col, int row);
    int getColCount();
    bool checkFour();
    bool isOpen(int col, int row, bool player);
    uint64_t getMask(bool player1);

    void printBoard();
};

#endif