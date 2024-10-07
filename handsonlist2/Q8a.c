/* 
=================================================================================================
NAME : Q8a.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a seperate program using signal system call to catch the following signals.
(a) SIGSEGV
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("Segmentation fault occured\n");
    exit(1);
}
int main(){

    signal(SIGSEGV,signalhandler);
    int *p = NULL;
    *p = 42; 
    return 0;

}

//=======================OUTPUT======================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q8a.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Segmentation fault occured