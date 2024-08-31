/* 
=================================================================================================
NAME : Q21.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM, CALL FORK AND PRINT THE PARENT AND CHILD PROCESS ID.
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(){

    int pid=fork();
    if(pid==0)
    {
    printf("The process id of the child process is : %d \n", getpid());
    printf("The process id of the parent process is : %d \n", getppid());
    }
    sleep(1);
    return 0;
}

//OUTPUT OF THE FOLLOWING FILE IS-
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q21.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The process id of the child process is : 6242 
// The process id of the parent process is : 6241 
