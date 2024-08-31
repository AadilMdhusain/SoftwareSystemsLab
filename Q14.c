/* 
=================================================================================================
NAME : Q14.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO FIND THE TYPE OF A FILE.
(a) INPUT SHOULD BE TAKEN FROM COMMAND LINE
(b) PROGRAM SHOULD BE ABLE TO IDENTIFY ANY TYPE OF A FILE.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, char **argv){

    struct stat buf;
    printf("%d\n", argc);
    printf("%s\n", argv[1]);
    
    if(argc==2){
        if(stat(argv[1], &buf)==-1){
            perror("Error opening the file");
        }
            if (S_ISREG(buf.st_mode)) {
        printf("%s is a regular file\n", argv[1]);
    } else if (S_ISDIR(buf.st_mode)) {
        printf("%s is a directory\n", argv[1]);
    } else if (S_ISLNK(buf.st_mode)) {
        printf("%s is a symbolic link\n", argv[1]);
    } else if (S_ISCHR(buf.st_mode)) {
        printf("%s is a character device\n", argv[1]);
    } else if (S_ISBLK(buf.st_mode)) {
        printf("%s is a block device\n", argv[1]);
    } else if (S_ISFIFO(buf.st_mode)) {
        printf("%s is a FIFO (named pipe)\n", argv[1]);
    } else if (S_ISSOCK(buf.st_mode)) {
        printf("%s is a socket\n", argv[1]);
    } else {
        printf("%s is of unknown type\n", argv[1]);
    }

    }

    return 0;
}

//----------------------OUTPUT----------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q14.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out write.txt
// 2
// write.txt
// write.txt is a regular file
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out /home
// 2
// /home
// /home is a directory
