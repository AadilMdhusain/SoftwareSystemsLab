/* 
=================================================================================================
NAME : Q33.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to communicate between two machines using socket.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client!";
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Sending message to the server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server.\n");

    // Reading response from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("Response from server: %s\n", buffer);

    // Closing the socket
    close(sock);
    return 0;
}

//====================OUTPUT==============================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./client
// Message sent to server.
// Response from server: Message received!

