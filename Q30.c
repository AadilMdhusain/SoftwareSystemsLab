/* 
=================================================================================================
NAME : Q30.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO RUN A SCRIPT AT A SPECIFIC TIME USING A DAEMON PROCESS.
DATE : 29TH AUGUST 2024
=================================================================================================
*/

#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if(argc != 4)
    {
        fprintf(stderr, "Usage: %s <hour> <minute> <script_path> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int hour = atoi(argv[1]);
    int minute = atoi(argv[2]);
    const char *script_path = argv[3];
    system(script_path);
    printf("Hour : %d \n", hour);
    printf("Minutes : %d \n", minute);


    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
        while(1){
            time_t now = time(NULL);
            struct tm *timeinfo = localtime(&now);
            printf("Hour : %d \n", timeinfo->tm_hour);
            printf("Minutes : %d \n", timeinfo->tm_min);
            if(timeinfo->tm_hour == hour && timeinfo->tm_min == minute)
            {
                if(system(script_path) == -1){
                    exit(EXIT_FAILURE);
                }

                sleep(60);

            }
            else
            {
                printf("Child pid : %d\n", getpid());
                printf("Daemon process is running...\n");
                sleep(30);
            }
        }
    }
    else 
        exit(0);
}


//--------------------OUTPUT----------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist1$ gcc Q30.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist1$ ./a.out 18 38 /home/aadil-mohammad-husain/handsonlist1/daemon.sh
// The programming is running lets go
// Hour : 18 
// Minutes : 38 
// Hour : 18 
// Minutes : 39 
// Child pid : 13740
// Daemon process is running...
