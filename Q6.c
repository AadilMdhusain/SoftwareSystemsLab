/* 
=================================================================================================
NAME : Q6.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO TAKE INPUT FROM STDIIN AND DISPLAY ON STDOUT. USE ONLY READ/WRITE
SYSTEMS CALLS.
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd, sz;
    char *c = (char*) calloc(100,sizeof(char));

    fd = open("stdinput.txt",O_RDONLY);

    sz = read(fd, c, 10);
    c[sz]='\0';
    
    printf("The input taken from STDIN is : %s \n", c);

    int fd1 = open("stdout.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    write(fd1, c, strlen(c)); 

    printf("The write operation has been successful.\n");

    close(fd);
    close(fd1);
    return 0;
}

//----------------------OUTPUT----------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q6.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The input taken from STDIN is : Python is  
// The write operation has been successful.
