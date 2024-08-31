/* 
=================================================================================================
NAME : Q18b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO PERROM RECORD LOCKING -
(A) IMPLEMENT READ LOCK
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

#define max_record = 5;

int main(void){

    struct flock lock;
    struct record r1;
    int cont=1,fd;
    int input;
    fd = open("db.txt",O_RDONLY,777);
    do{
    printf("Enter the record number you want to read (less than 5)\n");
    scanf("%d",&input);
    }while(input>5);
        lseek(fd, (input-1)*sizeof(r1), SEEK_SET);
        lock.l_type=F_RDLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=(input-1)*sizeof(r1);
        lock.l_len=sizeof(r1);
        lock.l_pid=getpid();
        printf("Setting the lock on the record\n");

        fcntl(fd, F_SETLKW, &lock);
        printf("We have set the lock, press enter to continue \n");
        getchar();
        getchar();

        read(fd, &r1, sizeof(r1));
        printf("The data has been read from the file\n");

        printf("The integer value read from the file %d \n", r1.number);
        printf("The char array value read from the file %s \n", r1.info);

        lock.l_type=F_UNLCK;
        fcntl(fd,F_SETLK, &lock);
    
    close(fd);

    return 0;
}

//---------------------------OUTPUT------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q18b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Enter the record number you want to read (less than 5)
// 1
// Setting the lock on the record
// We have set the lock, press enter to continue 

// The data has been read from the file
// The integer value read from the file 1 
// The char array value read from the file Aadil 
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q18b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Enter the record number you want to read (less than 5)
// 2
// Setting the lock on the record
// We have set the lock, press enter to continue 

// The data has been read from the file
// The integer value read from the file 2 
// The char array value read from the file Ashraf 
