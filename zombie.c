#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent PID: %d\n", getpid());
        printf("Child PID (Zombie): %d\n", pid);
        sleep(30);  // Give time to observe the zombie
    } else if (pid == 0) {
        // Child process
        printf("Child exiting...\n");
        exit(0);  // Exit immediately
    } else {
        perror("fork");
    }

    return 0;
}
