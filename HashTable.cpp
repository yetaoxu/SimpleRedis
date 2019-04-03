//
// Created by xuyetao on 2019/3/28.
//

#include <stdlib.h>
#include "HashTable.h"

int hash(HashTable *hashTable, char *key, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += (key[i] * 91 << 2) * 17 - 127;
    }
    return sum % hashTable->capacity;
}

HashTable* initHashTable(int capacity) {
    HashTable* hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->capacity = capacity;
    hashTable->size = 0;
    hashTable->repos = (LinkListNode *)malloc(sizeof(LinkListNode) * capacity);
    printf("initHashTable succeed! \n");
    return hashTable;
}

void put(HashTable *hashTable, int kLen, char *key, int vLen, char *value) {
    DataNode *dataNode = (DataNode *)malloc(sizeof(dataNode));
    dataNode->kLen = kLen;
    dataNode->key = key;
    dataNode->vLen = vLen;
    dataNode->value = value;

    int bucketIndex = hash(hashTable, key, kLen);
    LinkListNode *head = hashTable->repos + bucketIndex;
    if (head == nullptr) {
        head = (LinkListNode *)malloc(sizeof(LinkListNode));
    }

    insert(head, dataNode);

    hashTable->size++;
}

DataNode *get(HashTable *hashTable, int kLen, char *key) {
    int bucketIndex = hash(hashTable, key, kLen);
    LinkListNode *head = hashTable->repos + bucketIndex;
    if (head == nullptr) {
        return nullptr;
    }
    return find(head, kLen, key);
}

bool remove(HashTable *hashTable, int kLen, char *key) {
    int bucketIndex = hash(hashTable, key, kLen);
    LinkListNode *head = hashTable->repos + bucketIndex;
    if (head == nullptr) {
        return false;
    }
    bool removed = remove(head, kLen, key);
    if (removed) {
        hashTable->size--;
    }
    return removed;
}
