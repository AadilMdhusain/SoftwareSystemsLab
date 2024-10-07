/* 
=================================================================================================
NAME : Q20.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write two programs so that both can communicate by FIFO -Use one way communication.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "my_fifo";
    
    // Create a FIFO if it doesn't exist
    mkfifo(fifo_name, 0666);

    char message[100];
    
    while (1) {
        printf("Enter a message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        
        // Remove newline character from message
        message[strcspn(message, "\n")] = 0;

        // Exit condition
        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Open the FIFO for writing
        int fd = open(fifo_name, O_WRONLY);
        write(fd, message, strlen(message) + 1); // Include null terminator
        close(fd);
    }

    // Clean up
    unlink(fifo_name); // Remove the FIFO
    return 0;
}

//======================OUTPUT=========================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q20a.c -o oneway
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./oneway
// Enter a message (type 'exit' to quit): Hello
// Enter a message (type 'exit' to quit): Aadil Here
// Enter a message (type 'exit' to quit): I wanted to contact you
// Enter a message (type 'exit' to quit): exit
//......................
//......................
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q20b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Received: Hello
// Received: Aadil Here
// Received: I wanted to contact you
