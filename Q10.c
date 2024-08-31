/* 
=================================================================================================
NAME : Q10.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO OPEN A FILE WITH READ WRITE MODE, WRITE 10 BYTES, MOVE THE FILE
POINTER BY 10 BYTES(USE LSEEK) AND WRITE AGAIN 10 BYTES
(a) CHECK THE RETURN VALUE OF LSEEK
(b) OPEN THE FILE WITH OD AND CHECK THE EMPTY SPACES IN BETWEEN THE DATA
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){

    int fd, sz;
    char *c = (char*)calloc(100,sizeof(char));
    char *str1 = "This is a string to check our output";

    fd = open("NewFile.txt", O_RDWR | O_EXCL);

    write(fd, str1, 10);
    
    int out = lseek(fd, 10, SEEK_CUR);

    printf("The result we received from the lseek is : %d \n",out);

    write(fd, str1, 10);

    close(fd);
    return 0;    
}

//-----------------------------OUTPUT--------------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q10.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The result we received from the lseek is : 20 
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ od -c NewFile.txt
// 0000000   T   h   i   s       i   s       a      \0  \0  \0  \0  \0  \0
// 0000020  \0  \0  \0  \0   T   h   i   s       i   s       a    
// 0000036