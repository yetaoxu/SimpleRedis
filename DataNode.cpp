//
// Created by xuyetao on 2019/3/28.
//

#include "DataNode.h"

bool isEqual(DataNode *left, DataNode *right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left == nullptr || right == nullptr) {
        return false;
    }
    if (left->kLen != right->kLen) {
        return false;
    }
    for (int i = 0; i < left->kLen; i++) {
        if (left->key[i] != right->key[i]) {
            return false;
        }
    }
    return true;
}

bool isEqual(int lkLen, char *lKey, int rkLen, char *rKey) {
    if (lkLen != rkLen) {
        return false;
    }
    for (int i = 0; i < lkLen; i++) {
        if (lKey[i] != rKey[i]) {
            return false;
        }
    }
    return true;
}

