/* 
=================================================================================================
NAME : Q29.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to remove the message queue.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int main() {
    key_t key = ftok("msgqueue", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Message queue created with ID: %d\n", msgid);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID failed");
        return EXIT_FAILURE;
    }

    printf("Message queue removed successfully.\n");

    return EXIT_SUCCESS;
}

//==========================OUTPUT===================================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q29.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Message queue created with ID: 0
// Message queue removed successfully.
