#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *file;

    file = fopen("students.dat", "ab");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *file;

    file = fopen("students.dat", "rb");

    if (file == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    while (fread(&s, sizeof(s), 1, file)) {
        printf("\nRoll Number: %d", s.rollNo);
        printf("\nName: %s", s.name);
        printf("\nMarks: %.2f\n", s.marks);
    }

    fclose(file);
}

void searchStudent() {
    struct Student s;
    FILE *file;
    int roll, found = 0;

    file = fopen("students.dat", "rb");

    if (file == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, file)) {
        if (s.rollNo == roll) {
            printf("\nStudent Found!");
            printf("\nRoll Number: %d", s.rollNo);
            printf("\nName: %s", s.name);
            printf("\nMarks: %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("\nStudent not found.\n");
    }
}

void updateStudent() {
    struct Student s;
    FILE *file;
    int roll, found = 0;

    file = fopen("students.dat", "rb+");

    if (file == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, file)) {
        if (s.rollNo == roll) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(file, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, file);

            found = 1;
            printf("Student updated successfully!\n");
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Student not found.\n");
    }
}

void deleteStudent() {
    struct Student s;
    FILE *file, *temp;
    int roll, found = 0;

    file = fopen("students.dat", "rb");

    if (file == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    if (temp == NULL) {
        fclose(file);
        printf("Unable to create temporary file.\n");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, file)) {
        if (s.rollNo == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        printf("Student deleted successfully!\n");
    } else {
        printf("Student not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}