/* 
=================================================================================================
NAME : Q25.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO CREATE THREE CHILD PROCESS. THE PARENT SHOULD WAIT FOR A PARTICULAR
CHILD (USE WAITPID SYSTEM CALL).
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    int status;

    printf("Parent : %d \n", getpid());

    pid_t pid = fork();

    if(pid==0){
         sleep(2);
         printf("Child %d\n", getpid());
         exit(EXIT_SUCCESS);
    }

    pid_t pid1 = fork();

    if(pid1==0){
         sleep(3);
         printf("Child %d\n", getpid());
         exit(EXIT_SUCCESS);
    }

    pid_t pid2 = fork();

    if(pid2==0){
        sleep(4);
         printf("Child %d\n", getpid());
         exit(EXIT_SUCCESS);
    }

    waitpid(pid, &status, 0);

    printf("Parent : %d \n", getpid());

    return 0;

}

//----------------OUTPUT----------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q25.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Parent : 5573 
// Child 5574
// Parent : 5573 
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ Child 5575
// Child 5576