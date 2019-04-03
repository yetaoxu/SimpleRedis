//
// Created by xuyetao on 2019/3/31.
//
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int connectToSever() {
    int fd;
    struct sockaddr_in client_addr;
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("create socket error");
        return -1;
    }
    printf("We get the sockfd\n");
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(8000);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&(client_addr.sin_zero), 8);
    if (connect(fd, (struct sockaddr *) &client_addr, sizeof(struct sockaddr)) != 0) {
        printf("error when connect.\n");
        return -1;
    }
    printf("connect the server!\n");
    return fd;
}

void fullSend(int fd, char* buff, int len) {
    char* startPoint = buff;
    int remain = len;
    while (remain > 0) {
        int sendLen = (int)send(fd, startPoint, remain, 0);
        remain -= sendLen;
        startPoint += sendLen;
    }
}

void sendVersionNum(int fd, int num) {
    fullSend(fd, (char* )&num, 4);
}

void sendOrder(int fd, char *orderName) {
    int orderNameLen = (int)strlen(orderName);
    fullSend(fd, (char* )&orderNameLen, 4);
    fullSend(fd, orderName, orderNameLen);
}

