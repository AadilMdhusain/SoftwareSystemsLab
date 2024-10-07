/* 
=================================================================================================
NAME : Q8g.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a seperate program using signal system call to catch the following signals.
(g) SIGPROF (use setitimer system call)
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int sig_no){
    printf("Timer Expired\n");
}

int main(){

    struct itimerval timer;
    signal(SIGPROF, signalHandler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 5;

    setitimer(ITIMER_PROF,&timer,NULL);

    while(1);
    return 0;


}

//=======================OUTPUT================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q8g.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Timer Expired
// Timer Expired
