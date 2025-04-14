#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>  

using namespace std;

int main() {
    const char *name = "/shared_memory";
    int shm_fd;
    void *ptr;

    // Open the shared segment
    shm_fd = shm_open(name, O_RDONLY, 0666);

    // Map the shared memory segment in the address space of the process
    ptr = mmap(0, sizeof(char*), PROT_READ, MAP_SHARED, shm_fd, 0);

    // Read from segment
    printf("%s\n", (char*)ptr);

    // cleanup
    shm_unlink(name);

    return 0;
}