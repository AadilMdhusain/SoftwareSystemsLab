/* 
=================================================================================================
NAME : Q26.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO EXECUTE AN EXECUTABLE PROGRAM -
(a) USE SOME EXECUTABLE PROGRAM
(b) PASS SOME INPUT TO AN EXECUTABLE PROGRAM (FOR EXAMPLE EXECUTE AN EXECUTABLE OF $./a.out name)
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[]){
    printf("Executing the Hello program\n");

    const char* name = argv[1];

    if(execl("/home/aadil-mohammad-husain/handsonlist1/executable","executable", name,  NULL) == -1){
        perror("execl failed");
        return 1;
    }

    printf("After execl\n");

    return 0;
}


//---------------------------OUTPUT------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist1$ gcc Q26.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist1$ ./a.out Ashraf
// Executing the Hello program
// The name of the person Ashraf. 