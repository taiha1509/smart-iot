/* Make the necessary includes and set up the variables. */

#include <sys/types.h>

#include <sys/socket.h>

#include <stdio.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <unistd.h>

int main()
{

    int sockfd;

    int len;

    struct sockaddr_in address;

    int result;

    char s[100];
    printf("Input your message %s\n ", s);
    gets(s);
    printf("your message is: %s", s);

    /* Create a socket for the client. */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Name the socket, as agreed with the server. */

    address.sin_family = AF_INET;

    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    address.sin_port = 5000;

    len = sizeof(address);

    /* Now connect our socket to the server's socket. */

    result = connect(sockfd, (struct sockaddr *)&address, len);

    if (result == -1)
    {

        perror("oops: client2");

        exit(1);
    }

    /* We can now read/write via sockfd. */
    write(sockfd, &s, 100);

    char rs[100];

    read(sockfd, &rs, 100);

    printf("message from server = %s\n", rs);

    close(sockfd);

    exit(0);
}