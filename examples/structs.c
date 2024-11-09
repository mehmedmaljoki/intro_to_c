#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
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

// not aligned; dont use without good reason
// it helps to reduce the size of the struct
#pragma pack(push, 1)
struct new_student {
    char *name;
    int id;
    char initials[3];
    double gpa;
    int credit_hours;
};
#pragma pack(pop)

struct good_alignment_student {
    char *name;
    double gpa;
    int id;
    int credit_hours;
    char initials[3];
};
#pragma pack(pop)

void student_report(struct student *s) {
    // s->name => (*s).name
    printf("Student Name: %s\n", s->name);
    printf("Student ID: %d\n", s->id);
    printf("Credit Hours: %d\n", s->credit_hours);
    printf("GPA: %.2f\n", s->gpa);
    printf("Full Time: %s\n", s->is_full_time ? "Yes" : "No");
    printf("Loan Outstanding: %.2Lf\n", s->loan_outstanding);
}

struct heap_student {
    char *name;
    char *initials;
    double gpa;
    int id;
    int credit_hrs;
};


struct heap_student make_student(char *name, int id, int num_initials) {
    return (struct heap_student){
        .name = name,
        .id = id,
        // allocate memory on heap bc we dont know the size of the initials
        // pls cast bc malloc returns void * and C has a weak type system
        // malloc returns memory address in dynamic memory where the memory you asked was allocated, but
        // if it was not able to allocate memory, it will return NULL (for example memory is full)
        .initials = (char *) malloc(num_initials * sizeof(char)),

        // calloc initializes the memory to 0
        // mostly you will not need it bc you would have to initialize the memory anyway
        // .initials = (char *) calloc(num_initials, sizeof(char)),

    };
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

    puts("++++++++++++++++++++++++++");

    printf("Size of new_student: %zu\n", sizeof(struct new_student));
    printf("offset of name: %zu\n", offsetof(struct new_student, name));
    printf("offset of id: %zu\n", offsetof(struct new_student, id));
    printf("offset of initials: %zu\n", offsetof(struct new_student, initials));
    printf("offset of gpa: %zu\n", offsetof(struct new_student, gpa));
    printf("offset of credit_hours: %zu\n", offsetof(struct new_student, credit_hours));

    puts("++++++++++++++++++++++++++");

    printf("Size of good_alignment_student: %zu\n", sizeof(struct good_alignment_student));
    printf("offset of name: %zu\n", offsetof(struct good_alignment_student, name));
    printf("offset of id: %zu\n", offsetof(struct good_alignment_student, id));
    printf("offset of initials: %zu\n", offsetof(struct good_alignment_student, initials));
    printf("offset of gpa: %zu\n", offsetof(struct good_alignment_student, gpa));
    printf("offset of credit_hours: %zu\n", offsetof(struct good_alignment_student, credit_hours));

    puts("*********************");

    // init a student on stack
    for (int i = 0; i < 5; i++) {
        struct heap_student student_on_heap = make_student("Heap Student", 12345, 2);
        student_on_heap.initials[0] = 'T';
        student_on_heap.initials[1] = 'S';
        student_on_heap.initials[2] = 0;

        printf("Initials: %s\n", student_on_heap.initials);
        assert(student_on_heap.initials != NULL);

        // another way to allocate memory is with realloc
        // realloc is used to change the size of the memory block that was previously allocated using malloc or calloc
        // if the memory block is not enough, it will allocate a new memory block, copy the data from the old memory block to the new memory block, and free the old memory block
        student_on_heap.initials = realloc(student_on_heap.initials, 4 * sizeof(char));
        assert(student_on_heap.initials != NULL);

        // free the memory allocated on heap
        free(student_on_heap.initials);
    }
    // student_on_heap.initials[0] = 'H';
    // student_on_heap.initials[1] = 'S';


    return EXIT_SUCCESS;
}
