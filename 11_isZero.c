#include <stdio.h>

/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */

// 0 - 0000
// 1 - 0001
// 4 - 0100
// (!) Logical NOT - 1 if ALL bits are 0, 0 if otherwise

int isZero(int x) {
    return !x;
}

int test_isZero(int x) {
    return x == 0;
}

int main(void) {
    int x = 0;
    printf("expected: %x\n", isZero(x));
    printf("actual  : %x\n", test_isZero(x));

    x = 1;
    printf("expected: %x\n", isZero(x));
    printf("actual  : %x\n", test_isZero(x));
}
