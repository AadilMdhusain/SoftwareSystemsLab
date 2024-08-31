/* 
=================================================================================================
NAME : Q7.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGARM TO COPY FILE1 INTO FILE2. ($CP FILE1 FILE2)
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){

    int fd, fd1, sz=1;
    char *c = (char*)calloc(100,sizeof(char));

    fd = open("stdinput.txt", O_RDONLY);
    fd1 = open("write.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);

    while(sz>0){
        sz=read(fd, c, 1);
        write(fd1, c, strlen(c));
    }

    close(fd);
    close(fd1);

    return 0;

}

//--------------------------OUTPUT------------------------------------
// STDINPUT.txt contents-
// Python is a high-level, general-purpose programming language. Its design philosophy 
// emphasizes code readability with the use of significant indentation.Guido van Rossum 
// began working on Python in the late 1980s as a successor to the ABC programming language 
// and first released it in 1991 as Python 0.9.0.[35]Python consistently ranks as one of 
// the most popular programming languages, and has gained widespread use in the machine 
// learning community.[37][38][39][40]
// write.txt contents-
// Python is a high-level, general-purpose programming language. Its design philosophy 
// emphasizes code readability with the use of significant indentation.Guido van Rossum 
// began working on Python in the late 1980s as a successor to the ABC programming language 
// and first released it in 1991 as Python 0.9.0.[35]Python consistently ranks as one of 
// the most popular programming languages, and has gained widespread use in the machine 
// learning community.[37][38][39][40]