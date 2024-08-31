/* 
=================================================================================================
NAME : Q5.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : Write a program to create five new files with infinite loop. Execute the program in 
the background and check the file descriptor table at /proc/pid/fd.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define NUM_FILES 5

int main() {
    int file_descriptors[NUM_FILES];
    char filename[20];


    for(int i=0; i<NUM_FILES; i++){
        snprintf(filename, sizeof(filename), "file_%d.txt", i+1);

        file_descriptors[i]=open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if(file_descriptors[i]<0){
            perror("open");
            exit(EXIT_FAILURE);
        }
    }


    while(1){
        for(int i=0; i<NUM_FILES; i++){
            write(file_descriptors[i], "Keeping the file open\n",22);
        }
    }


    return 0;
}


//---------------------------OUTPUT----------------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ gcc Q5.c
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ ./a.out &
// [1] 3806
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ cd /proc
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:/proc$ cd 3806
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:/proc/3806$ ls
// arch_status         fd                 net            setgroups
// attr                fdinfo             ns             smaps
// autogroup           gid_map            numa_maps      smaps_rollup
// auxv                io                 oom_adj        stack
// cgroup              ksm_merging_pages  oom_score      stat
// clear_refs          ksm_stat           oom_score_adj  statm
// cmdline             limits             pagemap        status
// comm                loginuid           patch_state    syscall
// coredump_filter     map_files          personality    task
// cpu_resctrl_groups  maps               projid_map     timens_offsets
// cpuset              mem                root           timers
// cwd                 mountinfo          sched          timerslack_ns
// environ             mounts             schedstat      uid_map
// exe                 mountstats         sessionid      wchan
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:/proc/3806$ cd fd
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:/proc/3806/fd$ ls
// 0  1  2  3  4  5  6  7