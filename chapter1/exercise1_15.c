// exercise 1-15: rewrite the temperature conversion program of sectio 1.2 to use a function for conversion
#include <stdio.h>

// rewrite temp conversion program to use functions
double celsiusToFahrenheit(double celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("  C    F \n");
    printf("***********\n");
    while (celsius <= upper) {
        fahr = celsiusToFahrenheit(celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}