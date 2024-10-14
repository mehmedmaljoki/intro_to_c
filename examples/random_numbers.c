
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int guesses;
    int answer;

    srand(time(0));

    answer = (rand() % MAX) + MIN;

    do {
        printf("Enter a guess: ");
        scanf("%d", &guess);

        if (guess > answer) {
            puts("Too high");
        } else if (guess < answer) {
            puts("Too low");
        } else {
            puts("CORRECT");
        }

        guesses++;
    } while (guess != answer);

    puts("+++++++++++++++++++++++++++++++++");
    printf("answer: %d\n", answer);
    printf("guesses: %d\n", guesses);
    puts("+++++++++++++++++++++++++++++++++");


    return EXIT_SUCCESS;
}
