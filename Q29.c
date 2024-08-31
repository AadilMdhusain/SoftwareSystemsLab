/* 
=================================================================================================
NAME : Q29.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO GET SCHEDULING POLICY AND MODIFY THE SCHEDULING POLICY(SCHED_FIFO
, SCHED_RR)
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<stdio.h>
#include<sched.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(){
    pid_t pid = getpid();
    int policy = sched_getscheduler(pid);

    if(policy == -1){
        perror("shed_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Current Scheduling Policy :");
    switch(policy){
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default: 
            printf("Unknown Policy \n");
            break;
    }


    struct sched_param param;
    param.sched_priority = 1;

    policy = SCHED_FIFO;

    if (sched_setscheduler(pid, policy, &param) == -1){
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("The New Scheduling Policy is  : SCHED_FIFO\n");

    policy = SCHED_RR;

    if (sched_setscheduler(pid, policy, &param) == -1){
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("The New Scheduling Policy is  : SCHED_RR\n");
    return 0;
}


//-----------------OUTPUT------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q29.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ sudo ./a.out
// [sudo] password for aadil-mohammad-husain: 
// Current Scheduling Policy :SCHED_OTHER
// The New Scheduling Policy is  : SCHED_FIFO
// The New Scheduling Policy is  : SCHED_RR
