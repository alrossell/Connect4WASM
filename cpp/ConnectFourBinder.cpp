#include <emscripten/bind.h>
#include "ConnectFour.h"
#include "MiniMax.h"

using namespace emscripten;

// #include <iostream>

class ConnectFourGame
{
public:
    ConnectFourGame()
    {
        game = connectFour();
    }

    int placePiece(bool player, int col)
    {
        if(game.placePiece(player, col)) 
        {
            return game.getLastPlacedRow();
        } else {
            return -1;
        }
    }

    bool checkFour()
    {
        return game.checkFour();
    }

    int nextMove(bool player, int depth)
    {
        return getMove(game, depth, player);
    }

    int getMask() 
    {
        return game.mask;
    }

    void newGame()
    {
        game = connectFour();
    }

    connectFour game;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example)
{
    class_<ConnectFourGame>("ConnectFourGame")
        .constructor()
        .function("placePiece", &ConnectFourGame::placePiece)
        .function("checkFour", &ConnectFourGame::checkFour)
        .function("nextMove", &ConnectFourGame::nextMove)
        .function("newGame", &ConnectFourGame::newGame)
        .function("getMask", &ConnectFourGame::getMask);
}

// int main() {
//     ConnectFourGame thisGame = ConnectFourGame();
//     thisGame.placePiece(0,1);
//     std::cout << thisGame.game.mask << "\n";
//     ConnectFourGame newGame = thisGame.tester();
//     std::cout << newGame.game.mask << "\n";
//     thisGame.placePiece(0,1);
//     std::cout << thisGame.game.mask << "\n";
//     std::cout << newGame.game.mask << "\n";
// }