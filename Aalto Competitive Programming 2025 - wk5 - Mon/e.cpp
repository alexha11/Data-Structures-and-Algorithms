#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
struct cell{
    uint64_t pos;
    struct cell *next;
};
 
int main() {
    uint64_t n = 0;
    uint64_t x = 0;
    if (scanf("%ld %ld", &n, &x) == 0)
        return EXIT_FAILURE;
 
    if (n == 1){
        printf("%ld\n", 1);
        return EXIT_SUCCESS;
    }
 
    uint64_t prev_pos;
    if (scanf("%ld", &prev_pos) == 0)
            return EXIT_FAILURE;
    uint64_t pos;
    uint64_t winner = -1;
    for (uint64_t i = 1; i < n; i++){
        if (scanf("%ld", &pos) == 0)
            return EXIT_FAILURE;
        if ((pos - prev_pos) % 2 == 1)
            winner = i;
        prev_pos = pos;
    }
 
    // main algo
 
    winner = (winner == -1) ? 0 : winner;
 
    printf("%ld\n", winner + 1);
 
    return EXIT_SUCCESS;
}