/* 
=================================================================================================
NAME : Q4.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>


int main(){

    int fd = open("newfile.txt", O_RDWR | O_EXCL);

    printf("The file descriptor value : %d \n", fd);
    return 0;
}

//--------------------------OUTPUT-----------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q4.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The file descriptor value : 3 