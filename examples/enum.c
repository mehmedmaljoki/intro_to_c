
#include <stdio.h>
#include <stdlib.h>

enum Weekday {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

typedef enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

int main() {

    enum Weekday today = MONDAY;

    Month month = JANUARY;

    if (month == JANUARY) {
        puts("It is January");
    }


    printf("Today is %d\n", today);

    return EXIT_SUCCESS;
}
