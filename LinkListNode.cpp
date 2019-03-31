//
// Created by xuyetao on 2019/3/28.
//

#include "LinkListNode.h"

void insert(LinkListNode *head, DataNode *dataNode) {
    if (head == nullptr) {
        return;
    }
    LinkListNode *curr = head;
    while (true) {
        if (curr->data == nullptr) {
            curr->data = dataNode;
            return;
        }
        if (isEqual(curr->data, dataNode)) {
            curr->data = dataNode;
            return;
        }
        if (curr->next == nullptr) {
            LinkListNode *newNode = (LinkListNode *)malloc(sizeof(LinkListNode));
            newNode->next = NULL;
            newNode->data = dataNode;
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    }
}

void append(LinkListNode *head, DataNode *dataNode) {
    if (head->data == nullptr) {
        head->data = dataNode;
        return;
    }

    while (head->next != NULL) {
        head = head->next;
    }
    LinkListNode *newNode = (LinkListNode *)malloc(sizeof(LinkListNode));
    newNode->next = NULL;
    newNode->data = dataNode;
    head->next = newNode;
}

bool remove(LinkListNode *head, int kLen, char *key) {
    if (head == nullptr) {
        return false;
    }
    if (head->data != nullptr && isEqual(head->data->kLen, head->data->key, kLen, key)) {
        if (head->next != nullptr) {
            head->data = head->next->data;
            head->next = head->next->next;
            free(head->next);
            return true;
        } else {
            head->data = nullptr;
        }
    }
    LinkListNode *prev = head;
    LinkListNode *curr = head->next;
    while (curr != nullptr) {
        if (curr->data != nullptr && isEqual(curr->data->kLen, curr->data->key, kLen, key)) {
            prev->next = curr->next;
            free(curr);
            return true;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}

DataNode* find(LinkListNode *head, int kLen, char *key) {
    if (head == nullptr) {
        return nullptr;
    }
    LinkListNode *curr = head;
    while (curr != nullptr) {
        if (curr->data != nullptr && isEqual(curr->data->kLen, curr->data->key, kLen, key)) {
            return curr->data;
        }
        curr = curr->next;
    }
    return nullptr;
}
