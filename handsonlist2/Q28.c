/* 
=================================================================================================
NAME : Q28.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to change the existing message queue permission. {use msqid_ds 
structure}.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(){
    key_t key = ftok("message queue",987);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1){
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    struct msqid_ds info;
    if(msgctl(msgid, IPC_STAT, &info) == -1) {
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    printf("Current permissions %o\n",info.msg_perm.mode);
    info.msg_perm.mode = 0644;


    if(msgctl(msgid, IPC_SET, &info) == -1) {
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }

    if(msgctl(msgid, IPC_STAT, &info) == -1) {
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    printf("Updated permissions %o\n",info.msg_perm.mode);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;

}

//========================OUTPUT=================================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q28.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Current permissions 666
// Updated permissions 644
