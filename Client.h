//
// Created by xuyetao on 2019/3/31.
//

#ifndef SIMPLEREDIS_CLIENT_H
#define SIMPLEREDIS_CLIENT_H

int connectToSever();

void fullSend(int fd, char* buff, int len);

void sendVersionNum(int fd, int num);

void sendOrder(int fd, char *orderName);

#endif //SIMPLEREDIS_CLIENT_H
