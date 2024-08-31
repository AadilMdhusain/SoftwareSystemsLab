/* 
=================================================================================================
NAME : Q18a.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO PERFORM RECORD LOCKING -
(A) IMPLEMENT WRITE LOCK
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

struct record{
    int number;
    char info[30];
};

int main(void){

    struct flock lock;
    struct record r1;
    int cont=1,fd;
    int input=0;
    fd = open("db.txt",O_WRONLY | O_EXCL,777);
    while(cont==1){

        printf("Enter a number : \n");
        scanf("%d",&r1.number);
        printf("Enter character array : \n");
        scanf("%s",r1.info);
        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=input*sizeof(r1);
        lock.l_len=sizeof(r1);
        lock.l_pid=getpid();
        printf("Setting the lock on the record\n");

        fcntl(fd, F_SETLKW, &lock);
        printf("We have set the lock, press enter to continue \n");
        getchar();
        getchar();

        write(fd, &r1, sizeof(r1));
        printf("The data has been written in the file\n");

        lock.l_type=F_UNLCK;
        fcntl(fd,F_SETLK, &lock);
        input++;
        printf("Do you want to continue: 1 to continue\n");
        scanf("%d", &cont);
    }
    close(fd);

    return 0;
}

//----------------------OUTPUT----------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q18a.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Enter a number : 
// 01
// Enter character array : 
// Aadil
// Setting the lock on the record
// We have set the lock, press enter to continue 

// The data has been written in the file
// Do you want to continue: 1 to continue
// 1
// Enter a number : 
// 02
// Enter character array : 
// Ashraf
// Setting the lock on the record
// We have set the lock, press enter to continue 

// The data has been written in the file
// Do you want to continue: 1 to continue
// 1
// Enter a number : 
// 03
// Enter character array : 
// Ishtiyak
// Setting the lock on the record
// We have set the lock, press enter to continue 

// The data has been written in the file
// Do you want to continue: 1 to continue
// 0
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ 