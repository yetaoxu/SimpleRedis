#include <stdio.h>
#include <cstring>
#include <zconf.h>
#include "HashTable.h"
#include "Interaction.h"



int main(int argc, char *argv[]) {
    int capacity;

    sscanf(argv[1], "%d", &capacity);

    HashTable *hashTable = initHashTable(capacity);

    startInteract(hashTable);
}
