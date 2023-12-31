#include <stdio.h>

int main()
{
    int arr_one[2][2];
    int arr_two[2][2];
    int mul[2][2];
    int transpose[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter first array element arr[%d][%d] \n", i, j);
            scanf("%d", &arr_one[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter second array element arr[%d][%d] \n", i, j);
            scanf("%d", &arr_two[i][j]);
        }
    }

    printf("\n");

    // Printing elements of both arrays
    printf("Elements of first array are: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr_one[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Elements of second array are: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr_two[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Performing addition
    printf("Sum of both arrays: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", (arr_one[i][j] + arr_two[i][j]));
        }
        printf("\n");
    }

    printf("\n");

    // Performing multiplication
    printf("Multiplication of both arrays: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                mul[i][j] += arr_one[i][k] * arr_two[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Transpose of first array
    printf("Transpose of first array is: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transpose[j][i] = arr_one[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Transpose of second array
    printf("Transpose of second array is: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transpose[j][i] = arr_two[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}