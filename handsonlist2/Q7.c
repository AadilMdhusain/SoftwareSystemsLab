/* 
=================================================================================================
NAME : Q7.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a simple program to print the created thread ids.
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* threadFunction(void* arg){
    int num = *((int*) arg);
    pthread_t thread_id = pthread_self();
    printf("thread id: %lu\n",(unsigned long)thread_id);
    printf("Hi i am thread %d\n",num+1);
    pthread_exit(NULL);
}

int main(){
    pthread_t thread_id[3]; // to save thread ids
    int status;
    for(int i=0;i<3;i++){
        status = pthread_create(&thread_id[i],NULL,threadFunction,(void*) &i);
        if(status!=0){
            perror("Error creating thread\n");
            exit(EXIT_FAILURE);
        }
        if(pthread_join(thread_id[i],NULL)){
            perror("Error terminating\n");
            exit(EXIT_FAILURE);
        }
        
    }


    return 0;
}