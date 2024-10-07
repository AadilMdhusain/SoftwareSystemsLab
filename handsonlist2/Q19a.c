#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char* fifo_path = "/tmp/myfifo";

    // Create FIFO file with mknod system call
    if (mknod(fifo_path, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        return 1;
    }

    printf("FIFO created using mknod: %s\n", fifo_path);
    return 0;
}

//========================OUTPUT==============================
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ gcc Q19a.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~/handsonlist2$ ./a.out
// mknod: File exists
