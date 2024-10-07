/* 
=================================================================================================
NAME : Q4.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to measure how much time is taken to execute 100 getpid () system call.
Use time stamp counter.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/

#include <stdio.h>
#include <x86intrin.h>  
#include <stdint.h>     
#include <unistd.h> 

int main(){
    uint64_t start,end;
    start = _rdtsc();
    for(int i=0;i<100;i++)
    getpid();
    end = _rdtsc();
    printf("cpu cycles taken: %lu\n",end-start);
}

//============================OUTPUT==========================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q4.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// cpu cycles taken: 21084
