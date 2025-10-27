#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Allocate 4KB of anonymous memory
    void *addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, 
                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (addr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    printf("Memory allocated with mmap.\n");

    // Write to memory to trigger actual allocation
    strcpy((char *)addr, "Hello, mmap!");

    printf("Wrote to mmap memory: %s\n", (char *)addr);

    // Sleep for inspection
    sleep(20);

    // Unmap memory
    if (munmap(addr, 4096) == -1) {
        perror("munmap failed");
        return 1;
    }

    printf("Memory unmapped successfully.\n");
    return 0;
}
