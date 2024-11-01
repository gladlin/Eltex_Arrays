 /*
    j
 i  0 0 0 1 
    0 0 1 1
    0 1 1 1
    1 1 1 1

0 0 1
0 1 1
1 1 1 
 */
#include <stdio.h>
#include <stdlib.h>

int** setRectangle(int n)
{
    int** resultMatrix = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
    {
        resultMatrix[i] = malloc(sizeof(int) * n);
    }
    for(int i = 0; i < n;i++)
    {
        for(int j =0; j < n;j++)
        {
            if(n-1-i==j || j >= -i + n)
                resultMatrix[i][j] = 1;
            else
                resultMatrix[i][j] = 0;
        }
    }
    return resultMatrix;
}


void printMatrix(int** matrix, int n)
{
    for(int i = 0; i < n;i++)
    {
        for(int j =0; j < n;j++)
        {
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
        free(matrix[i]);
    }
    free(matrix);
}



int main()
{
    unsigned int n = 0;
    if(scanf("%u", &n) != 1 || n < 1)
    {
        printf("Enter valid positive integer");
        return -1;
    }
    int** matrix = setRectangle(n);
    printMatrix(matrix, n);

    return 0;
}