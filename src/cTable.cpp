#include <stdexcept>
#include <ctime>
#include <iostream>
#include <cstring>

#include "../include/fidbs/cTable.h"

#define SIZE_UINT64T 8

cTable::cTable(uint columnCount, uint rowCount) {
    mColumnCount = columnCount;
    mRowCount = rowCount;
    mData = new uint64_t[mColumnCount * mRowCount];
}

cTable::~cTable() {

    if (mData != nullptr) {
        delete[] mData;
        mData = nullptr;
    }
}

void cTable::Clear() {
    for (int i = 0; i < mRowCount; ++i) {
        for (int j = 0; j < mColumnCount; ++j) {
            mData[i * mColumnCount + j] = 0;
        }
    }
}

void cTable::SetRandom(uint maxValue) {

    // initialize random generator
    srand(time(NULL));

    // increment max value to achievement: 0 <= number <= maxValue
    maxValue += 1;

    for (int i = 0; i < mRowCount; ++i) {
        for (int j = 0; j < mColumnCount; ++j) {
            mData[i * mColumnCount + j] = rand() % maxValue;
        }
    }
}

void cTable::Print() {

    std::cout << std::endl;

    for (int i = 0; i < mRowCount; ++i) {
        for (int j = 0; j < mColumnCount; ++j) {
            std::cout << mData[i * mColumnCount + j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}


void copyRow(uint64_t *InputData, uint InputColumnCount, uint64_t *JoinData, uint JoinDataColumnOffset = 0) {
    std::memcpy((JoinData + JoinDataColumnOffset), InputData, InputColumnCount * SIZE_UINT64T);
}

cTable *cTable::Join(cTable &t1, uint c1, cTable &t2, uint c2) {

    const uint newColumnCount = t1.GetColumnCount() + t2.GetColumnCount();
    const uint newRowCount = 1000;

    cTable *joinTable = new cTable(newColumnCount, newRowCount);
    joinTable->Clear();

    uint row = 1;

    for (uint i = 1; i <= t1.GetRowCount(); ++i) {
        for (uint j = 1; j <= t2.GetRowCount(); ++j) {

            // rows equals, copy
            if (t1.GetValue(c1, i) == t2.GetValue(c2, j)) {

                copyRow(t1.GetRow(i), t1.GetColumnCount(), joinTable->GetRow(row));
                copyRow(t2.GetRow(j), t2.GetColumnCount(), joinTable->GetRow(row), t1.GetColumnCount());

                row++;
            }
        }
    }

    return joinTable;
}

