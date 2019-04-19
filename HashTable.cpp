//
// Created by xuyetao on 2019/3/28.
//

#include <stdlib.h>
#include "HashTable.h"
#include <cstring>
#include <string.h>

int hashfun(HashTable *hashTable, char *key, int len) {
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
    for (LinkListNode *t = hashTable->repos; t != hashTable->repos + capacity; t++) {
        t->data = nullptr;
        t->next = nullptr;
    }
    printf("initHashTable succeed! \n");
    return hashTable;
}

void transfer(LinkListNode *copyHashTable, HashTable *hashTable, int newCapacity) {
    int oldCapacity = hashTable->capacity;
    hashTable->capacity = newCapacity;
    hashTable->size = 0;
    hashTable->repos = (LinkListNode *)malloc(sizeof(LinkListNode) * newCapacity);
    for (LinkListNode *t = hashTable->repos; t != hashTable->repos + newCapacity; t++) {
        t->data = nullptr;
        t->next = nullptr;
    }
    for (LinkListNode *temp = copyHashTable; temp != copyHashTable + oldCapacity; temp++) {
        LinkListNode* cur = temp;
        while (cur->data != nullptr) {
            int bucketIndex = hashfun(hashTable, cur->data->key, cur->data->kLen);
            LinkListNode *head = hashTable->repos + bucketIndex;
            insert(head, cur->data);
            hashTable->size++;

            printf("new size : %d\n", hashTable->size);
            printf("cur key : %s\n", cur->data->key);
            if (cur->next == nullptr) {
                break;
            }
            cur = cur->next;
        }
    }
}

void resize(int newCapacity, HashTable *hashTable) {
    LinkListNode *copyHashTable = (LinkListNode *)malloc(sizeof(LinkListNode) * hashTable->capacity);
    for (LinkListNode *t = copyHashTable; t !=copyHashTable + hashTable->capacity; t++) {
        t->data = nullptr;
        t->next = nullptr;
    }
    LinkListNode *temp1 = hashTable->repos;
    LinkListNode *temp2 = copyHashTable;
    while (temp1 != hashTable->repos + hashTable->capacity) {
        LinkListNode *cur1 = temp1;
        LinkListNode *cur2 = temp2;
        while (cur1->data != nullptr) {
            if (cur2->data == nullptr) {
                DataNode *tempDataNode = (DataNode *)malloc(sizeof(DataNode));
                tempDataNode->kLen = cur1->data->kLen;
                tempDataNode->key = (char *)malloc(sizeof(char) * cur1->data->kLen);
                memcpy(tempDataNode->key, cur1->data->key, cur1->data->kLen);
                tempDataNode->vLen = cur1->data->vLen;
                tempDataNode->value = (char *)malloc(sizeof(char) * cur1->data->vLen);
                memcpy(tempDataNode->value, cur1->data->value, cur1->data->vLen);
                cur2->data = tempDataNode;
            }
            if (cur1->next != nullptr) {
                LinkListNode *newNode = (LinkListNode *)malloc(sizeof(LinkListNode));
                newNode->data = nullptr;
                newNode->next = nullptr;
                cur2->next = newNode;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        temp1++;
        temp2++;
    }
    transfer(copyHashTable, hashTable, newCapacity);
}

void put(HashTable *hashTable, int kLen, char *key, int vLen, char *value) {
    DataNode *dataNode = (DataNode *)malloc(sizeof(DataNode));
    dataNode->kLen = kLen;
    dataNode->key = (char *)malloc(sizeof(char) * kLen);
    memcpy(dataNode->key, key, kLen);
    dataNode->vLen = vLen;
    dataNode->value = (char *)malloc(sizeof(char) * vLen);
    memcpy(dataNode->value, value, vLen);
    int bucketIndex = hashfun(hashTable, key, kLen);
    LinkListNode *head = hashTable->repos + bucketIndex;
    insert(head, dataNode);
    hashTable->size++;
    int f = hashTable->size / hashTable->capacity;
    if (f >= 2) {
        printf("begin to resize : enlarge quadruple... \n");
        resize(hashTable->capacity * 4, hashTable);
    }
}

DataNode *get(HashTable *hashTable, int kLen, char *key) {
    int bucketIndex = hashfun(hashTable, key, kLen);
    LinkListNode *head = hashTable->repos + bucketIndex;
    return find(head, kLen, key);
}

bool move(HashTable *hashTable, int kLen, char *key) {
    int bucketIndex = hashfun(hashTable, key, kLen);
    LinkListNode *head = hashTable->repos + bucketIndex;
    if (head == nullptr) {
        return false;
    }
    bool removed = remove(head, kLen, key);
    if (removed) {
        hashTable->size--;
        int f = hashTable->capacity / hashTable->size;
        if (f >= 2)
            resize(hashTable->capacity / 4, hashTable);
    }
    return removed;
}
