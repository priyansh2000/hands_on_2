/*========================================================================================
  ========================================================================================
   Name: 8b.c
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

  #include <signal.h> // Import for signal, raise
#include <stdio.h>  // Import for printf, scanf & perror
#include <unistd.h> // Import for _exit

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the signal call

    signalStatus = signal(SIGSEGV, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV); // Send segmentation fault signal
        
}
/*
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ cc 8b.c
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./a.out
Signal SIGSEGV has been caught!


*/
  