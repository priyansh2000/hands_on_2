/*========================================================================================
  ========================================================================================
   Name: 1c.c
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

// Signal handler for SIGPROF
void timer_handler(int signum) {
    printf("Timer expired: ITIMER_PROF\n");
}

int main(int argc, char *argv[]) {
    int timerStatus;
    struct itimerval timer;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s 1 for 10s timer or 2 for 10us timer\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Install the signal handler
    signal(SIGPROF, timer_handler);

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

    timerStatus = setitimer(ITIMER_PROF, &timer, NULL);
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
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ gcc -o 1cop 1c.c
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./1cop 1
^C  
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./1cop 
Usage: ./1cop 1 for 10s timer or 2 for 10us timer







*/