//
// Created by xuyetao on 2019/3/28.
//

#ifndef SIMPLEREDIS_HASH_TABLE_H
#define SIMPLEREDIS_HASH_TABLE_H

#include "DataNode.h"
#include "LinkListNode.h"

struct HashTable {
    int capacity;
    int size;
    LinkListNode *repos;
};

int hash(HashTable *hashTable, char *key, int len);

HashTable* initHashTable(int capacity);

void put(HashTable *hashTable, int kLen, char *key, int vLen, char *value);

DataNode *get(HashTable *hashTable, int kLen, char *key);

bool remove(HashTable *hashTable, int kLen, char *key);

#endif //SIMPLEREDIS_HASH_TABLE_H
