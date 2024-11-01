#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char name[50];
    int health;
    int score;
    int experience;
};

struct student {
    int id;
    char *name;
    int credit_hours;
    double gpa;
    bool is_full_time;
    long double loan_outstanding;
};

void student_report(struct student *s) {
    // s->name => (*s).name
    printf("Student Name: %s\n", s->name);
    printf("Student ID: %d\n", s->id);
    printf("Credit Hours: %d\n", s->credit_hours);
    printf("GPA: %.2f\n", s->gpa);
    printf("Full Time: %s\n", s->is_full_time ? "Yes" : "No");
    printf("Loan Outstanding: %.2Lf\n", s->loan_outstanding);
}

int main() {
    // struct Player player1;
    // struct Player player2;
    //
    // strcpy(player1.name, "Mehmed");


    struct student test_student;
    test_student.name = "Test Student";
    test_student.id = 12345;
    test_student.credit_hours = 40;
    test_student.gpa = 4.0;
    test_student.is_full_time = true;
    test_student.loan_outstanding = 123456789.87;

    struct student student_better_init = {
        123456,
        "Test Student",
        40,
        4.0,
        true,
        123456789.87
    };

    struct student zero_student = {};


    student_report(&test_student);

    puts("+++++++++++");

    student_report(&student_better_init);

    puts("+++++++++++++++++++");

    student_report(&zero_student);

    return EXIT_SUCCESS;
}
