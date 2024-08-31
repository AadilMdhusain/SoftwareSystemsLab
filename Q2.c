/* 
=================================================================================================
NAME : Q2.c
AUTHOR : AADIL MOHAMMAD HUSAIN
DESCRIPTION : WRITE A SINGLE PROGRAM TO EXECUTE IN AN INFINITE LOOP AT THE BACKGROUND.GO TO /proc
DIRECTORY AND IDENTIFY ALL THE PROCESS RELATED INFORMATION IN THE CORRESPONDING /proc directory.
DATE : 29TH AUGUST 2024
=================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>

int main(int argc, char **argv){

    while(true){
        ;
    }
return 0;
    
}

//-------------------------OUTPUT----------------------------------
// aadil-mohammad-husain@aadil-mohammad-husain-82AU:~$ cat /proc/12050/status
// Name:	a.out
// Umask:	0002
// State:	R (running)
// Tgid:	12050
// Ngid:	0
// Pid:	12050
// PPid:	11893
// TracerPid:	0
// Uid:	1000	1000	1000	1000
// Gid:	1000	1000	1000	1000
// FDSize:	256
// Groups:	4 24 27 30 46 100 118 1000 
// NStgid:	12050
// NSpid:	12050
// NSpgid:	12050
// NSsid:	11893
// VmPeak:	    2548 kB
// VmSize:	    2484 kB
// VmLck:	       0 kB
// VmPin:	       0 kB
// VmHWM:	     896 kB
// VmRSS:	     896 kB
// RssAnon:	       0 kB
// RssFile:	     896 kB
// RssShmem:	       0 kB
// VmData:	      92 kB
// VmStk:	     132 kB
// VmExe:	       4 kB
// VmLib:	    1672 kB
// VmPTE:	      36 kB
// VmSwap:	       0 kB
// HugetlbPages:	       0 kB
// CoreDumping:	0
// THP_enabled:	1
// Threads:	1
// SigQ:	0/31066
// SigPnd:	0000000000000000
// ShdPnd:	0000000000000000
// SigBlk:	0000000000000000
// SigIgn:	0000000000000000
// SigCgt:	0000000000000000
// CapInh:	0000000000000000
// CapPrm:	0000000000000000
// CapEff:	0000000000000000
// CapBnd:	000001ffffffffff
// CapAmb:	0000000000000000
// NoNewPrivs:	0
// Seccomp:	0
// Seccomp_filters:	0
// Speculation_Store_Bypass:	thread vulnerable
// SpeculationIndirectBranch:	conditional enabled
// Cpus_allowed:	ff
// Cpus_allowed_list:	0-7
// Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
// Mems_allowed_list:	0
// voluntary_ctxt_switches:	0
// nonvoluntary_ctxt_switches:	7586
