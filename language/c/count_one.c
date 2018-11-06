#include <stdio.h>

int count_one(int x) {

    int num = 0;

    while (x) {
        if (x & 01) {}
            num ++;
        x >>= 1;
    }

    return num;
}


int count_one_2(int x) {
    int num = 0;

    while (x) {
        num ++;

        /* Delete the rightmost bit one. */
        x &= (x - 1);
    }

    return num;
}


int main(void) {

    printf("Count of ones of %d is %d\n", 0xff, count_one(0xff));
    printf("Count of ones of %d is %d\n", 0xee, count_one(0xee));
    printf("Count of ones of %d is %d\n", 0x1, count_one(0x1));

    printf("Count of ones of %d is %d\n", 0xff, count_one_2(0xff));
    printf("Count of ones of %d is %d\n", 0xee, count_one_2(0xee));
    printf("Count of ones of %d is %d\n", 0x1, count_one_2(0x1));

    return 0;
}