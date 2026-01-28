#include <stdio.h>

/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */

// TMin = 1000 .... 0000
// -1 = 1111 .... 1111
// 0  = 0000 .... 0000
// TMax = 0111 .... 1111
// If non-negative:
// short TMax = 0111 1111 1111 1111
// If negative:
// short -1   = 1111 1111 1111 1111
// int -1     = 1111 1111 1111 1111 1111 1111 1111 1111
// short TMin = 1000 0000 0000 0000
// int        = 1111 1111 1111 1111 1000 0000 0000 0000
// Detect if negative: >> 15 & 1

// 1111 1111 1111 1111 1000 0000 0000 0000 (short TMin)
// 0000 0000 0000 0000 0000 0000 0000 0000 (zero)
// 0000 0000 0000 0000 0111 1111 1111 1111 (short TMax)


int fitsShort(int x) {
    return !(x >> 15) | !~(x >> 15);
}

int test_fitsShort(int x)
{
    short int sx = (short int) x;
    return x == sx;
}

int main(void)
{
    int x = 0;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
    printf("\n");

    x = -1;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
    printf("\n");

    x = -32768;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
    printf("\n");

    x = -32769;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
    printf("\n");

    x = 32767;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
    printf("\n");

    x = 32768;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
    printf("\n");

}
