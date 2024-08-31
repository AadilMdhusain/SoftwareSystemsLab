/* 
=================================================================================================
NAME : Q1b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : CREATE THE FOLLOWING TYPES OF FILES USING (i) SHELL COMMAND (II)SYSTEM CALL
(b) hard link (link system call)
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

    char *path1 = "/home/aadil-mohammad-husain/Desktop/aadil.txt";
    char *path2 = "/home/aadil-mohammad-husain/Desktop/ashraf.txt";
    int val=link(path1,path2);

    if(val==0){
        printf("The hardlink has been created succesfully.\n");
    }
    else{
        printf("The hardlink could not be created. \n");
    }

    return 0;
}



//----------------------OUTPUT-----------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q1b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The hardlink has been created succesfully.