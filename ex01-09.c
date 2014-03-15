#include <stdio.h>

main() {
    int c, b;

    b = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            b = 0;
        } else if (!b) {
            putchar(c);
            b = 1;
        }
    }
}
