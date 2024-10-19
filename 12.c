/**========================================================================================
   Name: 12.c
   Author: Priyansh Rai
  Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
   Date: 10th September,2024
  =======================================================================================
  =======================================================================================*/

  #include <sys/types.h> // Import for `kill`, `fork`
#include <signal.h>    // Import for `kill`
#include <unistd.h>    // Import for `fork`, `sleep`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    pid_t childPid, parentPid;
    int killStatus; // Determines success of `kill`

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        // Child will enter this branch
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        // Parent will enter this branch
        while (1);
    }
}
/*
base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ cc 12.c
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./a.out
Child PID: 64173
Parent PID: 64172
Successfully killed parent!
Killed
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ Child now exiting!


*/