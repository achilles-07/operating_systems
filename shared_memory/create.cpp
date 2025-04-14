#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>   


using namespace std;


int main() {
    // Shared Memory data
    const char *name = "/shared_memory";  // Must start with a forward slash
    const char *message = "This is a shared message";
    int shm_fd;
    void *ptr;

    // Creating shared memory segment
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Configuring the size of memory segment
    size_t size = strlen(message) + 1;
    if (ftruncate(shm_fd, size) == -1) {
        perror("ftruncate");
        return 1;
    }

    // mapping the shared memory segment in the address space of the process
    ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write to the shared memory segment
    sprintf((char*)ptr, "%s", message);

    return 0;
}