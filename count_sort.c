// Time complexity is O(m+n) or approximately O(n) because when the array of size n is very large m will be negligible
// Time complexity is least (linear) but at the cost of some extra space

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        return max;
    }
}

void countSort(int arr[], int n)
{
    int i, j;
    // Find the maximum element in array
    int max = maximum(arr, n);

    // Create the count array
    // Count of number of elements in main array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Inititalize the count elements to be zero
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array arr

    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }

        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {23, 47, 73, 2, 79, 17, 11, 7, 29, 41, 35};
    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    countSort(arr, size);
    printArray(arr, size);

    return 0;
}