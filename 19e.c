/**========================================================================================
   Name: 19e.c
   Author: Priyansh Rai
 Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
   Date: 12th September,2024
  =======================================================================================
  =======================================================================================*/
  #include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *fifo_name = "my_fifo";

    // Create FIFO with mkfifo
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created using mkfifo.\n");
    return 0;
}
