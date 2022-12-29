// Raiden Nguyen
// Project 4
// Start Date:  10/21/22
// Due Date:    10/22/22

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Function Prototypes Assignment Part 1
double DivideNumber(double *a, double *b);
double MultiplyNumber(double *a, double *b);
double GetResult(double a, double b);

//Function Prototypes Assignment Part 2
#define SIZE 20
int Average(int total[], int size, double avg);

int main()
{
    //Assignment Part 1
    double a, b;

    printf("Assignment Part 1\n\n");

    //Prompt User
    printf("Pleases enter first number: ");
    scanf("%lf", &a);
    printf("Pleases enter second number: ");
    scanf("%lf", &b);

    //Call function for result
    GetResult(a, b);

    //Assignment Part 2
    int i, array[SIZE], total = 0, count;
    double avg;

    printf("Assignment Part 2\n\n");
    printf("Please enter 20 numbers.\n");

    //Loop for filling array
    for(i = 0; i < SIZE; i++)
    {
        printf("Number %d: ", i+1);
        scanf("%d", &array[i]);
    }

    //Loop to calculate total
    for(i = 0; i < SIZE; i++)
    {
        total += *(array + i);
    }

    //Calculating the average
    avg = total / SIZE;

    //Calculate count referencing function
    count = Average(&total, SIZE, avg);

    printf("\nNumber of elements above average: %d\n", count);

    return 0;
}

//Function Definitions Assignment Part 1
double DivideNumber(double *a, double *b)
{
    return *a / *b; //Grab value and divide
}

double MultiplyNumber(double *a, double *b)
{
    return *a * *b; //Grab value and multiply
}

double GetResult(double a, double b)
{
    double c, d;

    //Calculate c by function reference
    c = DivideNumber(&a, &b);
    printf("\nThe result of c is: %.2lf\n", c);

    //Calculate d by function reference
    d = MultiplyNumber(&a, &b);
    printf("The result of d is: %.2lf\n\n", d);
}

//Function Definitions Assignment Part 2
int Average(int total[], int size, double avg)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        if(total[i] > avg)
        {
            count++;
        }
    }

    return count;
}
