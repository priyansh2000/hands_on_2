 /**========================================================================================
   Name: 10.c
   Author: Priyansh Rai
 Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
   Date: 8th September,2024
  =======================================================================================
  =======================================================================================*/
#include <signal.h> // Import for `sigaction`, `raise`
#include <stdio.h>  // Import for `perror` & `printf`
#include <unistd.h> // Import for `_exit`, `sleep`

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGFPE (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;
    int a;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGFPE, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        raise(SIGFPE);
}
