/* 
=================================================================================================
NAME : Q1a.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : CREATE THE FOLLOWING TYPES OF FILES USING (i) SHELL COMMAND (II)SYSTEM CALL
(a) soft link(symlink system call)
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

    char *path1 = "/home/aadil-mohammad-husain/Desktop/ticket.sh";
    char *path2 = "/home/aadil-mohammad-husain/Desktop/softlinkticket.sh";
    int val=symlink(path1,path2);

    if(val==0){
        printf("The softlink has been created successfully. \n");
    }
    else{
        printf("The softlink creation was unsuccessful.\n");
    }

    return 0;
}

//------------------------OUTPUT---------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q1a.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// The softlink creation was unsuccessful.
