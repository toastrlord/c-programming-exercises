#include <stdio.h>

int is_leap(int);
int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

main() {
    int m, d;
    month_day(1988, 60, &m, &d);
    printf("Month day result- m: %d, d: %d\n", m , d);
}

int is_leap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

// exercise 5-9: rewrite day_of_year and month_day to use pointers instead of indexing

int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = is_leap(year);
    for (i = 1; i < month; i++) {
        day += *(*daytab + 12 * leap + i);
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = is_leap(year);
    for (i = 1; yearday > *(*daytab + leap) + i; i++) {
        yearday -= *(*daytab + 13 * leap + i);
    }
    *pmonth = i;
    *pday = yearday;
}