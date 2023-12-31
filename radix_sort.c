// Time complexity --> O(n)
// Number of passes = Number of digits of maximum element in array

#include <stdio.h>
#include <limits.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get the largest element from an array
int Maximum(int array[], int n)
{
    int max = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place)
{
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((array[i] / place) % 10) > max)
        {
            max = array[i];
        }
    }
    int count[max + 1];

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;

    } // Calculate count of elements
    for (int i = 0; i < size; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];

    } // Place the elements in sorted order

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

// Main function to implement radix sort
void radixsort(int array[], int size)
{
    // Get maximum element
    int max = Maximum(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(array, size, place);
    }
}

int main()
{
    int arr[] = {23, 47, 73, 2, 79, 17, 11, 7, 29, 41, 35};
    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    radixsort(arr, size);
    printArray(arr, size);

    return 0;
}