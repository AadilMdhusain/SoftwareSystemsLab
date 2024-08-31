/* 
=================================================================================================
NAME : Q3.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO CREATE A FILE AND PRINT THE FILE DESCRIPTOR VALUE. USE CREAT() 
SYSTEM CALL.
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/stat.h>

int main(){
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR;
    char *filename = "newfile.txt";

    fd = creat(filename, mode);

    printf("The value of the file descriptor will be %d \n", fd);

    return 0;
}

//-------------------------OUTPUT----------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q3.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The value of the file descriptor will be 3 
