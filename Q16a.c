/* 
=================================================================================================
NAME : Q16a.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO DISPLAY THE MANDATORY LOCKING-
(a) IMPLEMENT WRITE LOCK
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){

    struct flock lock;
    int fd;

    fd = open("write.txt", O_RDWR);
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();

    printf("Before entering into the critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section.....\n");
    printf("Enter to unlock..\n");
    getchar();
    printf("unlocked\n");
    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Finish\n");
}

//-------------------------OUTPUT--------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q16a.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Before entering into the critical section
// Inside the critical section.....
// Enter to unlock..

// unlocked
// Finish