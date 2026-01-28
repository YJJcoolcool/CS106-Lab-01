#include <stdio.h>

/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */

// -1 = 1111 .... 1111
// 1  = 0000 .... 0001
// Use 1 << 31 (since int is 32 bits)
// Then it will become
// 1000 .... 0000
// Then push it back using >> 31
// 1111 .... 1111 = -1
// Alternative: ~0

int minusOne(void) {
    return 1 << 31 >> 31;
}

int test_minusOne(void) {
    return -1;
}

int main(void) {
    printf("expected: %x (%d)\n", minusOne(), minusOne());
    printf("actual  : %x (%d)\n", test_minusOne(), test_minusOne());
}
