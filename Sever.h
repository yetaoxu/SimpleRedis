//
// Created by xuyetao on 2019/3/31.
//

#ifndef SIMPLEREDIS_SEVER_H
#define SIMPLEREDIS_SEVER_H

const int protocol_version = 1;

int listening();

int acceptClient(int fd);

void fullRecv(int fd, char* buff, int len);

void recvVersionNum(int fd, int num);

void recvOrder(int fd, char *orderName);

#endif //SIMPLEREDIS_SEVER_H
