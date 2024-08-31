/* 
=================================================================================================
NAME : Q11b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO OPEN A FILE, DUPLICATE THE FILE DESCRIPTOR AND APPEND THE FILE 
WITH BOTH THE DESCRIPTORS AND CHECK WHETHER THE FILE IS UPDATED PROPERLY OR NOT.
(b) USE DUP2
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd;
    char *str = (char*)calloc(200,sizeof(char));

    fd = open("stdinput.txt", O_RDWR | O_APPEND );

    if(fd<0){
        printf("An Error had occurred\n");
        exit(EXIT_FAILURE);
    }

    dup2(fd, 101);

    write(101, "This string is written from the Copy of the file descriptor. ", 61);

    write(fd,"This string is written from the original file descriptor.",57);

    lseek(fd, -118, SEEK_CUR);

    read(fd, str, 200);

    printf("The string that we read from the file:\n %s", str);

    return 0;
}

//-----------------------OUTPUT----------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q11b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The string that we read from the file:
//  is string is written from the Copy of the file descriptor created using fcntl. 
// This string is written from the original file descriptor.
