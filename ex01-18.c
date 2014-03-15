/** Exercise 1.18
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete blank lines.
 */
#include <stdio.h>

#define BUFSIZE 1024

main() {
    int i, line_not_empty;
    char buffer[BUFSIZE];
    char c;

    i = line_not_empty = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (i < BUFSIZE - 1) {
                buffer[i] = c;
                ++i;
            }
        } else if (c == '\n') {
            if (line_not_empty) {
                putchar(c);
                line_not_empty = 0;
            }
        } else {
            buffer[i] = '\0';
            i = 0;
            printf("%s", buffer);
            putchar(c);
            line_not_empty = 1;
        }
    }
}
