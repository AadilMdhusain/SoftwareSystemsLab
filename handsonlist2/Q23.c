/* 
=================================================================================================
NAME : Q23.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to print the maximum number of files can be opened within a process 
and size of a pipe (circular buffer).
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/resource.h>

int main() {
    // Get the maximum number of file descriptors
    struct rlimit rl;
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("Maximum number of open files: soft limit = %lu, hard limit = %lu\n", rl.rlim_cur, rl.rlim_max);

    // Create a pipe
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Get the size of the pipe buffer
    int pipe_size;
    if (ioctl(pipe_fd[0], FIONREAD, &pipe_size) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    printf("Size of the pipe buffer: %d bytes\n", pipe_size);

    // Close the pipe file descriptors
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    return 0;
}


//============================OUTPUT===================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q23.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Maximum number of open files: soft limit = 1024, hard limit = 1048576
// Size of the pipe buffer: 0 bytes