#pragma once

#include <cstdint>

typedef unsigned int uint;

class cTable {
private:
    uint mColumnCount;
    uint mRowCount;
    uint64_t *mData;

public:
    cTable(uint columnCount, uint rowCount);

    ~cTable();

    inline uint GetColumnCount();
    inline uint GetRowCount();

    inline uint64_t GetValue(uint ci, uint ri);
    inline void SetValue(uint ci, uint ri, uint64_t value);

    void Clear();
    void SetRandom(uint maxValue);
    void Print();
};
