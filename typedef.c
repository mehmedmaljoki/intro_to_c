

#include <stdio.h>
#include <stdlib.h>

typedef char my_user[25];

typedef struct {
    char name[25];
    char password[12];
    int id;
} User;

typedef struct {
    char name[12];
    float gpa;
} Student;

int main() {

    // typedef => reserved keyword that gives an existing type a nickname

    my_user user1 = "Mehmed";

    User user2 = {"Mehmed", "1234", 1};
    User user3 = {"", "", 2};

    Student student1 = {"Mehmed", 3.5f};
    Student student2 = {"test", 2.5f};

    Student students[] = {student1, student2};

    for (int i = 0; i < sizeof(students) / sizeof(Student); i++) {
        printf("Student %d: %s, %.2f\n", i, students[i].name, students[i].gpa);
    }

    return EXIT_SUCCESS;
}
