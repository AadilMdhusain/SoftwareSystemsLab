#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char* fifo_path = "/tmp/myfifo";

    // Create FIFO file with mkfifo library function
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created using mkfifo: %s\n", fifo_path);
    return 0;
}

//======================OUTPUT=======================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q19b.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// FIFO created using mkfifo: /tmp/myfifo
