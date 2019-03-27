//
// Created by xuyetao on 2019/3/28.
//

#ifndef SIMPLEREDIS_HASH_TABLE_H
#define SIMPLEREDIS_HASH_TABLE_H

#include "DataNode.h"
#include "LinkList.h"

struct HashTable {
    int size;
    LinkList *repos;
};

int hashFunction(string key);

void put(string key, string value);

string get(string key);

void remove(string key);

#endif //SIMPLEREDIS_HASH_TABLE_H
