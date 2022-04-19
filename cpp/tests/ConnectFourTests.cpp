#include "../ConnectFour.h"

#include <iostream>

void checkPiece(connectFour *game, bool player, int col, bool expected)
{
    game->placePiece(player, col);
    bool results =  game->checkFour();
    // std::cout << results << " " << expected << "\n";
    if (results != expected) {
        std::cout << "Failed" << "\n";
    }
}

int main() {
    bool verbose = false;

    std::cout << "Testing connectFour" << "\n";

    std::cout << "Testing Vertical" << "\n";
    connectFour *game = new connectFour();
    checkPiece(game, true, 1, false);
    checkPiece(game, true, 1, false);
    checkPiece(game, true, 1, false);
    checkPiece(game, true, 1, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Horizantial Right to Left" << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 1, false);
    checkPiece(game, true, 2, false);
    checkPiece(game, true, 3, false);
    checkPiece(game, true, 4, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Horizantial Left to Right" << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 4, false);
    checkPiece(game, true, 3, false);
    checkPiece(game, true, 2, false);
    checkPiece(game, true, 1, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Diagonial Top Left to Bottom Right" << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 4, false);
    checkPiece(game, false, 5, false);
    checkPiece(game, true, 6, false);
    checkPiece(game, false, 7, false);

    checkPiece(game, false, 4, false);
    checkPiece(game, true, 5, false);
    checkPiece(game, false, 6, false);

    checkPiece(game, true, 4, false);
    checkPiece(game, false, 5, false);

    checkPiece(game, false, 4, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Diagonial Bottom Right to Top Left" << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 4, false);
    checkPiece(game, false, 5, false);
    checkPiece(game, true, 6, false);

    checkPiece(game, false, 4, false);
    checkPiece(game, true, 5, false);
    checkPiece(game, false, 6, false);

    checkPiece(game, true, 4, false);
    checkPiece(game, false, 5, false);

    checkPiece(game, false, 4, false);

    checkPiece(game, false, 7, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Diagonial Bottom Right to Top Left"
              << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 4, false);
    checkPiece(game, false, 5, false);
    checkPiece(game, true, 6, false);
    checkPiece(game, false, 7, false);

    checkPiece(game, false, 4, false);
    checkPiece(game, true, 5, false);

    checkPiece(game, true, 4, false);
    checkPiece(game, false, 5, false);

    checkPiece(game, false, 4, false);

    checkPiece(game, false, 6, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Diagonial Top Right to Bottom Left" << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 4, false);
    checkPiece(game, false, 3, false);
    checkPiece(game, true, 2, false);
    checkPiece(game, false, 1, false);

    checkPiece(game, false, 4, false);
    checkPiece(game, true, 3, false);
    checkPiece(game, false, 2, false);

    checkPiece(game, true, 4, false);
    checkPiece(game, false, 3, false);

    checkPiece(game, false, 4, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Diagonial Bottom Right to Top Left" << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 4, false);
    checkPiece(game, false, 3, false);
    checkPiece(game, true, 2, false);

    checkPiece(game, false, 4, false);
    checkPiece(game, true, 3, false);
    checkPiece(game, false, 2, false);

    checkPiece(game, true, 4, false);
    checkPiece(game, false, 3, false);

    checkPiece(game, false, 4, false);

    checkPiece(game, false, 1, true);
    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing Diagonial to Bottom Right and to Top Left"
              << "\n";
    delete game;
    game = new connectFour();
    checkPiece(game, true, 4, false);
    checkPiece(game, false, 3, false);
    checkPiece(game, true, 2, false);
    checkPiece(game, false, 1, false);

    checkPiece(game, false, 4, false);
    checkPiece(game, true, 3, false);

    checkPiece(game, true, 4, false);
    checkPiece(game, false, 3, false);

    checkPiece(game, false, 4, false);

    checkPiece(game, false, 2, true);

    if (verbose) {
        game->printBoard();
    }

    std::cout << "Testing connectFour Completed \n\n";
}