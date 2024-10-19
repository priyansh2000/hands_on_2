/*========================================================================================
  ========================================================================================
   Name: 8e.c
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

#include <signal.h>   // Import for `signal`, `SIGALRM`
#include <sys/time.h> // Import for `setitimer`
#include <stdio.h>    // Import for `printf`, `perror`
#include <unistd.h>   // Import for `_exit`

void callback(int signum)
{
    // This function is called when the SIGALRM signal is caught
    printf("Signal SIGALRM has been caught!\n");
    _exit(0); // Exit the program
}

void main()
{
    struct itimerval timer;
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    // Set up the timer
    timer.it_value.tv_sec = 1; // Initial delay (seconds)
    timer.it_value.tv_usec = 0; // Initial delay (microseconds)
    timer.it_interval.tv_sec = 0; // Interval (seconds) - 0 means no periodic timer
    timer.it_interval.tv_usec = 0; // Interval (microseconds)

    // Configure the timer
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1)
    {
        perror("Error while setting timer!");
        _exit(1);
    }

    // Catch the SIGALRM signal
    signalStatus = signal(SIGALRM, callback);
    if (signalStatus == SIG_ERR)
    {
        perror("Error while catching signal!");
        _exit(1);
    }

    // Wait for the signal to be caught
    while (1); // Infinite loop to keep the program running
}

/*
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ cc 8e.c
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./a.out
Signal SIGALRM has been caught!



*/


