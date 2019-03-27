//
// Created by xuyetao on 2019/3/28.
//

#include "HashTable.h"

#include <iostream>

extern HashTable *globalHashTable;

void put(string key, string value) {

    DataNode *dataNode = new DataNode();

    dataNode->key = key;
    dataNode->value = value;

    int a = globalHashTable->size;

    cout << a << endl;
}