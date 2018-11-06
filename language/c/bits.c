#include <stdio.h>

/* get n bits from position p, right adjusted*/
unsigned get_bits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(void) {
    unsigned x = 0xff;
    int p = 4;
    int n = 3;
    printf("x=%x, field=%x\n", x, get_bits(x, p, n));

    int a = -1;
    printf("a is %d, right-shift is %d\n", a, a >> 10);

    return 0;
}
