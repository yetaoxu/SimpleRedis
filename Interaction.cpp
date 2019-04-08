//
// Created by xuyetao on 2019/4/2.
//

#include "Interaction.h"
#include <cstring>
#include <zconf.h>
#include <stdlib.h>
#include <string.h>

const int BUF_SIZE=1024;

void startInteract(HashTable *hashTable) {
    int fd = listening();
    int newFd = acceptClient(fd);
    char closeOrder[10] = "CLOSE";
    char putOrder[10] = "PUT";
    char removeOrder[10] = "DELETE";
    char getOrder[10] = "GET";
    char *returnOk = "OK";
    char *returnNull = "null";
    char *returnNotFound = "Not Found";
    char *returnByeBye = "Bye Bye";
    char *returnUnknowCommand = "Unknow Command";
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
            if(strcmp(orderName, closeOrder) == 0) {
                sendOrder(newFd, returnByeBye);
                break;
            } else if (strcmp(orderName, putOrder) == 0) {
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
            } else if (strcmp(orderName, getOrder) == 0) {
                char *key = (char *)malloc(sizeof(char) * BUF_SIZE);
                memcpy(key, k, strlen(k));
                int kLen = (int)strlen(key);
                DataNode *dataNode = get(hashTable, kLen, key);
                if (dataNode == nullptr) {
                    sendOrder(newFd, returnNull);
                    printf("null\n");

                } else {
                    printf("%s\n", dataNode->value);
                    sendOrder(newFd, dataNode->value);
                }
                free(key);
            } else if (strcmp(orderName, removeOrder) == 0) {
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
    close(fd);
    close(newFd);
    printf("bye bye!\n");
}