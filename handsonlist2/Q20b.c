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
    
    // Open the FIFO for reading
    char message[100];

    while (1) {
        // Open the FIFO for reading
        int fd = open(fifo_name, O_RDONLY);
        read(fd, message, sizeof(message));

        // Exit condition: check if the message is empty
        if (strlen(message) == 0) {
            break; // Exit loop if no message is received
        }

        printf("Received: %s\n", message);
        close(fd);
    }

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