#include <stdio.h>

#include <fcntl.h> // for open

#include <unistd.h> // for close

#include <string.h>

#include <stdlib.h>

#include <pthread.h>

#include <arpa/inet.h>

#include <sys/socket.h>

#include <netinet/in.h>

#define BUFF_SIZE 2048

#define SERVER_PORT 5001

#define SERVER_ADDR "127.0.0.1"

#define MAX_CLIENT 2

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int countClient = 0;

void *socketThread(void *arg)

{

    char *buff = (char *)malloc(BUFF_SIZE);

    if (buff == NULL)
    {

        // countClient--;

        pthread_exit(NULL);
    }

    // char buff[BUFF_SIZE];

    int ret = 0;

    int connectedSocket = *((int *)arg);

    while (1)
    {

        ret = recv(connectedSocket, buff, BUFF_SIZE, 0);

        if (ret < 0)
        {

            printf("Socket closed.\n");

            // countClient--;

            pthread_exit(0);
        }

        else
        {

            buff[ret] = '\0';

            printf("Receive from client[%d]: %s\n", connectedSocket, buff);

            ret = send(connectedSocket, buff, ret, 0);

            if (ret < 0)
            {

                printf("Socket closed.\n");

                break;
            }
        }
    }

    close(connectedSocket);

    pthread_exit(NULL);
}

int main()
{
    // Step 01: Construct socket

    int listenSock;
    listenSock = socket(AF_INET, SOCK_STREAM, 0);
    // Step 02: Bind address to socket

    struct sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(SERVER_PORT);

    serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    // Set all bits of the padding field to 0

    // memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    int result = bind(listenSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    if (result < 0)
    {

        printf("Error! Cannot bind this address.\n");

        return 0;
    }

    // Step 03: Listen request from client
    int listenRs = listen(listenSock, 10);
    if (listenRs)
    {

        printf("Error! Cannot listen.\n");

        return 0;
    }
    printf("Server started!\n");
    // Step 04: Communicate with client

    int newSocket;

    struct sockaddr_in clientAddr;

    // struct sockaddr_storage serverStorage;

    int clientAddrLen = sizeof(clientAddr);

    int i = 0;

    pthread_t thread_id[MAX_CLIENT + 100];
    while (1)
    {

        if (i < MAX_CLIENT + 1)
        {

            // Accept and create new socket for the incoming connection

            newSocket = accept(listenSock, (struct sockaddr *)&clientAddr, &clientAddrLen);

            printf("Connect new socket: %d\n", newSocket);

            if (pthread_create(&thread_id[i], NULL, socketThread, (void *)&newSocket))
            {

                printf("Create new thread failed.\n");

                exit(EXIT_FAILURE);
            }

            // countClient++;

            i++;
        }
        else
        {

            printf("Cannot create new thread socket.\n");

            // i = 0;

            // while(i < MAX_CLIENT){

            // pthread_join(thread_id[i++], NULL);

            // }

            // i = 0;
        }

        //Now join the thread , so that we dont terminate before the thread

        //pthread_join( thread_id , NULL);

        printf("Handler assigned\n");
    }

    close(listenSock);

    return 0;
}