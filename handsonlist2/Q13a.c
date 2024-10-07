/* 
=================================================================================================
NAME : Q13.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write two programs : first program to catch SIGSTOP signal, the second program will send
the signal (using kill system call). Find out whether the first program is able to catch the signal or
not.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signalHandler(int signo, siginfo_t *info, void* context){
    printf("SIGSTOP signal recived\n");
    exit(1);
}

int main(){

    struct sigaction sig_config;
    sig_config.sa_sigaction = signalHandler;
    sig_config.sa_flags = 0;
    sigaction(SIGSTOP, &sig_config, NULL);
    while(1); 
}

//==============================OUTPUT=============================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// 13801
// 13825
// 13858
// Enter The above process id: 13848

// Sending SIGSTOP
// SIGSTOP SENT
//........................................
//........................................
//........................................
//aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./signal

// [2]+  Stopped                 ./signal

