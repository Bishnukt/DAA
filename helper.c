#include"helper.h"
#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r, int c)
{
    int i;
    int **temp = (int **)calloc(r,sizeof(int *));
    for (i = 0; i < r; i++)
        temp[i] = (int *)calloc(c,sizeof(int));
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

void freeall(int **arr,int r)
{
	int i;
	for(i=0;i<r;i++)
		free(arr[i]);
	free(arr);
}
