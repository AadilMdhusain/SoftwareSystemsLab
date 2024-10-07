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

int main(){
    int pid;
    system("pgrep a.out");
    printf("Enter The above process id: ");
    scanf("%d",&pid);
    printf("\nSending SIGSTOP\n");
    kill(pid,SIGSTOP);
    printf("SIGSTOP SENT\n");
    return 0;

    
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