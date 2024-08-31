/* 
=================================================================================================
NAME : Q23.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO CREATE A ZOMBIE PROCESS OF THE RUNNING PROGRAM.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    if((pid = fork())<0){
        perror("fork");
        exit(1);
    }

    if(pid==0)
        exit(0);

    sleep(60);
    pid=wait(&status);

    exit(0);
    return 0;
}

//---------------------------OUTPUT--------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q23.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ps -ef | grep a.out
// aadil-m+    5391    5035  0 17:51 pts/0    00:00:00 ./a.out
// aadil-m+    5392    5391  0 17:51 pts/0    00:00:00 [a.out] <defunct>
// aadil-m+    5414    5402  0 17:52 pts/1    00:00:00 grep --color=auto a.out
