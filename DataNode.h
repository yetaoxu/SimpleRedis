//
// Created by xuyetao on 2019/3/28.
//

#ifndef SIMPLEREDIS_DATANODE_H
#define SIMPLEREDIS_DATANODE_H

struct DataNode {
    int vLen;
    int kLen;
    char *key;
    char *value;
};

bool isEqual(DataNode *left, DataNode *right);

bool isEqual(int lkLen, char *lKey, int rkLen, char *rKey);

#endif //SIMPLEREDIS_DATANODE_H
