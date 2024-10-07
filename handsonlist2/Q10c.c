/* 
=================================================================================================
NAME : Q10c.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a separate program using sigaction system call to catch the following signals.
(c) SIGFPE
DATE : 21st SEPTEMBER 2024
=================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handle_sigfpe(int sig) {
    printf("Caught SIGFPE: Arithmetic error occurred!\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;

    // Set up the signal handler
    sa.sa_handler = handle_sigfpe;  // Assign the handler function
    sa.sa_flags = 0;                 // No special flags
    sigemptyset(&sa.sa_mask);        // Initialize signal set to empty

    // Install the signal handler for SIGFPE
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Trigger a SIGFPE by dividing by zero
    printf("About to divide by zero...\n");
    int result = 1 / 0;  // This will cause SIGFPE

    // This line will not be executed
    printf("Result: %d\n", result);
    return 0;
}

//===================OUTPUT===================================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q10c.c
// Q10c.c: In function ‘main’:
// Q10c.c:39:20: warning: division by zero [-Wdiv-by-zero]
//    39 |     int result = 1 / 0;  // This will cause SIGFPE
//       |                    ^
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// About to divide by zero...
// Caught SIGFPE: Arithmetic error occurred!