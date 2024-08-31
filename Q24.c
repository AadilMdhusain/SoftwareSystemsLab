/* 
=================================================================================================
NAME : Q24.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO CREATE AN ORPHAN PROCESS.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int pid = fork();

    if (pid>0)
        printf("In parent process\n");
    
    else if(pid == 0)
    {
        sleep(5);
        printf("In child process\n");
    }

    return 0;
    
}

//OUTPUT OF THE PROGRAM -
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q24.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// In parent process
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ In child process
