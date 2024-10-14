
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    char question[][100] = {"1. What is the capital of France?",
                            "2. What is the capital of Germany?",
                            "3. What is the capital of Italy?",
                            "4. What is the capital of Spain?",
                            "5. What is the capital of Portugal?"};

    char options[][100] = {"A) Paris", "B) London", "C) Madrid", "D) Rome",
                           "A) Berlin", "B) Paris", "C) Madrid", "D) Rome",
                           "A) Berlin", "B) Paris", "C) Madrid", "D) Rome",
                           "A) Berlin", "B) Paris", "C) Madrid", "D) Rome",
                           "A) Berlin", "B) Paris", "C) Lisbon", "D) Rome"};

    char answers[5] = {'A', 'A', 'D', 'C', 'C'};

    int number_of_questions = sizeof(question) / sizeof(question[0]);
    char guess;
    int score;

    puts("Welcome to the quiz game!");

    for (int i = 0; i < number_of_questions; i++) {
        printf("%s\n", question[i]);

        for (int j = (i * 4); j < (i * 4) + 4; j++) {
            printf("%s\n", options[j]);
        }

        printf("Enter your guess: ");
        scanf(" %c", &guess);
        //scanf("%c"); // clear \n from input buffer

        if (toupper(guess) == answers[i]) {
            puts("Correct!");
            score++;
        } else {
            puts("Incorrect!");
        }
    }

    printf("FINAL SCORE: %d/%d\n", score, number_of_questions);


    return EXIT_SUCCESS;
}
