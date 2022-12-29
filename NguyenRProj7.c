// Raiden Nguyen
// Project 7 - Struct Assignment
// Start Date:  12/8/2022
// Due Date:    12/10/2022

#include <stdio.h>
#include <stdlib.h>

// Struct
typedef struct
{
    int studentNumber;
    float quiz1;
    float quiz2;
    float midterm;
    float finalExam;
    float average;
    char grade;
} StudentRecord;

// Function Prototypes
void Input(StudentRecord * student);
void ComputeGrade(StudentRecord * student);
void Output(const StudentRecord * student);
int Repeat();


int main()
{
    // Initializing
    StudentRecord * student;
    int again = 1;

    // Display name and project
    printf("Raiden Nguyen - Project 7: Struct");

    // Loop to repeat functions
    while(again > 0)
    {
        // Calling function
        Input(&student);
        ComputeGrade(&student);
        Output(&student);
        again = Repeat();
    }

    return 0;
}

// Function Definitions

// Function to collect input for student
void Input(StudentRecord * student)
{
    // Prompt user for member input
    printf("\n\nPlease enter the following: \n\n");
    printf("Student Number: ");
    scanf("%d", &student->studentNumber);
    printf("Quiz 1: ");
    scanf("%f", &student->quiz1);
    printf("Quiz 2: ");
    scanf("%f", &student->quiz2);
    printf("Midterm: ");
    scanf("%f", &student->midterm);
    printf("Final Exam: ");
    scanf("%f", &student->finalExam);
}

// Function to calculate total and letter grade
void ComputeGrade(StudentRecord * student)
{
    float quiz, mid, fin, total;

    // Calculations of each group by percentage
    quiz = ((student->quiz1 + student->quiz2)/20) * 25;
    mid = (student->midterm/100) * 25;
    fin = (student->finalExam/100) * 50;
    student->average = total = quiz + mid + fin;            // Setting member with total calculation

    // Conditions for letter grades
    if(total >= 90)
    {
        student->grade = 'A';
    }
    else if(total < 90 && total >= 80)
    {
        student->grade = 'B';
    }
    else if(total < 80 && total >= 70)
    {
        student->grade = 'C';
    }
    else if(total < 70 && total >= 60)
    {
        student->grade = 'D';
    }
    else
    {
        student->grade = 'F';
    }

}

// Function to display output
void Output(const StudentRecord * student)
{
    // Display member outputs of struct
    printf("\nRecord for Student Number: %d\n\n", student->studentNumber);
    printf("Quiz 1 Grade: %.2f\n", student->quiz1);
    printf("Quiz 2 Grade: %.2f\n", student->quiz2);
    printf("Midterm Grade: %.2f\n", student->midterm);
    printf("Final Exam Grade: %.2f\n", student->finalExam);
    printf("Grade Average: %.2f\n", student->average);
    printf("Letter Grade: %c\n", student->grade);
}

// Function for user input to repeat
int Repeat()
{
    int repeat = 0;
    char again;

    do
    {
        printf("\nGrade another student? (Y or N): ");
        scanf(" %c", &again);

        switch(again)
        {
                case 'Y':
                        repeat = 1;
                        break;
                case 'N':
                        repeat = 0;
                        break;
                default:
                        printf("\nIncorrect input, try again!\n");
                        again = 1;
        }
    } while (again == 1);


    return repeat;
}
