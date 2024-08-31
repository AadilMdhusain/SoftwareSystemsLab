/* 
=================================================================================================
NAME : Q19.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM OF Y0UR RUNNING PROGRAM. MODIFY THE PRIORITY WITH NICE COMMAND.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdio.h>
#include<stdint.h>
#include<immintrin.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    uint64_t start, end;
    double time = 0.00000000125;
    unsigned long int diff;

    start = _rdtsc();

    getpid();

    end = _rdtsc();

    diff = end-start;

    printf("Time elapsed: %lf seconds \n", diff*time);
    printf("Cycles elapsed: %lu \n", diff);
    return 0;
}


//----------OUTPUT-----------//
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q19.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Time elapsed: 0.000025 seconds 
// Cycles elapsed: 19804 
