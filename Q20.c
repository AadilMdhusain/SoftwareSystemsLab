/* 
=================================================================================================
NAME : Q20.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : FIND OUT THE PRIORITY OF YOUR RUNNING PROGRAM. MODIFY THE PRIORITY WITH NICE 
COMMAND.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){

    int pid =getpriority(PRIO_PROCESS,0);

    printf("The previous Priority is : %d \n", pid);

    int newpriotity = nice(13);

    int priority = getpriority(PRIO_PROCESS,0);

    printf("The new Priority : %d \n", priority);

    return 0;
}


//-----------OUTPUT----------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q20.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The previous Priority is : 0 
// Pirority : 13 
