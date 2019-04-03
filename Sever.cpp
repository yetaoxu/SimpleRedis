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

int listening() {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8000);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);
    int struct_len = sizeof(struct sockaddr_in);
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(fd, (struct sockaddr *) &server_addr, struct_len) != 0) {
        printf("error when binding\n");
        return -1;
    }
    printf("Bind success!\n");
    if (listen(fd, 10) != 0) {
        printf("error when listening");
        return -1;
    }
    printf("listening! waiting for accept...\n");
    return fd;
}

int acceptClient(int fd) {
    int struct_len = sizeof(struct sockaddr_in);
    int newFd;
    char cli_ip[INET_ADDRSTRLEN] = "";
    struct sockaddr_in client_addr;
    socklen_t cliaddr_len = sizeof(client_addr);
    newFd = accept(fd, (struct sockaddr *) &client_addr, (socklen_t * ) & struct_len);
    printf("Get the Client!\n");
    return newFd;
}

void fullRecv(int fd, char* buff, int len) {
    char* starPoint = buff;
    int remain = len;
    while (remain > 0) {
        int recvLen = (int)recv(fd, starPoint, remain, 0);
        remain = remain - recvLen;
        starPoint = starPoint + recvLen;
    }
}

void recvVersionNum(int fd, int num) {
    fullRecv(fd, (char* )&num, 4);
}

void recvOrder(int fd, char *orderName) {
    int orderNameLen = (int)strlen(orderName);
    fullRecv(fd, (char* )&orderNameLen, 4);
    fullRecv(fd, orderName, orderNameLen);
}