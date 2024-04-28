#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20 // 30 characters + null terminator
#define DATE_LENGTH 10   // 10 characters (YYYY-MM-DD) + null terminator
#define REGISTRATION_LENGTH 6// 6 characters + null terminator
#define MAX_STUDENTS 100 // maximum number of students in an array

struct Student {
    char name[MAX_NAME_LENGTH];
    char dob[DATE_LENGTH];
    char registration[REGISTRATION_LENGTH];
    char program_code[4];
    float tuition;

};


void createStudent(struct Student *students, int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    struct Student newStudent;

    printf("Enter student name (no spaces) :  ");
    scanf("%20s", newStudent.name);
    printf("Enter date of birth (YYYY-MM-DD):  ");
    scanf("%12s", newStudent.dob);

    printf("Enter registration number :  ");
    scanf("%6s", newStudent.registration);

    printf("Enter program code :  ");
    scanf("%4s", newStudent.program_code);

    printf("Enter annual tuition:  ");
    scanf("%f", &newStudent.tuition);

    students[*numStudents] = newStudent;
    (*numStudents)++;
}











void readStudent(struct Student *students, int numStudents) {

    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Student Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Date of Birth: %s\n", students[i].dob);
        printf("Registration Number: %s\n", students[i].registration);
        printf("Program Code: %s\n", students[i].program_code);
        printf("Annual Tuition: %.2f\n", students[i].tuition);
        printf("\n");
    }
}






void updateStudent(struct Student *students, int numStudents) {

    if (numStudents == 0) {
        printf("No students to update.\n");
        return;
    }

    int studentIndex;
    printf("Enter the index of the student you want to update (1 to %d): ", numStudents);
    scanf("%d", &studentIndex);

    if (studentIndex < 1 || studentIndex > numStudents) {
        printf("Invalid student index.\n");
        return;
    }

    struct Student *studentToUpdate = &students[studentIndex - 1];

    printf("Update student details:\n");
    printf("Enter student name (up to 50 characters): ");
    scanf("%50s", studentToUpdate->name);

    printf("Enter date of birth (YYYY-MM-DD): ");
    scanf("%10s", studentToUpdate->dob);

    printf("Enter registration number (6 digits padded with zeros): ");
    scanf("%6s", studentToUpdate->registration);

    printf("Enter program code (up to 4 characters): ");
    scanf("%4s", studentToUpdate->program_code);

    printf("Enter annual tuition: ");
    scanf("%f", &studentToUpdate->tuition);

    printf("Student details updated successfully.\n");

}






void deleteStudent(struct Student *students, int *numStudents) {

    if (*numStudents == 0) {
        printf("No students to delete.\n");
        return;
    }

    int studentIndex;
    printf("Enter the index of the student you want to delete (1 to %d): ", *numStudents);
    scanf("%d", &studentIndex);

    if (studentIndex < 1 || studentIndex > *numStudents) {
        printf("Invalid student index.\n");
        return;
    }


    for (int i = studentIndex - 1; i < *numStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    (*numStudents)--; // Decrement the number of students

    printf("Student deleted successfully.\n");

}




void searchByRegistration(struct Student *students, int numStudents) {
    char regNum[REGISTRATION_LENGTH];
    int found = 0;

    if (numStudents == 0) {
        printf("No students to search.\n");
        return;
    }

    printf("Enter registration number to search: ");
    scanf("%s", regNum);

    for (int i = 1; i < numStudents; i++) {
        if (strcmp(students[i].registration, regNum) == 0) {
            printf("Student found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Date of Birth: %s\n", students[i].dob);
            printf("Registration Number: %s\n", students[i].registration);
            printf("Program Code: %s\n", students[i].program_code);
            printf("Annual Tuition: %.2f\n", students[i].tuition);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with registration number %s not found.\n", regNum);

    }
}



// Comparison function for sorting by student name
int compareByName(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    return strcmp(studentA->name, studentB->name);
}

// Comparison function for sorting by student tuition
int compareByTuition(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    if (studentA->tuition < studentB->tuition) return -1;
    if (studentA->tuition > studentB->tuition) return 1;
    return 0;
}

// Function to print the list of students
void printStudents(struct Student *students, int numStudents, int sortBy) {
    printf("Sorted List of Students by ");
    if (sortBy == 1) {
        printf("Name:\n");
        for (int i = 0; i < numStudents; i++) {
            printf("%s\n", students[i].name);
        }
    } else if (sortBy == 2) {
        printf("Tuition:\n");
        for (int i = 0; i < numStudents; i++) {
            printf("%.2f\n", students[i].tuition);
        }
    }
    printf("\n");
}

// Function to sort students based on user choice
void sortStudents(struct Student *students, int numStudents) {
    int mainChoice, sortChoice;

    printf("\nSort by:\n");
    printf("1. Name\n");
    printf("2. Tuition\n");
    printf("Enter your choice: ");
    scanf("%d", &mainChoice);

    switch(mainChoice) {
        case 1:
            qsort(students, numStudents, sizeof(struct Student), compareByName);
            printf("Students sorted by name.\n");
            printStudents(students, numStudents, 1); // Print the sorted list by name
            break;
        case 2:
            qsort(students, numStudents, sizeof(struct Student), compareByTuition);
            printf("Students sorted by tuition.\n");
            printStudents(students, numStudents, 2); // Print the sorted list by tuition
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}






// Function to export records to a CSV file
void exportRecords(struct Student *students, int numStudents) {

    if (numStudents == 0) {
        printf("No students to export to the file.\n");
        return;
    }


    FILE *file = fopen("students.csv", "a"); // Open the file in append mode to avoid overwriting existing records

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s,%s,%s,%s,%.2f\n", students[i].name, students[i].dob, students[i].registration, students[i].program_code, students[i].tuition);
    }

    fclose(file);
    printf("Records exported to students.csv successfully!\n");
}










int main() {
    struct Student students[100]; //  maximum of 100 students
    int numStudents = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create Student\n");
        printf("2. Read Student\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Search student by registration number\n");
        printf("6. Sort Students\n");
        printf("7. Export records\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createStudent(students, &numStudents);
                break;
            case 2:
                readStudent(students, numStudents);
                break;
            case 3:
                updateStudent(students, numStudents);
                break;
            case 4:
                deleteStudent(students, &numStudents);
                break;
            case 5:
                searchByRegistration(students, numStudents);
                break;
            case 6:
                sortStudents(students, numStudents);
                break;
            case 7:
                exportRecords(students, numStudents);
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);

    return 0;
}














