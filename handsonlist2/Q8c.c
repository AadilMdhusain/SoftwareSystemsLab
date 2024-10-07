/* 
=================================================================================================
NAME : Q8c.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a seperate program using signal system call to catch the following signals.
(c) SIGFPE
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("Overflow\n");
    exit(1);
}

int main(){

    signal(SIGFPE,signalhandler);
    int a = 3;
    int b = 0;
    a = a/b;
    while(1);
    // scanf("%f",&b);
    // a = a/b;
}

//=============================OUTPUT=====================================
aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q8c.c
aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
Overflow
