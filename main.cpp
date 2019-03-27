#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable *globalHashTable;

int main() {

    globalHashTable = new HashTable();
    globalHashTable->size = 5;

    put("1", "2");

    return 0;
}