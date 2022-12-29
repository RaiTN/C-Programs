//Raiden Nguyen
//Project 2
//10/7/22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_LIMIT 41
#define LOWER_LIMIT 21

void printDiamond()
{
    //Sample code for random number generator
    int sampleSize;
    
    srand(time(NULL));
    sampleSize = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
    
    if (sampleSize % 2 == 0)
    {
        sampleSize++;
    }
    
    printf("Number of lines: %d \n", sampleSize);
    
    
    //Initializing variables for usage
    int row, column;
    char c = '=';
    
    //Loop for rows of top portion
    for (row = 1; row < sampleSize; row++)
    {
        //Loop for columns in the row
        for (column = 1; column < (sampleSize*2) - 1; column++)
        {
            //Conditions to print
            if (column >= sampleSize-(row-1) && column <= sampleSize+(row-1))
            {
                printf("R");
            }
            else
            {
                printf(" ");
            }
        }
        //New line after each loop
        printf("\n");
    }
    
    //Loop to add separation between top and bottom
    for (row = 1; row <= (sampleSize*2)-1; row++)
    {
        putchar(c);
    }
    
    printf("\n");
    
    //Loop for rows of bottom portion, inverse of top
    for (row = sampleSize-1; row > 0; row--)
    {
        //Loop for columns within rows
        for (column = (sampleSize*2)-1; column > 1; column--)
        {
            //Conditions to print
            if (column >= sampleSize-(row-1) && column <= sampleSize+(row-1))
            {
                printf("N");
            }
            else
            {
                printf(" ");
            }
        }
        
        printf("\n");
    }
}

int main()
{
    printDiamond();
    
    return 0;
}