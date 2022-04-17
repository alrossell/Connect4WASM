#include <emscripten/bind.h>
#include "ConnectFour.h"

using namespace emscripten;

class ConnectFourGame
{
public:
    ConnectFourGame()
    {
        game = connectFour();
    }

    int placePiece(bool player, int col)
    {
        game.placePiece(player, col);
        return game.checkFour();
    }

    int getMove()
    {
        return 1;
    }

private:
    connectFour game;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example)
{
    class_<ConnectFourGame>("ConnectFourGame")
        .constructor()
        .function("placePiece", &ConnectFourGame::placePiece)
        .function("getMove", &ConnectFourGame::getMove);
}