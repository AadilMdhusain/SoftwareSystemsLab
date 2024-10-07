/* 
=================================================================================================
NAME : Q8b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a seperate program using signal system call to catch the following signals.
(b) SIGINT
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("SIGINT Signal recived\n");
    exit(1);
}

int main(){

    signal(SIGINT,signalhandler);
    printf("Press Ctrl C\n");
    while(1);
}

//========================OUTPUT=============================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q8b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Press Ctrl C
// ^CSIGINT Signal recived