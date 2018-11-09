#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main(void) {

    struct Point pt = {200, 100};
    printf("pt.x=%d, pt.y=%d\n", pt.x, pt.y);

    return 0;
}