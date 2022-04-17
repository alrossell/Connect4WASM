#ifndef TRANSPOSITIONTABLE_H
#define TRANSPOSITIONTABLE_H

#include <vector>
#include <stdint.h>

class TranspositionTable
{
    private:
        struct Entry
        {
            int64_t key;
            int8_t val;
        };

        std::vector<Entry> T;

        unsigned int index(int64_t key);

    public:
        TranspositionTable(unsigned int size);
        void put(int64_t key, int8_t val);
        int8_t get(int64_t);
};

#endif