#include <stdio.h>

main() {
    int c, nb, nt, nl;

    nb = nt = nl = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    printf("Blanks: %d\n", nb);
    printf("Tabs:   %d\n", nt);
    printf("Lines:  %d\n", nl);
}
