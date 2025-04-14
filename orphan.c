#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent exits immediately, making the child an orphan
        printf("Parent process (PID: %d) exiting...\n", getpid());
        exit(0);  // Parent exits immediately, leaving child behind
    } else if (pid == 0) {
        // Child process
        sleep(5);  // Child waits for a moment, allowing us to observe orphan status
        printf("Child process (PID: %d) is now an orphan, adopted by init (PID: 1)\n", getpid());
    } else {
        perror("fork");
    }

    return 0;
}
