#include <stdio.h>

float fahrenheit2celsius(float);
float celsius2fahrenheit(float);

main() {
    int i;

    printf("  °C    °F\n");
    printf(" ==========\n");
    for (i = 0; i < 100; ++i) {
        printf("%4d %5.1f\n", i, celsius2fahrenheit(i));
    } 
    return 0;
}

float fahrenheit2celsius(float fahrenheit) {
    return 5.0/9.0 * (fahrenheit - 32);
}

float celsius2fahrenheit(float celsius) {
    return 9.0/5.0 * (celsius + 32);
}
