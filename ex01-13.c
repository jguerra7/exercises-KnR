#include <stdio.h>

#define MAXLEN 100
#define BLOCK  "█"
#define BLOCK2 "▒"
#define EMPTY  ' '

main() {
    int i, l, c, maxv, maxh, j;
    int hist[MAXLEN];

    for (i = 0; i < MAXLEN; ++i)
        hist[i] = 0;

    l = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') {
            if (l > 0) {
                if (l >= MAXLEN)
                    printf("Error: word too long.");
                else
                    ++hist[l];
                l = 0;
            }
        } else {
            ++l;
        }

    /* find maximum for vertical histogramming */
    maxv = hist[0];
    maxh = 0;
    for (i = 0; i < MAXLEN; ++i) {
        if (hist[i] > maxv)
            maxv = hist[i];
        if (hist[i] != 0)
            maxh = i;
    }

    /* some serious shit */
    for (i = maxv; i > 0; --i) {
        printf("%10d", i);
        for (j = 1; j <= maxh; ++j)
            if (hist[j] >= i)
                printf(BLOCK);
            else
                putchar(EMPTY);
        putchar('\n');
    }
    printf("          ");
    for (i = 1; i <= maxh; ++i) {
        printf("%d", i % 10);
    }
    putchar('\n');
}
