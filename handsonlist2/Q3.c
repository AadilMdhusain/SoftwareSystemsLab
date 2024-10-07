/* 
=================================================================================================
NAME : Q3.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to set(any one) system resource limit. Use setrlimit system call.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){
    struct rlimit limit;
    if(getrlimit(RLIMIT_FSIZE,&limit) != 0){
        perror("getrlimit failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Soft Limit: ");
    if(limit.rlim_cur == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long) limit.rlim_cur);

    printf("Hard Limit: ");
    if(limit.rlim_max == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long)limit.rlim_max);

    // changing limit;
    limit.rlim_cur = 2048;
    limit.rlim_max = 4096;
    if(setrlimit(RLIMIT_FSIZE,&limit)!=0){
       perror("getrlimit failed\n");
       exit(EXIT_FAILURE);
    }


    printf("New Soft Limit: ");
    if(limit.rlim_cur == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long) limit.rlim_cur);

    printf("New Hard Limit: ");
    if(limit.rlim_max == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long) limit.rlim_max);
}

//=========================OUTPUT===================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q3.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Soft Limit: unlimited
// Hard Limit: unlimited
// New Soft Limit: 2048
// New Hard Limit: 4096
