//
// Created by xuyetao on 2019/3/28.
//

#ifndef SIMPLEREDIS_LINKLIST_H
#define SIMPLEREDIS_LINKLIST_H

#include "DataNode.h"
#include <stdlib.h>
#include <stdio.h>

struct LinkListNode {
    DataNode *data;
    LinkListNode *next;
};

void insert(LinkListNode *head, DataNode *dataNode);

void append(LinkListNode *head, DataNode *dataNode);

bool remove(LinkListNode *head, int kLen, char *key);

DataNode* find(LinkListNode *head, int kLen, char *key);

#endif //SIMPLEREDIS_LINKLIST_H
