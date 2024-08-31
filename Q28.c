/* 
=================================================================================================
NAME : Q28.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO GET MAXIMUM AND MINIMUM REAL TIME PRIORITY 
DATE : 29TH AUGUST 2024
=================================================================================================
*/




#include<stdio.h>
#include<sched.h>

int main(){
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    min_priority = sched_get_priority_min(SCHED_FIFO);

    if(max_priority == -1 || min_priority == -1){
        perror("sched_get_priority_max/min");
        return 1;
    }

    printf("Maximum Real-Time Priority of FIFO: %d\n", max_priority);
    printf("Minimum Real Time Priority of FIFO: %d\n", min_priority);

    max_priority = sched_get_priority_max(SCHED_RR);
    min_priority = sched_get_priority_min(SCHED_RR);

    if(max_priority == -1 || min_priority == -1){
        perror("sched_get_priority_max/min");
        return 1;
    }

    printf("Maximum Real-Time Priority of RR: %d\n", max_priority);
    printf("Minimum Real Time Priority of RR: %d\n", min_priority);
    return 0;
}


//----------OUTPUT-----------//
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist1$ gcc Q28.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist1$ ./a.out
// Maximum Real-Time Priority of FIFO: 99
// Minimum Real Time Priority of FIFO: 1
// Maximum Real-Time Priority of RR: 99
// Minimum Real Time Priority of RR: 1