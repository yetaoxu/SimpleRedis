//
// Created by xuyetao on 2019/3/28.
//

#ifndef SIMPLEREDIS_LINKLIST_H
#define SIMPLEREDIS_LINKLIST_H

#include "DataNode.h"

struct LinkList {
    DataNode *head;
};

void append(DataNode *head, DataNode *dataNode);

void remove(DataNode *head, DataNode *dataNode);

void find(DataNode *head, string key);

#endif //SIMPLEREDIS_LINKLIST_H
