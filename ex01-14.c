#include <ctype.h>
#include <stdio.h>

#define CHARMAX 128
#define BLOCK "#"
#define EMPTY " "

main() {
    int c, i, j, max;
    int chars[CHARMAX];
    char ch;

    for (i = 0; i < CHARMAX; ++i) {
        chars[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < CHARMAX) {
            ++chars[c];
        }
    }

    /* find vertical maximum for histogram */
    max = chars[0];
    for (i = 1; i < CHARMAX; ++i) {
        if (chars[i] > max) {
            max = chars[i];
        }
    }

    /* draw histogram */
    for (i = max; i > 0; --i) {
        printf("%4d", i);
        for (j = 0; j < CHARMAX; ++j) {
            if (chars[j] >= i) {
                printf(BLOCK);
            } else {
                printf(EMPTY);
            }
        }
        printf("\n");
    }
    for (i = 0; i < CHARMAX; ++i) {
        ch = i;
        if (isprint(ch)) {
            printf("%c", ch);
        } else {
            printf(" ");
        }
    }
    printf("\n");
}
