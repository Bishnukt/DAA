/*
Name- Bishnu Kant Thakur
Program- Write a program to subtract matrix b from matrix a iteratively.
*/

#include <stdio.h>
#include <stdlib.h>

int r, c;
int **mat_sub(int **, int **);
int **mem_alloc(int, int);
void input(int **, int, int);
void display(int **, int, int);

int main()
{
    int **mat1, **mat2, **mat3, i, j;

    printf("Enter no. of rows in Matrix A & B ");
    scanf("%d", &r);
    printf("Enter no. of columns in Matrix A & B: ");
    scanf("%d", &c);
    mat1 = mem_alloc(r, c);
    mat2 = mem_alloc(r, c);

    printf("Enter %d elements in Matrix A: ", r * c);
    input(mat1, r, c);
    printf("Enter %d elements in Matrix B: ", r * c);
    input(mat2, r, c);

    printf("Matrix A: \n");
    display(mat1, r, c);
    printf("\nMatrix B:\n");
    display(mat2, r, c);

    mat3 = mat_sub(mat1, mat2);
    free(mat1);
    free(mat2);
    printf("\nMatrix A - Matrix B: \n");
    display(mat3, r, c);
}

int **mat_sub(int **mat1, int **mat2)
{
    int i = 0, j = 0;
    int **mat = mem_alloc(r, c);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            mat[i][j] = mat1[i][j] - mat2[i][j];

    return mat;
}

int **mem_alloc(int r, int c)
{
    int i;
    int **temp = (int **)malloc(sizeof(int *) * r);
    for (i = 0; i < r; i++)
        temp[i] = (int *)malloc(sizeof(int) * c);
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