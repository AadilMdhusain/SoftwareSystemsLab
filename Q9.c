/* 
=================================================================================================
NAME : Q9.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGARM TO PRINT THE FOLLOWING INFORMATION ABOUT A GIVEN FILE-
(a) inode
(b) number of hardlinks
(c) uid
(d) gid
(e) size
(f) block size
(g) number of blocks
(h) time of last access
(i) time of last modification
(j) time of last change
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

extern int errno;

int main(){

    int  fd, inode;
    fd = open("stdinput.txt", O_RDONLY);

    if(fd < 0){
        perror("Program");
    }

    struct stat file_stat;
    int ret;
    ret = fstat(fd, &file_stat);
    if(ret<0){
        perror("Program");
    }
    inode = file_stat.st_ino;
    int nohl = file_stat.st_nlink;
    int uid = file_stat.st_uid;
    int gid = file_stat.st_gid;
    int sz = file_stat.st_size;
    int blcksz = file_stat.st_blksize;
    int noblock = file_stat.st_blocks;
    int tla = file_stat.st_atime;
    int tlm = file_stat.st_mtime;
    int tlc = file_stat.st_ctime;


    printf("The inode number is : %d\n", inode);
    printf("The number of hard links to the file is : %d\n", nohl);
    printf("The user id of the file is : %d\n", uid);
    printf("The group id of the file is : %d \n", gid);
    printf("The size of the file is : %d \n", sz);
    printf("The block size will be :%d\n",blcksz);
    printf("The number of blocks is : %d\n",noblock);
    printf("The time of last access : %d\n",tla);
    printf("The time of last modification : %d\n",tlm);
    printf("The time of last status chagne : %d\n",tlc);
    close(fd);
}

//---------------------OUTPUT--------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q9.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The inode number is : 8389044
// The number of hard links to the file is : 1
// The user id of the file is : 1000
// The group id of the file is : 1000 
// The size of the file is : 1609 
// The block size will be :4096
// The number of blocks is : 8
// The time of last access : 1724956780
// The time of last modification : 1724956381
// The time of last status chagne : 1724956381