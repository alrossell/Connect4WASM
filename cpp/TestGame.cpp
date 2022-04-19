#include "ConnectFour.h"
#include "MiniMax.h"

#include <iostream>

using namespace std;

int main()
{
    connectFour currGame{};
    currGame.printBoard();
    // true = player11 = 1, false = player12 = -1
    bool player1 = true;
    char col;
    bool gameIsOver = false;

    while (!gameIsOver)
    {
        if (player1)
        {
            std::cout << "It's player 1 turn \n";
            std::cout << "Col placement: ";
            std::cin >> col;

            if(col == 'q') {
                std::cout << "Goodbye\n";
                return 1;
            }

            int newCol = (int)col - 48;
            currGame.placePiece(true, newCol);
        }
        else
        {
            col = getMove(currGame, 40, false);
            currGame.placePiece(false, col);
        }
        player1 = !player1;
        currGame.printBoard();
        gameIsOver = currGame.checkFour();
    }

    if (player1)
    {
        printf("player1 2 wins");
    }
    else
    {
        printf("player1 1 wins");
    }
}