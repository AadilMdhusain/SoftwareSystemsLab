/* 
=================================================================================================
NAME : Q16b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO DISPLAY THE MANDATORY LOCKING-
(b) IMPLEMENT READ LOCK
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    char * file = argv[1];

    int fd;

    struct flock lock;

    printf("I am opening the file %s \n", file);

    fd = open(file, O_RDONLY);
    printf("I am locking it buddy \n");

    lock.l_type = F_RDLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();

    fcntl(fd, F_SETLKW, &lock);

    printf("I locked the file, Press Enter to Unlock\n");

    getchar();

    printf("Releasing the lock buddy\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    close(fd);
    return 0;
}

//-------------------OUTPUT-------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q16b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out write.txt
// I am opening the file write.txt 
// I am locking it buddy 
// I locked the file, Press Enter to Unlock

// Releasing the lock buddy
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ 