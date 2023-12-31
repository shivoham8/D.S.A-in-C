#include <stdio.h>

int main()
{
    int arr[10][10];
    int rows, columns;
    int counter = 0;

    printf("Enter number of rows \n");
    scanf("%d", &rows);

    printf("Enter number of columns \n");
    scanf("%d", &columns);

    printf("Enter co-efficients of matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter element arr[%d][%d] \n", i, j);
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0)
            {
                counter++;
            }
        }
    }

    if (counter > (rows * columns) / 2)
    {
        printf("The given matrix is sparse matrix \n");
    }

    else
    {
        printf("The given matrix is not sparse matrix \n");
    }

    printf("There are %d zeroes in matrix", counter);

    return 0;
}