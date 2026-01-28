#include <stdio.h>

/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */

// De Morgan's Law
// ~(x & y) = (~x) | (~y)
// ~(x | y) = (~x) & (~y)
int bitAnd(int x, int y) {
    return ~(~(x) | ~(y));
}

int test_bitAnd(int x, int y) {
    return x & y;
}

int main(void) {
    int x = 0;
    int y = 0;
    printf("expected: %x\n", test_bitAnd(x, y));
    printf("actual  : %x\n", bitAnd(x, y));

    x = 6;
    y = 5;
    printf("expected: %x\n", test_bitAnd(x, y));
    printf("actual  : %x\n", bitAnd(x, y));
}
