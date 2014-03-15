/** Exercise 1.17
 * Write a program to print all input lines that are longer than 80 characters.
 */
#include <stdio.h>

#define MINLINE 80

main() {
    int i, buffer_printed;
    char buffer[MINLINE + 1];
    char c;

    i = buffer_printed = 0;
    buffer[MINLINE] = '\0';

    while ((c = getchar()) != EOF) {
        if (!buffer_printed) {
            buffer[i] = c;
            ++i;
            if (i > MINLINE) {
                printf("%s", buffer);
                buffer_printed = 1;
            }
        } else {
            putchar(c);
        }
        
        if (c == '\n') {
            i = 0;
            buffer_printed = 0;
        }
    }

    return 0;
}
