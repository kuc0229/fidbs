#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/fidbs/cTable.h"

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

inline uint cTable::GetColumnCount() {
    return mColumnCount;
}

inline uint cTable::GetRowCount() {
    return mRowCount;
}

inline uint64_t cTable::GetValue(uint ci, uint ri) {

    if (ci < 1 || ri < 1) {
        throw std::invalid_argument("column index and row index must be >= 1");
    }

    if (ci > mColumnCount || ri > mRowCount) {
        throw std::invalid_argument("out of boundary");
    }

    return mData[(ri - 1) * mColumnCount + (ci - 1)];
}

inline void cTable::SetValue(uint ci, uint ri, uint64_t value) {

    if (ci < 1 || ri < 1) {
        throw std::invalid_argument("column index and row index must be >= 1");
    }

    if (ci > mColumnCount || ri > mRowCount) {
        throw std::invalid_argument("out of boundary");
    }

    mData[(ri - 1) * mColumnCount + (ci - 1)] = value;
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
}

