/** Exercise 1.19
 * Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.
 */
#include <stdio.h>

#define BUFSIZE 1024

int _getline(char[], int);
void reverse(char[], int);

main() {
    char line[BUFSIZE];
    int length;

    while ((length = _getline(line, BUFSIZE)) > 0) {
        if (line[length-1] == '\n') {
            length--;
        }
        reverse(line, length);
        printf("%s", line);
    }

    return 0;
}

int _getline(char s[], int lim) {
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[], int size) {
    if (size < 2) {
        return;
    }

    int i, j;
    char tmp;

    for (i = 0, j = size - 1; i < size/2; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
