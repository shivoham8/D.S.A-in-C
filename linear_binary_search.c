#include <stdio.h>

int linearSearch(int arr[], int size, int element)
// --> Works for both sorted and unsorted arrays
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
// --> Works only for sorted arrays
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] > element)
        {
            high = mid - 1;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 7, 11, 14, 23, 29, 35, 41, 53, 59, 69, 73, 79, 85};
    int size = sizeof(arr) / sizeof(int);
    int element = 41;

    printf("The element %d was found at index %d", element, binarySearch(arr, size, element));

    return 0;
}