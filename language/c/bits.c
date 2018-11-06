#include <stdio.h>

/* get n bits from position p, right adjusted*/
unsigned get_bits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(void) {
    unsigned x = 0xff;
    int p = 4;
    int n = 3;
    printf("x=%u, field=%u\n", x, get_bits(x, p, n));
}
