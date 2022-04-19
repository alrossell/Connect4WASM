#include "TransTable.h"

#include <iostream>

int test(TransTable *table, int8_t *teste) {
    int x = table->get(0);
    std::cout << x << "\n";
    int8_t y = 5;
    *teste = y;
    return 1;
}

int main() {
    TransTable* table = new TransTable(10000);
    int8_t teste = 5;
    test(table, &teste);
    int x = teste;
    std::cout << x << "\n";
}