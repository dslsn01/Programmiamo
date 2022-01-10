#include <stdio.h>
#include <inttypes.h>

int main() {
    uint64_t m = 442578139;
    uint64_t n = 442578139;

    printf("%" PRIu64 "\n", m);
    printf("%" PRIu64 "\n", n);

    if (m == n) {
        printf("uguali!\n");
    }
}

