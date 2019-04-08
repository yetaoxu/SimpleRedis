//
// Created by xuyetao on 2019/3/31.
//

#ifndef SIMPLEREDIS_SEVER_H
#define SIMPLEREDIS_SEVER_H

const int protocolVersion = 1;

int listening();

void fullRecv(int fd, char* buff, int len);

char *recvOrder(int fd);

#endif //SIMPLEREDIS_SEVER_H
