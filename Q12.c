/* 
=================================================================================================
NAME : Q12.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO FIND OUT THE OPENING MODE OF A FILE. USE FCNTL.
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


int main(){

    int fd, fd1, fd2;
    fd = open("stdinput.txt", O_WRONLY); 
    fd1 = open("aadil.txt", O_RDONLY); 
    fd2 = open("stdout.txt", O_RDWR); 
    
    int word[3];

    word[0] = fcntl(fd, F_GETFL);
    word[1] = fcntl(fd1, F_GETFL);
    word[2] = fcntl(fd2, F_GETFL);

    printf("The mode of the file is : %d \n",word[0] & 3);
    printf("The mode of the aadil file is : %d \n",word[1] & 3);
    printf("The mode of the stdout file is : %d \n",word[2] & 3);

    for(int i=0; i<3; i++)
    {

    if((word[i] & 3)==0)
    {
        printf("The mode of the file is readonly\n");
    }
    else if((word[i] & 3)==1)
    {
        printf("The mode of the file is writeonly\n");
    }
    else if((word[i] & 3)==2)
    {
        printf("The mode of the file is read and write\n");
    }

    }

    return 0;
}

//------------------------OUTPUT---------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q12.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The mode of the file is : 1 
// The mode of the aadil file is : 0 
// The mode of the stdout file is : 2 
// The mode of the file is writeonly
// The mode of the file is readonly
// The mode of the file is read and write
