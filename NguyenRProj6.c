// Raiden Nguyen
// Project 6
// Start Date:  11/28/22
// Due Date:    12/3/22

#include <stdio.h>
#include <stdlib.h>

#define ROW 12
#define COLUMN 9

// Function
void ParityBit(int row, int column, int array[][COLUMN]);
void PrintParityBit(int row, int column, int array[][COLUMN]);

int main()
{
    // Random seed generator
    srand(time(NULL));

    // Declaration
    int array[ROW][COLUMN];

    printf("Raiden Nguyen - Project 6: Parity Bit \n\n");
    printf("    Data Bit\t   Parity Bit\n");

    ParityBit(ROW, COLUMN, array);
    PrintParityBit(ROW, COLUMN, array);

    return 0;
}

void ParityBit(int row, int column, int array[][COLUMN])
{
    int count = 0;

    for (row = 0; row < ROW; row++)
    {
        for (column = 0; column <= COLUMN - 1; column++)
        {
            if (column == COLUMN - 1)
            {
                array[row][column] = count % 2;
                count = 0;
            }

            else
            {
                array[row][column] = rand() % 2;
                count += array[row][column];
            }
        }
    }
}

void PrintParityBit(int row, int column, int array[][COLUMN])
{
    row = 0;
    column = 0;

    while (row < ROW - 1)
    {
        if (column == COLUMN - 1)
        {
            printf("\t");
        }
        printf("%d%c", array[row][column], (column == COLUMN - 1) ? '\n' : ' ');
        (column == COLUMN - 1) ? row++, column = 0 : column++;
    }
}
