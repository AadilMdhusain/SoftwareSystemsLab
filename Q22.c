/* 
=================================================================================================
NAME : Q22.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM, OPEN A FILE, CALL A FORK, AND THEN WRITE TO THE FILE BY BOTH THE 
CHILD AS WELL AS THE PARENT PROCESSES. CHECK OUTPUT OF THE FILE.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>

int main(){

    int fd = open("writefork.txt", O_WRONLY);
    char *c= (char*)calloc(100, sizeof(char));
    fork();

    c="Writing to the file after calling fork()";

    write(fd, c, 40);

    close(fd);

}

//---------------------OUTPUT-------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q22.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
//----------OUTPUT IN THE FILE------------------------------
// Writing to the file after calling fork()Writing to the file after calling fork()
