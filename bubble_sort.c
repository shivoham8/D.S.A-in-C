// Time complexity O(n^2)
// Number of comparisons 1 + 2 + ... + n-1
// Number of passes = size -1
// Is stable as the order is same as the order in input array
// By default it is not adaptive but we can make it. Time complexity O(n) for already sorted

#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // --> For number of pass
    {
        printf("Working on pass number %d \n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // --> For comparison in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int arr[], int n)
{
    int temp;
    int isSorted = 0; 
    // Matlab agar hume loop ke andar jaane ki zaroorat hi ni parh rahi agar ye already sorted hai

    for (int i = 0; i < n - 1; i++) // --> For number of pass
    {
        printf("Working on pass number %d \n", i + 1);
        isSorted = 1; // --> Har loop run karne se pehle se iski value 1 kar dege
        for (int j = 0; j < n - 1 - i; j++) // --> For comparison in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0; // --> Loop run hone par iski value 0
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {23, 47, 73, 2, 79, 17, 11, 7, 29, 41, 35};
    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    printf("\n");
    bubbleSort(arr, size);
    printf("\n");
    printArray(arr, size);
    printf("\n");
    bubbleSortAdaptive(arr, size);
    printf("\n");
    printArray(arr, size);

    return 0;
}