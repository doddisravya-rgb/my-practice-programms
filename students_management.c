#include <stdio.h>

// Structure definition
struct Student {
    int rollNo;
    char name[30];
    float marks[5];
    float total;
    float average;
};

// Function to calculate total
float calculateSum(float marks[], int n) {
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }

    return sum;
}

// Function to calculate average
float calculateAverage(float total, int n) {
    return total / n;
}

// Function to display grade
void displayGrade(float avg) {
    if (avg >= 90)
        printf("Grade: A\n");
    else if (avg >= 80)
        printf("Grade: B\n");
    else if (avg >= 70)
        printf("Grade: C\n");
    else if (avg >= 60)
        printf("Grade: D\n");
    else if (avg >= 50)
        printf("Grade: E\n");
    else
        printf("Grade: F\n");
}

int main() {
    struct Student s;

    // Getting student details
    printf("Enter roll number: ");
    scanf("%d", &s.rollNo);

    printf("Enter student name: ");
    scanf(" %29[^\n]", s.name);

    // Getting five subject marks
    printf("Enter marks for 5 subjects:\n");

    for (int i = 0; i < 5; i++) {
        scanf("%f", &s.marks[i]);
    }

    // Calculations
    s.total = calculateSum(s.marks, 5);
    s.average = calculateAverage(s.total, 5);

    // Displaying student report
    printf("\n----- STUDENT REPORT -----\n");
    printf("Roll Number: %d\n", s.rollNo);
    printf("Student Name: %s\n", s.name);
    printf("Total Marks: %.2f\n", s.total);
    printf("Average Marks: %.2f\n", s.average);

    displayGrade(s.average);

    return 0;
}