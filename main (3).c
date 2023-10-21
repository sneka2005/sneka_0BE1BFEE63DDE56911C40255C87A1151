#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    char roll_number[20];
    float cgpa;
};

void sort_students(struct Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (students[j].cgpa < students[j + 1].cgpa) {
                // Swap students[j] and students[j + 1]
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Example list of students
    struct Student students[] = {
        {"Alice", "101", 3.8},
        {"Bob", "102", 3.5},
        {"Charlie", "103", 3.9},
        {"David", "104", 3.2},
        {"Eva", "105", 3.7}
    };

    int size = sizeof(students) / sizeof(students[0]);

    printf("Original list of students:\n");
    for (int i = 0; i < size; ++i) {
        printf("Name: %s, Roll Number: %s, CGPA: %.2f\n", students[i].name, students[i].roll_number, students[i].cgpa);
    }

    sort_students(students, size);

    printf("\nSorted list of students based on CGPA (descending order):\n");
    for (int i = 0; i < size; ++i) {
        printf("Name: %s, Roll Number: %s, CGPA: %.2f\n", students[i].name, students[i].roll_number, students[i].cgpa);
    }

    return 0;
}
