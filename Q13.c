/* 
=================================================================================================
NAME : Q13.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO WAIT FOR A STDIN FOR 10 SECONDS USING SELECT. WRITE A PROPER 
PRINT STATEMENT TO VERIFY WHETHER THE DATA IS AVAILABLE WITHIN 10 SECONDS OR NOT (CHECK IN $MAN 2
SELECT).
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<sys/types.h>
#include<sys/time.h>
#include<err.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
    int value =0;
    struct timeval tmo;
    fd_set readfds;

    printf("Enter the non-zero number: ");

    fflush(stdout);

    //wait only 10 seconds for user input*/
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    tmo.tv_sec = 10;
    tmo.tv_usec = 0;

    switch(select(1, &readfds, NULL, NULL, &tmo)){
        case -1:
            err(1, "select");
            break;
        case 0:
            printf("User don't give input");
            return(1);
    }

    scanf("%d",&value);
    if(value!=0){
        printf("User input a number\n");
    }
    else{
        printf("User don't give input");
    }
    return 0;
}

// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q13.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Enter the non-zero number: 4
// User input a number
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Enter the non-zero number: User don't give inputaadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ 
