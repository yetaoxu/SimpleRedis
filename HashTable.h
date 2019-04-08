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

int hashfun(HashTable *hashTable, char *key, int len);

HashTable* initHashTable(int capacity);

void transfer(LinkListNode *oldHashTable, HashTable *hashTable, int newCapacity);

void resize(int newCapacity, HashTable *hashTable);

void put(HashTable *hashTable, int kLen, char *key, int vLen, char *value);

DataNode *get(HashTable *hashTable, int kLen, char *key);

bool move(HashTable *hashTable, int kLen, char *key);

#endif //SIMPLEREDIS_HASH_TABLE_H
