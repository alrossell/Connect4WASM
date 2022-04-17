#include "TranspositionTable.h"
#include <stdint.h>
#include <vector>
#include <assert.h>

struct Entry
{
    int64_t key; 
    int8_t val;   
};                     

TranspositionTable::TranspositionTable(unsigned int size) : T(size)
{
    assert(size > 0);
}

unsigned int TranspositionTable::index(int64_t key)
{
    return key % T.size();
}

/**
 * Store a value for a given key
 * @param key: 56-bit key
 * @param value: non-null 8-bit value. null (0) value are used to encode missing data.
 */
void TranspositionTable::put(int64_t key, int8_t val)
{
    unsigned int i = index(key); 
    T[i].key = key;
    T[i].val = val;
}

/**
 * Get the value of a key
 * @param key
 * @return 8-bit value associated with the key if present, 0 otherwise.
 */
int8_t TranspositionTable::get(int64_t key)
{
    unsigned int i = index(key); // compute the index position
    if (T[i].key == key)
        return T[i].val; // and return value if key matches
    else
        return -128; // or 0 if missing entry
}


