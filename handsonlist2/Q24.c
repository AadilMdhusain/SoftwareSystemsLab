/* 
=================================================================================================
NAME : Q24.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to create a message queue and print the key and message queue id.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

int main(){
    key_t key =12;
    int msgq_id = msgget(key, 0666 | IPC_CREAT);
    if( msgq_id== -1){
        perror("Message queue failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Message Queue Key: %d\n",key);
    printf("Message Queue ID: %d\n",msgq_id);
    return 0;
}

//========================OUTPUT=========================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q24.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Message Queue Key: 12
// Message Queue ID: 6
