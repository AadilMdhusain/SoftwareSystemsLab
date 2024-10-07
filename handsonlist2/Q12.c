/* 
=================================================================================================
NAME : Q12.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to create an orphan process. Use kill system call to send SIGKILL signal 
to the parent process from the child process.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){

    int id = fork();
    if(id<0){
        perror("Fork failed\n");
        exit(1);
    }

    if(id == 0){
        sleep(5); // waiting for parent to begin execution;
        int parent_pid = getppid();
        printf("Before becoming Orphan Parent Process id: %d\n",parent_pid);
        kill(parent_pid,SIGKILL);
        
        printf("Process has become Orphan\n");
        while(1);
        
    }
    else{
        printf("Waiting for a Signal from Child Process\n");
        sleep(10);
    }

    return 0;
}

//============================OUTPUT========================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q12.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Waiting for a Signal from Child Process
// Before becoming Orphan Parent Process id: 13957
// Process has become Orphan
// Killed
