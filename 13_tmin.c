#include <stdio.h>

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */

// TMin = 1000 .... 0000
// So use 1 (.... 0001) and left shift by 31
int tmin(void) {
    return 1 << 31;
}

int test_tmin(void) {
    return 0x80000000;
}

int main(void)
{
    printf("expected: %x (%d)\n", tmin(), tmin());
    printf("actual  : %x (%d)\n", test_tmin(), test_tmin());
}
