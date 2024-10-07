/* 
=================================================================================================
NAME : Q8d.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a seperate program using signal system call to catch the following signals.
(d) SIGALRM (use alarm system call)
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("SIGALRM recived\n");
    exit(1);
}

int main(){

    signal(SIGALRM,signalhandler);
    alarm(5);
    while(1);
}

//===========================OUTPUT=================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q8d.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// SIGALRM recived