/**========================================================================================
   Name: 15.c
   Author: Priyansh Rai
  Write a simple program to send some data from parent to the child process.
   Date: 10th September,2024
  =======================================================================================
  =======================================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int pair_fd[2];
    
    if (pipe(pair_fd) == -1) {
        printf("Pipe not created");
        return 0;
    }

    pid_t id = fork();

    if (id == 0) {
        // Inside the child
        // Child is reading the parent's data
        // Close write file descriptor (i.e., pair_fd[1], the write end)
        close(pair_fd[1]);
        int x;
        read(pair_fd[0], &x, sizeof(int));
        printf("Value of X read in child is %d\n", x);
        close(pair_fd[0]);
    } else {
        // Inside the parent
        // Writing data for the child
        // Close read file descriptor (i.e., pair_fd[0], the read end)
        close(pair_fd[0]);
        int x;
        scanf("%d", &x);
        printf("Value of X to write in child is %d\n", x);
        write(pair_fd[1], &x, sizeof(int));
        close(pair_fd[1]);
    }

    return 0;
}
/*
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ cc 15.c
(base) priyansh@priyansh-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/hands_on_2$ ./a.out
fdjasssajdsifjsaasidjasijsadidjasd
Value of X to write in child is -103988400
Value of X read in child is -103988400

*/