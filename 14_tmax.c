#include <stdio.h>

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */

// TMax = 0111 .... 1111
// Use 1 (.... 0001) and shift it by 31 to become:
// 1000 .... 0000
// Then flip all the bits to become
// 0111 .... 1111 = TMax
int tmax(void) {
    return ~(1 << 31);
}

int test_tmax(void) {
    return 0x7FFFFFFF;
}

int main(void)
{
    printf("expected: %x (%d)\n", tmax(), tmax());
    printf("actual  : %x (%d)\n", test_tmax(), test_tmax());
}
