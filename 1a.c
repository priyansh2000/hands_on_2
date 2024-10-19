/*========================================================================================
  ========================================================================================
   Name: 1a.c
   Author: Priyansh Rai
   Description:Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
   Date: 6th September,2024
  =======================================================================================
  =======================================================================================*/




  
#include <sys/time.h>  // for `setitimer`
#include <signal.h>    // for `signal`
#include <unistd.h>    // for `pause`
#include <stdio.h>     // for `perror`, `printf`, `fprintf`
#include <stdlib.h>    // for `exit`

// Signal handler for SIGALRM
void timer_handler(int signum) {
    printf("Timer expired: ITIMER_REAL\n");
}

int main(int argc, char *argv[]) {
    int timerStatus;
    struct itimerval timer;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s 1 for 10s timer or 2 for 10us timer\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Install the signal handler
    signal(SIGALRM, timer_handler);

    // Set timer based on input argument
    if (atoi(argv[1]) == 1) {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    } else if (atoi(argv[1]) == 2) {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10;  // 10 microseconds
    } else {
        fprintf(stderr, "Invalid option.\n");
        exit(EXIT_FAILURE);
    }

    timerStatus = setitimer(ITIMER_REAL, &timer, NULL);
    if (timerStatus == -1) {
        perror("Error setting the interval timer");
        exit(EXIT_FAILURE);
    }

    // Wait indefinitely for signal
    while (1) {
        pause();
    }

    return 0;
}

/*

TERMINAL:
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ gcc -o 1aop 1a.c
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./1aop 1
Timer expired: ITIMER_REAL


*/




















  /*
  printf:

    Writes formatted output to the standard output (usually the console or terminal).
    Usage: printf(format_string, arguments...)
    Example:

    c

    printf("Hello, World!\n");

fprintf:

    Writes formatted output to a specified file stream, which could be a file, standard output, standard error, or another custom file stream.
    Usage: fprintf(file_pointer, format_string, arguments...)
    Example:

    c

        FILE *fp = fopen("output.txt", "w");
        fprintf(fp, "Hello, World!\n");
        fclose(fp);



------------------------------------------------------------------------------------

In C, the struct itimerval is used to specify intervals for setting a timer. It's primarily used with functions like setitimer() to configure and handle real-time timers.

Here is the structure definition of itimerval:

c

struct itimerval {
    struct timeval it_interval;  // Interval for periodic timer
    struct timeval it_value;     // Time until next expiration
};

Fields:

    it_interval: This is of type struct timeval, and it specifies the period between successive timer expirations. Once the timer expires, the countdown will restart with this interval.

    it_value: Also of type struct timeval, this specifies the time remaining until the timer expires for the first time.

struct timeval:

The timeval structure represents time with two components:

c

struct timeval {
    long tv_sec;    // Seconds
    long tv_usec;   // Microseconds
};

    tv_sec: Holds the number of seconds.
    tv_usec: Holds the number of microseconds.

    ---------------------------------------------------------------------------------------------

    The line signal(SIGALRM, timer_handler); is a way to set a signal handler in C for the SIGALRM signal. Here’s a breakdown of what this line does:
Components:

    SIGALRM:
        This is a signal constant, representing the alarm signal. It is delivered when a timer set by the alarm() or setitimer() functions expires.
        In this case, it corresponds to the real-time timer.

    timer_handler:
        This is a function pointer that points to the handler function you want to be called when the SIGALRM signal is received.
        This function must have the following signature:

        c

    void timer_handler(int signum);

    Where signum will be the signal number (in this case, SIGALRM).

signal():

    This function is used to set up a signal handler. It takes two arguments: the signal number and the function to be executed when that signal occurs.
    In this case, SIGALRM is the signal number, and timer_handler is the function that will handle the signal.

    -----------------------------------------------------------------------------------------------
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
    perror("Error setting timer");
    exit(EXIT_FAILURE);
}

    setitimer: Starts the timer with the specified settings.
    ITIMER_REAL: Specifies that the real-time timer is used, which decrements in real time and sends SIGALRM upon expiration.
    Error Checking: If setitimer fails, an error message is printed, and the program exits.

  */