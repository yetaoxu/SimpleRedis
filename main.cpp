#include <stdio.h>
#include "HashTable.h"

int main() {

    HashTable *hashTable = initHashTable(101);

    char *key = "sampleKey";
    char *value = "sampleValue";

    put(hashTable, 9, key, 11, value);
    printf("HashTable size: %d", hashTable->size);

    DataNode *dataNode = get(hashTable, 9, key);
}
