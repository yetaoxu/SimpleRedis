//
// Created by xuyetao on 2019/4/2.
//

#include "Interaction.h"
#include <cstring>
#include <zconf.h>

const int BUF_SIZE=1024;

void startInteract(HashTable *hashTable) {
    char key[BUF_SIZE];
    char value[BUF_SIZE];

    DataNode *dataNode;
    int fd1 = listening();
    int fd2 = connectToSever();
    int newFd = acceptClient(fd1);

    char closeOrder[10] = "CLOSE";
    char putOrder[10] = "PUT";
    char removeOrder[10] = "DELETE";
    char getOrder[10] = "GET";

    char orderName[BUF_SIZE];
    int kLen;
    int vLen;
    int magicNumber = 1;
    while (true) {
        if (protocol_version != magicNumber) {
            break;
        } else {
            printf(">>");
            scanf("%s", orderName);
            sendOrder(fd2, orderName);
            recvOrder(newFd, orderName);

            if(strcmp(orderName, closeOrder) == 0) {
                break;
            } else if (strcmp(orderName, putOrder) == 0) {
                scanf("%s %s", key, value);
                kLen = (int)strlen(key);
                vLen = (int)strlen(value);
                put(hashTable, kLen, key, vLen, value);
                printf("OK!\n");
            } else if (strcmp(orderName, getOrder) == 0) {
                scanf("%s", key);
                dataNode = get(hashTable, kLen, key);
                if (dataNode == nullptr) {
                    printf("null\n");
                } else {
                    printf("%s\n", dataNode->value);
                }
            } else if (strcmp(orderName, removeOrder) == 0) {
                scanf("%s", key);
                remove(hashTable, kLen, key);
                printf("OK!\n");
            } else {
                printf("unknown command...\n");
            }
        }
    }
    close(fd1);
    close(fd2);
    close(newFd);
    printf("bye bye!\n");
}