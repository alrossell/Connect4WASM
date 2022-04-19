#include "../TransTable.h"
#include "../ConnectFour.h"

#include <iostream>

int main() {
    std::cout << "Testing Trans Table" << "\n";
    TransTable table = TransTable(10000);
    connectFour game = connectFour();
    
    std::cout << "Getting a Missing Entry" << "\n";
    game.placePiece(true, 1);
    int result = table.get(game.mask);
    
    if (result == -128) 
    {
        std::cout << "Pass" << "\n";
    } else 
    {
        std::cout << "Failed: " << result <<  "\n";
    }

    std::cout << "Getting a Placed Entry" << "\n";
    int8_t value = 10; 
    table.put(game.mask, value);
    result = table.get(game.mask);

    if (result == value)
    {
        std::cout << "Pass"
                  << "\n";
    }
    else
    {
        std::cout << "Failed: " << result << "\n";
    }
}