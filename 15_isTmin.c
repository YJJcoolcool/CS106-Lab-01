#include <stdio.h>

/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 1
 */

// TMin = 1000 .... 0000
// Mask = 1000 .... 0000
// Result = 0000 .... 0000 (A)
//
// Not TMin = 1100 .... 0010
// Mask     = 1000 .... 0000
// Result   = 0100 .... 0010 (B)
// If LOGICAL NOT (!) used on A, it will evaluate to 1
// Likewise if used on B, it will evaluate to 0
int isTmin(int x) {
    return !(x ^ (1 << 31));
}

int test_isTmin(int x) {
    return x == 0x80000000;
}

int main(void)
{
    int x = 0;
    printf("expected: %x\n", isTmin(x));
    printf("actual  : %x\n", test_isTmin(x));

    x = -2147483648;
    printf("expected: %x\n", isTmin(x));
    printf("actual  : %x\n", test_isTmin(x));
}
