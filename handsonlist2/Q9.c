/* 
=================================================================================================
NAME : Q9.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to ignore a SIGINT signal than reset the default action of the SIGINT
signal - Use signal system call.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void new_signalHandler(int signo){
    printf("doing Nothing\n");
    return;
}
void default_signalHandler(int signo){
    printf("SIGINT recived:\n");
    exit(1);
}

int main(){

    signal(SIGINT,new_signalHandler);
    printf("Press Ctrl + C(will do nothing)\n");

    sleep(5);

    printf("Press Ctrl + C(reset to default)\n");
    signal(SIGINT,default_signalHandler);
    while(1);

}

//===========================OUTPUT============================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q9.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Press Ctrl + C(will do nothing)
// ^Cdoing Nothing
// Press Ctrl + C(reset to default)
// ^CSIGINT recived: