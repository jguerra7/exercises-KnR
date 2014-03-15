#include <stdio.h>

#define MAXLINE 10/*00*/  /* maximum input size */

int _getline(char line[], int maxline);
/* getline is a library function in POSIX; unfortunately on OS X the -ansi flag
   doesn't help */
void copy(char to[], char from[]);

main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {  /* there was a line */
        printf("%d\n", max);
        printf("%s", longest);
    }
    return 0;
}

/* _getline: read a line into s, return length */
int _getline(char s[], int lim) {
    int c, i, length;

    i = length = 0;
    while ((c = getchar()) != EOF) {
        ++length;
        if (i < lim - 1) {
            s[i] = c;
            ++i;
        }
        if (c == '\n') {
            break;
        }
    }
    s[i-1] = '\n';
    s[i] = '\0';
    return length;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
