#include <stdio.h>

void mean(int arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    printf("The mean of array is %.2f \n", sum/n);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr)/sizeof(int);

    mean(arr, size);

    return 0;
}