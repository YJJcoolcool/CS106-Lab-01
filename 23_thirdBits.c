#include <stdio.h>

/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */

// 0x49249249 = 0100 1001 0010 0100 1001 0010 0100 1001
// 1        = 0000 0001
// << 3     = 0000 1000
// +1       = 0000 1001
// << 3     = 0100 1000
// 0x49     = 0000 0000 0100 1001
// << 9     = 1001 0010 0000 0000
// + 0x49   = 1001 0010 0100 1001
int thirdBits(void) {
    return ((0x49 << 9) + 0x49) << 18 | ((0x49 << 9) + 0x49);
}

int test_thirdBits(void)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i += 3)
        result |= 1 << i;
    return result;
}

int main(void)
{
    printf("expected: %x\n", thirdBits());
    printf("actual  : %x\n", test_thirdBits());
}
