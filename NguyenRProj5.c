// Raiden Nguyen
// Project 5
// Start Date: 11/4/22
// Due Date: 11/5/22

#include <stdio.h>
#include <stdlib.h>

//Function Prototype
void FirstToss(die, die2, diceSum, point);
void KeepRolling(die, die2, diceSum, point);

int main()
{
    //Title
    printf("Raiden Nguyen - Project 5: Craps\n\n");

    //Seed Generator
    srand(time(NULL));

    //Initialization
    int die = rand() % 6 + 1, die2 = rand() % 6 + 1;
    int diceSum, point, count = 1;

    //Calculations
    diceSum = die + die2;
    point = diceSum;

    //Calling functions
    FirstToss(die, die2, diceSum, point);
    KeepRolling(die, die2, diceSum, point);

    return 0;
}

//Function Definitions

//Function to determine first toss outcome
void FirstToss(die, die2, diceSum, point)
{
    //Display outcome
    printf("Player rolled %d + %d = %d\n\n", die, die2, diceSum);

    //Switch case to determine outcome of multiple cases
    switch(point)
    {
        case 7:
        case 11: printf("Player wins!\n");
                exit(0);

        case 2:
        case 3:
        case 12: printf("Player loses!\n");
                exit(0);
    }

    //Display message if switch case not met
    printf("Game Point: %d\n\n", point);
    printf("Keep rolling!\n\n");
}

//Function to loop dice roll
void KeepRolling(die, die2, diceSum, point)
{
    //Loop to keep rolling if sum is not 7
    while (diceSum != 7)
    {
        //Dice roll generator
        die = rand() % 6 + 1, die2 = rand() % 6 + 1;

        //Calculating sum
        diceSum = die + die2;

        //Display outcome
        printf("Player rolled %d + %d = %d\n", die, die2, diceSum);

        //Win condition
        if (point == diceSum)
        {
            printf("\nPlayer wins!\n");
            exit(0);
        }

        //Continue loop otherwise
        else
        {
            continue;
        }
    }

    //Display lose message if player roll 7
    printf("\nPlayer loses!\n");
}
