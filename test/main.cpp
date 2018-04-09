
#include <cstdio>
#include <iostream>
#include <cstring>
#include "../include/fidbs/cTable.h"

#define SIZE_UINT64T 8

/**
 * Test create table, set random values, print
 */
void test1() {

    std::cout << "table 3x3" << std::endl;
    cTable *table1 = new cTable(3, 3);
    table1->Clear();
    table1->SetRandom(30);
    table1->Print();

    std::cout << "------------- " << std::endl << std::endl;


    std::cout << "table 10x5" << std::endl;
    cTable *table2 = new cTable(10, 5);
    table2->Clear();
    table2->SetRandom(10);
    table2->Print();

    std::cout << " ------------- " << std::endl << std::endl;

    std::cout << "table 100x30" << std::endl;
    cTable *table3 = new cTable(100, 30);
    table3->Clear();
    table3->SetRandom(10000);
    table3->Print();

    std::cout << " ------------- " << std::endl << std::endl;

    delete table1;
    delete table2;
    delete table3;
}

/**
 * Test join table
 */
void test2() {

    cTable *table1 = new cTable(3, 5);
    table1->SetValue(1, 1, 1);
    table1->SetValue(2, 1, 999);
    table1->SetValue(3, 1, 999);

    table1->SetValue(1, 2, 2);
    table1->SetValue(2, 2, 999);
    table1->SetValue(3, 2, 999);

    table1->SetValue(1, 3, 3);
    table1->SetValue(2, 3, 999);
    table1->SetValue(3, 3, 999);

    table1->SetValue(1, 4, 5);
    table1->SetValue(2, 4, 999);
    table1->SetValue(3, 4, 999);

    table1->SetValue(1, 5, 4);
    table1->SetValue(2, 5, 999);
    table1->SetValue(3, 5, 999);

    table1->Print();

    cTable *table2 = new cTable(4, 5);
    table2->SetValue(1, 1, 1111);
    table2->SetValue(2, 1, 1111);
    table2->SetValue(3, 1, 1111);
    table2->SetValue(4, 1, 1);

    table2->SetValue(1, 2, 1111);
    table2->SetValue(2, 2, 1111);
    table2->SetValue(3, 2, 1111);
    table2->SetValue(4, 2, 2);


    table2->SetValue(1, 3, 1111);
    table2->SetValue(2, 3, 1111);
    table2->SetValue(3, 3, 1111);
    table2->SetValue(4, 3, 3);


    table2->SetValue(1, 4, 1111);
    table2->SetValue(2, 4, 1111);
    table2->SetValue(3, 4, 1111);
    table2->SetValue(4, 4, 5);


    table2->SetValue(1, 5, 1111);
    table2->SetValue(2, 5, 1111);
    table2->SetValue(3, 5, 1111);
    table2->SetValue(4, 5, 4);

    table2->Print();

    cTable *result;
    result = cTable::Join(*table1, 1, *table2, 4);

    result->Print();

    std::cout << " ------------- " << std::endl << std::endl;


    delete table1;
    delete table2;
    delete result;
}

int main(int argc, char **argv) {

//    test1();
//    test2();

}


