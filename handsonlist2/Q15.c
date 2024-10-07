/* 
=================================================================================================
NAME : Q15.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a simple program to send some data from parent to the child process.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int pipefd[2];
    if(pipe(pipefd) == -1){
        perror("Failed\n");
        exit(EXIT_FAILURE);
    }
    int pid;
    char buffer[50];
    pid = fork();

    if(pid<0){
        perror("Fork failed\n");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
        close(pipefd[1]);
        ssize_t numBytes = read(pipefd[0], buffer, sizeof(buffer));
        buffer[numBytes] = '\0'; 
        printf("Data Sent by Parent: ");
        printf("%s\n",buffer);
        close(pipefd[0]);

    }
    else{
        close(pipefd[0]);
        char* data = "Hi! I am the parent process";
        write(pipefd[1],data, strlen(data)+1);
        close(pipefd[1]);
        wait(NULL);
    }

    return 0;
}

//======================OUTPUT============================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q15.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Data Sent by Parent: Hi! I am the parent process
