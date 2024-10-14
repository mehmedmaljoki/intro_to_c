
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char name[50];
    int health;
    int score;
    int experience;
};

int main() {

    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "Mehmed");

    return EXIT_SUCCESS;
}
