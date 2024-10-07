/* 
=================================================================================================
NAME : Q8e.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a seperate program using signal system call to catch the following signals.
(e) SIGALRM (use setitimer system call)
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void signalhandler(int sig_no){
    printf("Real-Timer Expired\n");
}
int main(){
    struct itimerval timer; // to set the time
    signal(SIGALRM,signalhandler); // Real time interval sends a SIGALRM 

    timer.it_value.tv_sec = 10; // it_value sets the timer for the first time
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 5; // sets the reccuring interval after which signal will be sent
    timer.it_interval.tv_sec = 5;

    setitimer(ITIMER_REAL,&timer,NULL);

    while(1);
    return 0;

}

//===================OUTPUT============================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q8e.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Real-Timer Expired
// Real-Timer Expired
