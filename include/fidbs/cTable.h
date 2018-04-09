#pragma once

#include <cstdint>

typedef unsigned int uint;

class cTable {
private:
    uint mColumnCount;
    uint mRowCount;
    uint64_t *mData;

    inline uint64_t *GetRow(uint ri) {
        return &mData[(ri - 1) * mColumnCount];
    };

public:
    cTable(uint columnCount, uint rowCount);

    ~cTable();

    inline uint GetColumnCount() {
        return mColumnCount;
    };

    inline uint GetRowCount() {
        return mRowCount;
    };

    inline uint64_t GetValue(uint ci, uint ri) {
        return mData[(ri - 1) * mColumnCount + (ci - 1)];
    };

    inline void SetValue(uint ci, uint ri, uint64_t value) {
        mData[(ri - 1) * mColumnCount + (ci - 1)] = value;
    };

    void Clear();

    void SetRandom(uint maxValue);

    void Print();

    static cTable *Join(cTable &t1, uint c1, cTable &t2, uint c2);

};
