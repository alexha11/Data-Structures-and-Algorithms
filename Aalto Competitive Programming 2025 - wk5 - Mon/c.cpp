#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
 
uint64_t ones_in(uint64_t n){
    if (n == 0)
        return 0;
    return n%2 + ones_in(n/2);
}
 
uint64_t ones_upto(uint64_t n){
    if (n == 1){
        return 0;
    }
    if (n%2 == 1){
        return ones_upto(n+1) - ones_in(n);
    } else {
        return n/2 + 2 * ones_upto(n/2);
    }
}
 
 
int main() {
    uint64_t n = 0;
    if (scanf("%ld", &n) == 0)
        return EXIT_FAILURE;
 
    // main algo
 
    printf("%ld\n", ones_upto(n + 1));
 
    return EXIT_SUCCESS;
}