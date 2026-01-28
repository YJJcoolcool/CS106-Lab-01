#include <stdio.h>

/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */

// test_upperBits(1) = 1000 .... 0000
// test_upperBits(2) = 1100 .... 0000
// test_upperBits(3) = 1110 .... 0000
// ...
// test_upperBits(32) = 1111 .... 1111
// 1        = 0000 .... 0001
// << 31    = 1000 .... 0000
// >> (n-1) = 1110 .... 0000
//              ^ (If n=3, then n-1 = 2 so >> 2)
//
// If n = 0, n - 1 = -1 = 1111 .... 1111
// mask: all zeros
// If n = 1, n - 1 = 0 = 0000 .... 0000
// mask: all ones
// If n = 32, n - 1 = 31 = 0000 .... 0001 1111
// mask: all ones

int upperBits(int n) {
    return 1 << 31 >> (n + ~0) & (!((n + ~0) >> 5) << 31 >> 31);
}

// 33
// 1111 .... 11111
// 32 = 0000 .... 0010 0000
// >>5= 0000 .... 0000 0001
// !  = 0

int test_upperBits(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < x; i++)
        result |= (1 << (31 - i));
    return result;
}

int main(void)
{
    int x = 32;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
    printf("\n");

    x = 4;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
    printf("\n");

    x = 0;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
    printf("\n");

    x = 33;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
    printf("\n");

    x = -1;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
    printf("\n");
}
