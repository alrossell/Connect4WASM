#include "TransTable.h"
#include <stdint.h>
#include <vector>

#include <iostream>

struct Entry
{
    int64_t key; 
    int8_t val;   
};

TransTable::TransTable(unsigned int size) : T(size)
{
}

unsigned int TransTable::index(int64_t key)
{
    return key % T.size();
}

void TransTable::put(int64_t key, int8_t val)
{
    unsigned int i = index(key); 
    T[i].key = key;
    T[i].val = val;
}

int8_t TransTable::get(int64_t key)
{
    // Doesn't work for empty games 
    unsigned int i = index(key); 
    if (T[i].key == key)
        return T[i].val; 
    else
        // Returms -128 if the entry is missing 
        return -128; 
}


