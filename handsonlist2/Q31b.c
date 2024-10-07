/* 
=================================================================================================
NAME : Q31b.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to create a semaphore and initialize value to the semaphore.
(b) create a counting semaphore
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
    sem_t *sem = sem_open("/mycountingsemaphore", O_CREAT, 0644, 3);
    if(sem == SEM_FAILED){
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }

    printf("Before Entering The Critical Section\n");
    sem_wait(sem);
    printf("Inside the Critical Section\n");
    sleep(2);
    printf("Press Enter to Exit CS\n");
    getchar();
    sem_post(sem);

    sem_close(sem);
    // sem_unlink("/mysemaphore");
    return 0;
}

//======================OUTPUT==========================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// Before Entering The Critical Section
// Inside the Critical Section
// Press Enter to Exit CS
