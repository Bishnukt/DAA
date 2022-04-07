/*
Name- Bishnu Kant Thakur
Program- Write a program to multiply two matrices iteratively.
*/
#include <stdio.h>
#include <stdlib.h>

int **multiply(int **, int **);
int **mem_alloc(int, int);
void input(int **, int, int);
void display(int **, int, int);
int r1, r2, c1, c2;

int main()
{
    do
    {
        printf("**For multiplication, no. of columns of first matrix must be equal to the no. of rows of second matrix.**\n");
        printf("Enter the no. of rows & columns in first matrix: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter the  no. of rows & columns in the second matrix: ");
        scanf("%d %d", &r2, &c2);
    } while (c1 != r2);
    int **mat1, **mat2, **mat3;

    mat1 = mem_alloc(r1, c1);
    mat2 = mem_alloc(r2, c2);

    printf("Enter %d*%d elements in Matrix A: ", r1, c1);
    input(mat1, r1, c1);
    printf("Enter %d*%d elements in Matrix B: ", r2, c2);
    input(mat2, r2, c2);

    printf("Matrix A:\n");
    display(mat1, r1, c1);
    printf("\nMatrix B:\n");
    display(mat2, r2, c2);
    mat3 = multiply(mat1, mat2);
    free(mat1);
    free(mat2);
    printf("\nMatrix A  X  Matrix B:\n");
    display(mat3, r1, c2);
}

int **multiply(int **mat1, int **mat2)
{
    int **mat = mem_alloc(r1, c2);
    int i, j, k;
    for (k = 0; k < r1; k++)
        for (i = 0; i < c2; i++)
            for (j = 0; j < r2; j++)
                mat[k][i] += mat1[k][j] * mat2[j][i];
    return mat;
}
int **mem_alloc(int r, int c)
{
    int i;
    int **temp = (int **)calloc(r, sizeof(int *));
    for (i = 0; i < r; i++)
        temp[i] = (int *)calloc(c, sizeof(int));
    return temp;
}

void input(int **mat, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
}

void display(int **mat, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
