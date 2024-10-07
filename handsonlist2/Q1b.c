/* 
=================================================================================================
NAME : Q1b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Q1. Write a seperate program (fro each time domain) to set a time interval timer in 10
sec and 10 micro second. 
(b) ITIMER_VIRTUAL
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int sig_no){
    printf("Virtual Timer Expired\n");
}

int main(){

    struct itimerval timer;
    signal(SIGVTALRM, signalHandler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 5;

    setitimer(ITIMER_VIRTUAL,&timer,NULL);

    while(1);
    return 0;


}

//=======================OUTPUT==============================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q1b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Virtual Timer Expired
// Virtual Timer Expired