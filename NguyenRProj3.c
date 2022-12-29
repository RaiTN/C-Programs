// Raiden Nguyen
// Project 3
// Start Date:  10/16/22
// Due Date:    10/22/22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20
#define UPPER_LIMIT 20
#define LOWER_LIMIT 12
#define DATA_UPPER_LIMIT 90
#define DATA_LOWER_LIMIT 10

//Functions
void ArrayElements(int array[], int size);
void FindMinMax(int array[], int size);
void FindAverage(int array[], int size);
void SortArray(int array[], int size);
void PrintArray(int array[], int size);
void FindMedian(int array[], int size);

int main()
{
    //Random seed generator
    srand(time(NULL));

    //Declaration for array and random size limit
    int array[ARRAY_SIZE];
    int sizeLimit = (rand() % (UPPER_LIMIT - LOWER_LIMIT +1) + LOWER_LIMIT);

    //Call function to print array elements
    ArrayElements(array[ARRAY_SIZE], sizeLimit);

    //Call function to find the minimum and maximum number of array elements
    FindMinMax(array[ARRAY_SIZE], sizeLimit);

    //Call function to find the average within the element
    FindAverage(array[ARRAY_SIZE], sizeLimit);

    //Call function to sort elements within array
    SortArray(array[ARRAY_SIZE], sizeLimit);

    //Call function to print array with sorted elements
    PrintArray(array[ARRAY_SIZE], sizeLimit);

    //Call function to find the median of elements
    FindMedian(array[ARRAY_SIZE], sizeLimit);

    return 0;
}

//Function to fill array with random elements
void ArrayElements(int array[], int size)
{
    //Declaring i for loop use
    int i;

    //Display message to user
    printf("The array size is: %d\n\n", size);
    printf("Array Elements:\n");

    //Loop for seeding array with elements
    for(i = 0; i < size; i++)
    {
        //Inserting random element between lower and upper limit into array
        array[i] = (rand() % (DATA_UPPER_LIMIT - DATA_LOWER_LIMIT + 1) + DATA_LOWER_LIMIT);

        //Display array
        printf("%d ", array[i]);
    }


}

//Function to find min and max number in array elements
void FindMinMax(int array[], int size)
{
    //Declaring i for loop, min and max for lowest and highest element
    int i, min, max;

    //Setting min and max to position 0
    min = max = array[0];

    //Loop through array for calculation
    for(i = 0; i < size; i++)
    {
        //Set min as current element if condition met
        if (min > array[i])
        {
            min = array[i];
        }

        //Set max as current element if condition met
        if (max < array[i])
        {
            max = array[i];
        }
    }

    //Display min and max element within array
    printf("\n\nMaximum = %d, ", max);
    printf("Minimum = %d\n\n", min);
}

//Function to find the average number within array elements
void FindAverage(int array[], int size)
{
    //Declaring i for loop, avg to hold average of all elements, total for sum of all elements
    int i, avg, total;

    //Loop through array
    for(i = 0; i < size; i++)
    {
        //Adding element into total
        total += array[i];
    }

    //Calculate average after total obtained
    avg = total / size;

    //Display the average of all elements
    printf("Average = %d\n\n", avg);
}

//Function to sort the element within the array
void SortArray(int array[], int size)
{
    //Declaration for temp element placement, i and loop for loop conditions
    int temp, i, loop;

    //Loop set to true until condition changes
    while(loop > 0)
    {
        //Loop through array elements until end
        for(i = 0; i < size - 1; i++)
        {
            //Condition to swap elements
            if(array[i] > array[i+1])
            {
                temp = array[i];        //Swap array element into temp holder
                array[i] = array[i+1];  //Swap next element with current element
                array[i+1] = temp;      //Swap next element with temp holder
            }
        }

        //Condition to exit loop
        loop--;
    }
}

//Function to print array after sorting
void PrintArray(int array[], int size)
{
    //Declaring i for loop
    int i;

    //Display message
    printf("Sorted Array:\n");

    //Loop through array
    for(i = 0; i < size; i++)
    {
        //Display current element each loop
        printf("%d ", array[i]);
    }
    //Spacing for decoration
    printf("\n\n");
}

//Function to find the median within the array
void FindMedian(int array[], int size)
{
    //Declaring med for median, mid for middle of array, remainder for odd/even calculation
    int med, mid, remainder;

    //Calculation to find middle element of array
    mid = size/2;

    //Calculation to determine odd or even
    remainder = size % 2;

    //Condition to run if number is even
    if(remainder == 0)
    {
        //Calculation to add both middle element then divide 2 for median
        med = (array[mid] + array[mid-1]) / 2;
    }

    //Condition to run if number is odd
    if(remainder == 1)
    {
        //Median is middle element of array when odd
        med = array[mid];
    }

    //Display result
    printf("Median = %d\n", med);
}
