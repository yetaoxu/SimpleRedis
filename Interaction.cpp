//
// Created by xuyetao on 2019/4/2.
//

#include "Interaction.h"
#include <cstring>
#include <zconf.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>

const int BUF_SIZE = 1024;
char closeOrder[10] = "CLOSE";
char closeOr[10] = "close";
char putOrder[10] = "PUT";
char putOr[10] = "put";
char removeOrder[10] = "DELETE";
char removeOr[10] = "delete";
char getOrder[10] = "GET";
char getOr[10] = "get";
char *returnOk = "OK";
char *returnNull = "null";
char *returnNotFound = "Not Found";
char *returnByeBye = "Bye Bye";
char *returnUnknowCommand = "Unknow Command";

struct para {
    int fdd;
    HashTable *ht;
};

void *commandHandle(void *parameters) {

    para *t = (para *)parameters;
    int newFd = t->fdd;
    HashTable *hashTable = t->ht;

    int magicNumber = 1;
    while (true) {
        if (protocolVersion != magicNumber) {
            break;
        } else {

            char orderName[BUF_SIZE];
            char k[BUF_SIZE];
            char v[BUF_SIZE];
            char *order = recvOrder(newFd);
            sscanf(order, "%s %s %s", orderName, k, v);
            if(strcmp(orderName, closeOrder) == 0 || strcmp(orderName, closeOr) == 0) {
                sendOrder(newFd, returnByeBye);
                break;
            } else if (strcmp(orderName, putOrder) == 0 || strcmp(orderName, putOr) == 0) {
                char *key = (char *)malloc(sizeof(char) * BUF_SIZE);
                char *value = (char *)malloc(sizeof(char) * BUF_SIZE);
                memcpy(key, k, strlen(k));
                memcpy(value, v, strlen(v));
                int kLen = (int)strlen(key);
                int vLen = (int)strlen(value);
                put(hashTable, kLen, key, vLen, value);
                sendOrder(newFd, returnOk);
                printf("OK!\n");
                free(key);
                free(value);
            } else if (strcmp(orderName, getOrder) == 0 || strcmp(orderName, getOr) == 0) {
                char *key = (char *)malloc(sizeof(char) * BUF_SIZE);
                memcpy(key, k, strlen(k));
                int kLen = (int)strlen(key);
                DataNode *dataNode = get(hashTable, kLen, key);
                if (dataNode == nullptr) {
                    sendOrder(newFd, returnNull);
                    printf("null\n");

                } else {
                    printf("get the value : %s\n", dataNode->value);
                    sendOrder(newFd, dataNode->value);
                }
                free(key);
            } else if (strcmp(orderName, removeOrder) == 0 || strcmp(orderName, removeOr) == 0) {
                char *key = (char *)malloc(sizeof(char) * BUF_SIZE);
                memcpy(key, k, strlen(k));
                int kLen = (int)strlen(key);
                if (move(hashTable, kLen, key)) {
                    sendOrder(newFd, returnOk);
                    printf("OK!\n");
                } else {
                    printf("not found this key.\n");
                    sendOrder(newFd, returnNotFound);
                }
                free(key);
            }
            else {
                sendOrder(newFd, returnUnknowCommand);
                printf("unknown command...\n");
            }
        }

    }
    close(newFd);
    printf("current client disconnect.\n");
    pthread_exit(NULL);
}

void startInteract(HashTable *hashTable) {
    int fd = listening();
    int newFd;
    int n = 2;
    while (true) {
        pthread_t threadId;
        int clientLength = sizeof(struct sockaddr_in);
        struct sockaddr_in client_addr;
        newFd = accept(fd, (struct sockaddr *) &client_addr, (socklen_t * ) &clientLength);

        char clientIp[INET_ADDRSTRLEN] = "";
        inet_ntop(AF_INET, &client_addr.sin_addr, clientIp, INET_ADDRSTRLEN);
        printf("-------------------------------------------\n");
        printf("client ip = %s, port = %d\n", clientIp,ntohs(client_addr.sin_port));

        if (newFd == -1) {
            printf("Accept error! \n");
            exit(0);
        }
        printf("a new connection\n");
        struct para temp;
        temp.fdd = newFd;
        temp.ht = hashTable;
        for (int i = 0; i < n; i++) {

        }
        if (pthread_create(&threadId, NULL, commandHandle, &temp) == -1) {
            printf("pthread create error");
            break;
        }
    }
}