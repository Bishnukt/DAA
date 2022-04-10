/*
Name- Bishnu Kant Thakur
Program- Write a program to subtract matrix b from matrix a recursively.
*/

#include <stdio.h>
#include <stdlib.h>

int r, c;
int **mat1, **mat2, **mat3;
void mat_sub(int, int);
int **mem_alloc(int, int);
void input(int **, int, int);
void display(int **, int, int);

int main()
{
    int i, j;
    printf("Enter no. of rows in Matrix A & B : ");
    scanf("%d", &r);
    printf("Enter no. of columns in Matrix A & B : ");
    scanf("%d", &c);

    mat1 = mem_alloc(r, c);
    mat2 = mem_alloc(r, c);
    mat3 = mem_alloc(r, c);

    printf("Enter %d elements in Matrix A: ", r * c);
    input(mat1, r, c);
    printf("Enter %d elements in Matrix B: ", r * c);
    input(mat2, r, c);

    printf("Matrix A: \n");
    display(mat1, r, c);
    printf("\nMatrix B:\n");
    display(mat2, r, c);

    mat_sub(r - 1, c - 1);
    free(mat1);
    free(mat2);
    printf("\nMatrix A - Matrix B: \n");
    display(mat3, r, c);
}

void mat_sub(int r1, int c1)
{
    if (r1 >= 0)
    {
        if (c1 >= 0)
        {
            mat3[r1][c1] = mat1[r1][c1] - mat2[r1][c1];
            c1--;
            mat_sub(r1, c1);
        }
        mat_sub(r1 - 1, c - 1);
    }
    return;
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
