//
// Created by xuyetao on 2019/3/28.
//

#ifndef SIMPLEREDIS_DATANODE_H
#define SIMPLEREDIS_DATANODE_H

using namespace std;

struct DataNode {
    int kLen;
    char *key;
    int vLen;
    char *value;
    struct DataNode *next;
};

bool isEqual(DataNode *left, DataNode *right);

bool isEqual(int lkLen, char *lKey, int rkLen, char *rKey);

#endif //SIMPLEREDIS_DATANODE_H
