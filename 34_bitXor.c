#include <stdio.h>

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */

// 0110 ^ 1010 = 1100

//    0110
// ~= 1001
//    1010
// &= 1000 (A)

//    1010
// ~= 0101
//    0110
// &= 0100 (B)

// A | B
// = 1100
int bitXor(int x, int y) {
    return (~x & y) | (x & ~y);
}

int test_bitXor(int x, int y) {
    return x ^ y;
}

int main(void) {
    int x = 0;
    int y = 0;
    printf("expected: %x\n", bitXor(x, y));
    printf("actual  : %x\n", test_bitXor(x, y));
    printf("\n");

    x = 4;
    y = 5;
    printf("expected: %x\n", bitXor(x, y));
    printf("actual  : %x\n", test_bitXor(x, y));
    printf("\n");

    x = 6;
    y = 10;
    printf("expected: %x\n", bitXor(x, y));
    printf("actual  : %x\n", test_bitXor(x, y));
    printf("\n");
}
