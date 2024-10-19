/*========================================================================================
  ========================================================================================
   Name: 8d.c
   Author: Priyansh Rai
  Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
   Date: 8th September,2024
  =======================================================================================
  =======================================================================================*/

#include <signal.h>   // Import for `signal`
#include <unistd.h>   // Import for `_exit`, `alarm`
#include <stdio.h>    // Import `perror` & `printf`

void callback()
{
    printf("Signal SIGALRM has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines status of `signal` call

    alarm(1); // Set an alarm for 1s

    // Catch the SIGALRM signal
    signalStatus = signal(SIGALRM, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");
    else
        while (1);
}
/*
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ cc 8d.c
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./a.out
Signal SIGALRM has been caught!



*/


