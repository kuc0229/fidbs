
#include <cstdio>
#include <iostream>
#include "../include/fidbs/cTable.h"

int main(int argc, char **argv) {

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

    std::cout << "table 30x30" << std::endl;
    cTable *table3 = new cTable(30, 30);
    table3->Clear();
    table3->SetRandom(30);
    table3->Print();

    std::cout << " ------------- " << std::endl << std::endl;

    std::cout << "table 100x30" << std::endl;
    cTable *table4 = new cTable(100, 30);
    table4->Clear();
    table4->SetRandom(10000);
    table4->Print();

    std::cout << " ------------- " << std::endl << std::endl;


}
