/* 
=================================================================================================
NAME : Q14.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a simple program to create a pipe, write to the pipe, read from the pipe and display on
the monitor.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
        close(pipefd[0]);
        char* data = "Hi! I am the child process";
        write(pipefd[1],data, strlen(data)+1);
        close(pipefd[1]);

    }
    else{
        close(pipefd[1]);
        sleep(5);
        ssize_t numBytes = read(pipefd[0], buffer, sizeof(buffer));
        buffer[numBytes] = '\0'; 
        printf("%s\n",buffer);
        close(pipefd[0]);
    }

    return 0;
}

//====================OUTPUT======================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q14.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Hi! I am the child process
