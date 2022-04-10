#include"dhelper.h"

double **mem_alloc(int r,int c)
{
	double **temp=(double **)calloc(r,sizeof(double *));
	for(int i=0;i<r;i++)
		temp[i]=(double *)calloc(c,sizeof(double));
	return temp;
}

void input(double **mat,int r,int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%lf",&mat[i][j]);
}

void display(double **mat,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			printf("%.2lf ",mat[i][j]);
		printf("\n");
	}
}

void freeall(double **mat,int r)
{
	for(int i=0;i<r;i++)
		free(mat[i]);
	free(mat);
}

