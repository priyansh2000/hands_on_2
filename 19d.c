/**========================================================================================
   Name: 19d.c
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
  #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    const char *fifo_name = "my_fifo";

    // Create FIFO with mknod
    if (mknod(fifo_name, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        return 1;
    }

    printf("FIFO created using mknod.\n");
    return 0;
}
