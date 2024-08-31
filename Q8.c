/* 
=================================================================================================
NAME : Q8.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGARM TO OPEN THE FILE IN READ ONLY MODE, READ LINE BY LINE AND DISPLAY 
EACH LINE AS IT IS. CLOSE THE FILE WHEN END OF THE FILE IS REACHED.
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){

    int fd, fd1, sz, index=0;;
    char line[256];
     char *c = (char*)calloc(1,sizeof(char));
    fd = open("stdinput.txt", O_RDONLY);
    fd1 = open("writeline.txt", O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, 0644);

    while(sz>0){
        sz=read(fd, c, 1);
        if(*c=='\n'){
            write(fd1, line, strlen(line));
            line[index]='\0';
            printf("The line is : %s \n", line);
            strcpy(line,"");
            continue;
        }
        strcat(line, c);
        index++;
    }

    close(fd);
    close(fd1);
    return 0;
}

//------------------OUTPUT-------------------------------
// DATA IN STDINPUT.TXT - Python is a high-level, general-purpose programming language.
// Its design philosophy emphasizes code readability with the use of significant indentation.
// Guido van Rossum began working on Python in the late 1980s as a successor to the ABC
// programming language and first released it in 1991 as Python 0.9.0.[35]Python consistently
// ranks as one of the most popular programming languages, and has gained widespread use 
// in the machine learning community.[37][38][39][40]

// DATA IN WRITELINE.TXT - Python is a high-level, general-purpose programming language.
// Its design philosophy emphasizes code readability with the use of significant indentation.
// Guido van Rossum began working on Python in the late 1980s as a successor to the ABC
// programming language and first released it in 1991 as Python 0.9.0.[35]Python consistently
// ranks as one of the most popular programming languages, and has gained widespread use 
// in the machine learning community.[37][38][39][40]