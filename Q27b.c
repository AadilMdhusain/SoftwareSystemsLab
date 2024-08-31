/* 
=================================================================================================
NAME : Q27b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO EXECUTE AN EXECUTABLE PROGRAM.
(b) execlp
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<unistd.h>
#include<stdio.h>

int main(){
    printf("Before execlp\n");

    if(execlp("ls","ls","-Rl",NULL) == -1){
        perror("execlp failed");
        return 1;
    }

    printf("After execlp\n");

    return 0;
}

//-------------------------OUTPUT--------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q27a.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Before execl
// .:
// total 556692
// -rw-rw-r-- 1 aadil-mohammad-husain aadil-mohammad-husain         0 Aug 12 04:32 aadil
// -rw-rw-r-- 2 aadil-mohammad-husain aadil-mohammad-husain        30 Aug 16 12:50 aadil.txt
// -rwxrwxr-x 1 aadil-mohammad-husain aadil-mohammad-husain     16048 Aug 29 17:26 a.out
// -rw-rw-r-- 1 aadil-mohammad-husain aadil-mohammad-husain       307 Aug 29 00:54 canIwrite.c
// -rw-rw-r-- 1 aadil-mohammad-husain aadil-mohammad-husain       429 Aug 16 10:57 copyfileQ7.c
// -rw-rw-r-- 1 aadil-mohammad-husain aadil-mohammad-husain       671 Aug 16 11:34 copylineQ8.c
// -rw-rw-r-- 1 aadil-mohammad-husain aadil-mohammad-husain       385 Aug 16 09:35 creatfileQ3.c
// -rw-rw-r-- 1 aadil-mohammad-husain aadil-mohammad-husain         8 Aug 17 11:03 database.txt
// -rwxrwxr-x 1 aadil-mohammad-husain aadil-mohammad-husain     16192 Aug 28 22:54 db.out
// -rw-rw-r-- 1 aadil-mohammad-husain aadil-mohammad-husain       144 Aug 17 10:43 db.txt
//..
//..
//..