/* 
=================================================================================================
NAME : Q17.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A PROGRAM TO SIMULATE ONLINE TICKET RESERVATION. IMPLEMENT A PROGRAM TO OPEN
THE FILE, IMPLEMENT WRITE LOCK, READ THE TICKET NUMBER, INCREMENT THE NUMBER AND PRINT THE NEW
TICKET NUMBER THEN CLOSE THE FILE.
DATE : 29TH AUGUST 2024
=================================================================================================
*/



#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

struct database{
    int ticket_count;
};

int main(){
    struct database db;
    int fd, input;
    fd = open("database.txt", O_RDWR | O_EXCL);
    printf("Select the train number(1,2,3) : \n");
    scanf("%d",&input);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1)*sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();

    lseek(fd, (input-1)*sizeof(db), SEEK_SET);

    read(fd, &db, sizeof(db));
    printf("Before applying the lock \n");

    fcntl(fd, F_SETLKW, &lock);

    printf("Ticket Number: %d \n", db.ticket_count);
    db.ticket_count++;

    lseek(fd, (input-1)*sizeof(db), SEEK_SET);

    write(fd, &db, sizeof(db));
    printf("To Book Ticket, press Enter \n");

    getchar();
    getchar();

    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Booked \n");
    
}

//---------------------------OUTPUT--------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q17.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Select the train number(1,2,3) : 
// 3
// Before applying the lock 
// Ticket Number: 3 
// To Book Ticket, press Enter 

// Booked 
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Select the train number(1,2,3) : 
// 2
// Before applying the lock 
// Ticket Number: 1 
// To Book Ticket, press Enter 

// Booked 
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out
// Select the train number(1,2,3) : 
// 3
// Before applying the lock 
// Ticket Number: 4 
// To Book Ticket, press Enter 

// Booked 