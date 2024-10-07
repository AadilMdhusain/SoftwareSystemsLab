/* 
=================================================================================================
NAME : Q34b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to create a concurrent server.
(a) use pthread_create
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg); // Free the allocated memory for socket descriptor
    char buffer[BUFFER_SIZE];
    int valread;

    // Read message from client
    valread = read(client_socket, buffer, BUFFER_SIZE);
    buffer[valread] = '\0'; // Null-terminate the string
    printf("Message from client: %s\n", buffer);

    // Send a response back to the client
    const char *response = "Message received!";
    send(client_socket, response, strlen(response), 0);
    printf("Response sent to client.\n");

    // Close the client socket
    close(client_socket);
    return NULL;
}

int main() {
    int server_fd, *client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Binding the socket to the specified port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accepting a connection
        client_socket = malloc(sizeof(int));
        if ((*client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            free(client_socket);
            continue;
        }

        // Create a new thread to handle the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, client_socket) != 0) {
            perror("pthread_create failed");
            free(client_socket);
            continue;
        }

        // Detach the thread so it can clean up after itself
        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}

//====================OUTPUT==============================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q34b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Server listening on port 8080...
// Message from client: Hello from client!
// Response sent to client.