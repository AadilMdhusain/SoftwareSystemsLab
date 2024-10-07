/* 
=================================================================================================
NAME : Q10b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a separate program using sigaction system call to catch the following signals.
(b) SIGINT
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signalHandler(int signo, siginfo_t *info, void *context){
    printf("SIGINT received\n");
    printf("Signal Number: %d\n",signo);
    printf("Signal source PID: %d\n", info->si_pid);
    printf("Signal source UID: %d\n", info->si_uid);
    exit(1);
}

int main(){

    struct sigaction sig_config;
    sig_config.sa_sigaction = signalHandler;
    sig_config.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &sig_config, NULL);

    printf("Press Ctrl + C \n");
    while(1);

    return 0;
}

//=========================OUTPUT===================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q10b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Press Ctrl + C 
// ^CSIGINT received
// Signal Number: 2
// Signal source PID: 0
// Signal source UID: 0